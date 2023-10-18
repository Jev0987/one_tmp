#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <condition_variable>
#include <sstream>
#include <chrono>  // 睡眠用
#include <functional>
using namespace std;
unsigned int MaxN;

namespace Method{
mutex alock;
condition_variable t;
// 信号量类， down信号量--， up信号量++
class Semaphore{
private:
    unsigned int m;
public:
    Semaphore(unsigned int x) : m(x) {}  
    Semaphore() {}
    Semaphore(const Semaphore& sa) {m = sa.m;}  // 拷贝构造函数
    ~Semaphore(){}

    void down(){
        unique_lock<mutex> locker(alock);
        while(m == 0){
            cout << "(thread id=" << this_thread::get_id() << "is wait)" << endl;
            t.wait(locker);
        }
        m--;
    }

    void up(){
        alock.lock();
        m++;
        t.notify_all();
        alock.unlock();
    }

    bool operator == (const Semaphore &t){
        return m == t.m;
    }
    bool operator != (const Semaphore &t){
        return m != t.m;
    }
    bool operator == (const unsigned int &t){
        return m == t;
    }
    bool operator != (const unsigned int &t){
        return m == t;
    }
    void operator = (const Semaphore &t){
        m = t.m;
    }
    void operator = (const unsigned int t){
        m = t;
    }
    Semaphore operator +(const Semaphore &t){
        return Semaphore(m + t.m);
    }
    Semaphore operator + (const unsigned int &t){
        return Semaphore(m + t);
    }
};

int Int(thread::id id){
    stringstream ss;
    ss << id;
    return std::stoi(ss.str());
}
Semaphore mutexs = 4;
Semaphore chopsticks[10000];

auto functionC = []()->void{
    while(true){
        int id = Int(this_thread::get_id()) -2;
        if(id % 2){
            // 奇数
            chopsticks[(id + 1) % MaxN].down();  
            chopsticks[id].down();
            alock.lock();  // 保证同时只有一个线程在屏幕里输出
            cout << "Philosopher" << id << " are eating (thread id =" << this_thread::get_id() << " is run)" << endl;
            alock.unlock();  // 释放锁
            chrono::milliseconds s(1000);  //睡眠1s
            this_thread::sleep_for(s);

            chopsticks[(id + 1) % MaxN].up();
            chopsticks[id].up();
        }else{
            // 偶数
            chopsticks[id].down();
            chopsticks[(id + 1) % MaxN].down();  
            alock.lock();  // 保证同时只有一个线程在屏幕里输出
            cout << "Philosopher" << id << " are eating (thread id =" << this_thread::get_id() << " is run)" << endl;
            alock.unlock();  // 释放锁
            chrono::milliseconds s(1000);  //睡眠1s
            this_thread::sleep_for(s);

            chopsticks[id].up();
            chopsticks[(id + 1) % MaxN].up();
        }
        alock.lock();
        cout << "Philosopher" << id << " are thinking (thread id =" << this_thread::get_id() << " is run)" << endl;
        alock.unlock();
    }
};
};

using namespace Method;

class Philosopher{
private:
    vector<function<void()> > fns;
    Philosopher(){}
    Philosopher(const Philosopher& t){fns = t.fns;}
    ~Philosopher(){}

public:
    static Philosopher *instance;
    static Philosopher *of(){
        if(instance) return instance;
        return (instance = new Philosopher());
    }
    void add(initializer_list<function<void()> > fs){
        for(auto iter = fs.begin(); iter != fs.end(); iter++){
            fns.push_back(*iter);
        }
    }
 
    void add(function<void()> t){
        fns.push_back(t);
    }
    
    function<void()> get(size_t i){
        return fns[i];
    }
};

Philosopher *Philosopher::instance = 0;
int main(){
    Philosopher::of()->add({functionC});

    cout << "input Philosopher number: "<< endl;
    cin >> MaxN;
    
    vector<thread> phils;

    for(size_t i = 0; i < MaxN; i++){
        chopsticks[i] = 1;
    }
    for(size_t i = 0; i < MaxN; i++){
        phils.push_back(thread(Philosopher::of()->get(0)));
    }

    for(auto iter = phils.begin(); iter != phils.end(); iter++){
        iter->join();
    }
    return 0;
}
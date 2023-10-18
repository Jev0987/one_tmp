//
// Created by Jev on 2022/11/7.
//
//请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//
//若队列为空，pop_front 和 max_value 需要返回 -1

//输入:
//["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
//[[],[1],[2],[],[],[]]
//输出:[null,null,null,2,1,2]
//
#include "queue"
#include "deque"
using namespace std;
class MaxQueue {
    queue<int> que;
    deque<int> deq;
public:
    MaxQueue() { }
    int max_value() {
        return deq.empty() ? -1 : deq.front();
    }
    void push_back(int value) {
        que.push(value);
        //关键，双端队列中，小于当前值的全部弹出，放入双端队列中
        while(!deq.empty() && deq.back() < value)
            deq.pop_back();
        deq.push_back(value);
    }
    int pop_front() {
        if(que.empty()) return -1;
        int val = que.front();
        //如果与deq头元素相同，deq弹出
        if(val == deq.front())
            deq.pop_front();
        que.pop();
        return val;
    }
};
/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */


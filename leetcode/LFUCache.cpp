//
// Created by Jev on 2023/8/26.
//
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;
class LFUCache {
private:
    struct Node{
        int cnt;  // 使用频次
        int time;  // 最近一次使用时间
        int key;  // 键
        int value;  // 值
        bool operator < (const Node &b) const {
            return cnt == b.cnt ? time < b.time : cnt < b.cnt;
        };
        Node(int c, int t, int k, int v) : cnt(c), time(t), key(k), value(v) {};
    };
    int time;
    int m_cap;
    unordered_map<int, Node> kv;
    set<Node> S;
public:
    LFUCache(int capacity) {
        m_cap = capacity;
        time = 0;
        S.clear();
        kv.clear();
    }

    int get(int key) {
        if(m_cap == 0) return -1;
        auto it = kv.find(key);
        if(it == kv.end()) return -1;  // 未在缓存中出现

        // 在缓存中出现了
        Node n = it->second;
        S.erase(n);  // 频率时间二叉排序树删除该元素
        n.time = ++time;  // 时间为当前时间
        n.cnt += 1;  // 使用频次增加

        S.insert(n);  // 放入二叉排序树中
        it->second = n;
        return n.value;

    }

    void put(int key, int value) {
        if(m_cap == 0) return;
        auto it = kv.find(key);
        if(it == kv.end()){
            // 没找到，分两种情况：空间充足和空间不足
            if(m_cap == kv.size()){
                // 空间不足，需要删除
                kv.erase(S.begin()->key);
                S.erase(S.begin());
            }
            Node n = Node(1, ++time, key, value);
            kv.emplace(key, n);
            S.insert(n);
        }else{
            // 找到了，修改它的value值和出现频次和操作时间即可
            Node n = it->second;
            S.erase(n);

            n.cnt += 1;
            n.time = ++time;
            n.value = value;

            S.insert(n);
            it->second = n;
        }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

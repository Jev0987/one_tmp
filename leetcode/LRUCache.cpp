//
// Created by Jev on 2023/4/4.
//
#include "unordered_map"
#include "queue"
#include "vector"
#include "iostream"
using namespace std;

class LRUCache {
private:
    // 使用链表存放值，插入和删除方便，头节点为最近使用的元素
    struct ListNode{
        int key;
        int value;
        ListNode *pre;
        ListNode *next;
        ListNode(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr){};
    };
    // 使用哈希表存放 键值对，快速存取
    unordered_map<int, ListNode*> kv;
    int m_cap;  // 缓存容量
    int size;  // 元素个数
    void deleteNode(ListNode *n){
        // 删除节点
        n->pre->next = n->next;
        n->next->pre = n->pre;
    }
    void add2head(ListNode *n){
        // 增加节点
        n->pre = head;
        n->next = head->next;
        head->next->pre = n;
        head->next = n;
    }
    void move2head(ListNode *n){
        // 将其从原链表中删除
        deleteNode(n);
        // 节点移动到最前端
        add2head(n);
    }
    ListNode* deleteTailNode(){
        // 删除链表尾部节点（最久没使用的）
        ListNode *dn = tail->pre;
        deleteNode(dn);
        size--;
        return dn;
    }
    ListNode *head = new ListNode(-1, -1);
    ListNode *tail = new ListNode (-1, -1);
public:
    LRUCache(int capacity) {
        m_cap = capacity;
        size = 0;
        head->next = tail; head->pre = tail;
        tail->pre = head; tail->next = head;
    }

    int get(int key) {
        if(m_cap == 0) return -1;
        auto it = kv.find(key);
        if(it == kv.end()) return -1;

        // 把该节点移动到链表最前端
        move2head(it->second);

        return it->second->value;
    }

    void put(int key, int value) {
        if(m_cap == 0) return;
        auto it = kv.find(key);
        if(it == kv.end()){
            // 没有找到，检查空间是否足够存放
            if(m_cap == size){
                // 空间不足，需要删除元素
                ListNode *dn = deleteTailNode();
                kv.erase(dn->key);
                delete dn;
            }
            // 插入元素
            ListNode *new_n = new ListNode(key, value);
            kv.emplace(key, new_n);
            add2head(new_n);
            size++;
        }else{
            // 找到了，更换值，并把它移动到链表头部
            it->second->value = value;
            move2head(it->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache* lruCache = new LRUCache(2);
    lruCache->put(2, 1);
    lruCache->put(1, 1);
    lruCache->put(2, 3);
    lruCache->put(4, 1);
    cout << lruCache->get(1) << endl;
    cout << lruCache->get(2) << endl;
}


struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

//class LRUCache {
//private:
//    unordered_map<int, DLinkedNode*> cache;
//    DLinkedNode* head;
//    DLinkedNode* tail;
//    int size;
//    int capacity;
//
//public:
//    LRUCache(int _capacity): capacity(_capacity), size(0) {
//        // 使用伪头部和伪尾部节点
//        head = new DLinkedNode();
//        tail = new DLinkedNode();
//        head->next = tail;
//        tail->prev = head;
//    }
//
//    int get(int key) {
//        if (!cache.count(key)) {
//            return -1;
//        }
//        // 如果 key 存在，先通过哈希表定位，再移到头部
//        DLinkedNode* node = cache[key];
//        moveToHead(node);
//        return node->value;
//    }
//
//    void put(int key, int value) {
//        if (!cache.count(key)) {
//            // 如果 key 不存在，创建一个新的节点
//            DLinkedNode* node = new DLinkedNode(key, value);
//            // 添加进哈希表
//            cache[key] = node;
//            // 添加至双向链表的头部
//            addToHead(node);
//            ++size;
//            if (size > capacity) {
//                // 如果超出容量，删除双向链表的尾部节点
//                DLinkedNode* removed = removeTail();
//                // 删除哈希表中对应的项
//                cache.erase(removed->key);
//                // 防止内存泄漏
//                delete removed;
//                --size;
//            }
//        }
//        else {
//            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
//            DLinkedNode* node = cache[key];
//            node->value = value;
//            moveToHead(node);
//        }
//    }
//
//    void addToHead(DLinkedNode* node) {
//        node->prev = head;
//        node->next = head->next;
//        head->next->prev = node;
//        head->next = node;
//    }
//
//    void removeNode(DLinkedNode* node) {
//        node->prev->next = node->next;
//        node->next->prev = node->prev;
//    }
//
//    void moveToHead(DLinkedNode* node) {
//        removeNode(node);
//        addToHead(node);
//    }
//
//    DLinkedNode* removeTail() {
//        DLinkedNode* node = tail->prev;
//        removeNode(node);
//        return node;
//    }
//};

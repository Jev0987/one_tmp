//
// Created by Jev on 2023/8/24.
//
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <pthread.h>

using namespace std;
#ifndef LEETCODES_BLOCK_QUEUE_H
#define LEETCODES_BLOCK_QUEUE_H

template <class T>
class block_queue{
public:
    // 构造函数，初始化阻塞队列
    block_queue(int max_num){
        // 阻塞队列中使用循环数组存放
        if(max_num <= 0){
            exit(-1);
        }
        front = -1;
        back = -1;

    }
    ~block_queue();
private:
    pthread_cond_t m_cond;
    pthread_mutex_t m_mutex;
    int m_max_num;
    int m_size;
    int front;
    int back;
    T *m_array;
};

#endif //LEETCODES_BLOCK_QUEUE_H

//
// Created by Jev on 2023/10/7.
//
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

//剑指 Offer 65. 不用加减乘除做加法
//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
//输入: a = 1, b = 1
//输出: 2

class Solution {
public:
    int add(int a, int b) {
        while(!b == 0){
            int c = (unsigned int)(a & b) << 1; // 进位
            a ^= b; // 无进位的运算
            b = c; // 将进位赋值给b
        }
        return a;
    }
};

int main(){
    Solution s;
    cout<< s.add(1, 2) << endl;
}
//
// Created by Jev on 2022/10/20.
//
//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
// 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
//
//输入: 12258
//输出: 5
//解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

//写出来之后：斐波那契
#include "string"
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);//转换为字符串
        int a = 1, b = 1, len = s.size();//动态规划
        for(int i = 2; i <= len; i++) {
            string tmp = s.substr(i - 2, 2);//psziZ位置，字串字符个数
            int c = tmp.compare("10") >= 0 && tmp.compare("25") <= 0 ? a + b : a;
            b = a;
            a = c;
        }
        return a;
    }
};

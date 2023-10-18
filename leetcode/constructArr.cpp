//
// Created by Jev on 2022/11/2.
//
//剑指 Offer 66. 构建乘积数组
//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中B[i] 的值是数组 A 中除了下标 i 以外的元素的积,
// 即B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

//输入: [1,2,3,4,5]
//输出: [120,60,40,30,24]
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len == 0) return {};
        vector<int> b(len);
        b[0] = 1;
        int tmp = 1;  // 存放从右往左遍历时的积
        for(int i = 1; i < len; i++) {
            b[i] = b[i - 1] * a[i - 1];  // 从左往右构建前n-1个元素的积, 初始第一个值为1
        }
        for(int i = len - 2; i >= 0; i--) {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }
        return b;
    }
};
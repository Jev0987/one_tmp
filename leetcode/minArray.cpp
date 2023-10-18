//
// Created by Jev on 2022/10/15.
//
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//
//给你一个可能存在重复元素值的数组numbers，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。
// 例如，数组[3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。
//注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。


//输入：numbers = [3,4,5,1,2]
//输出：1
#include "vector"
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 二分查找
        int min;
        int i = 0, j = numbers.size() - 1;
        while(i < j){
            int m = (i + j) >> 1;
            if(numbers[m] > numbers[j]) i = m + 1;
            else if(numbers[m] < numbers[j]) j = m;
            else j--;
        }
        return numbers[i];
    }
};
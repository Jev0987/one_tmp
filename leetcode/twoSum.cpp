//
// Created by Jev on 2022/10/22.
//
//剑指 Offer 57. 和为 s 的两个数字
//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

//输入：nums = [2,7,11,15], target = 9
//输出：[2,7] 或者 [7,2]
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int l = i + 1, r = numbers.size() - 1;
            while(l <= r){
                int mid = (r - l) / 2 + l;
                if(numbers[i] + numbers[mid] == target){
                    return {i, mid};
                }else if(target - numbers[i] > numbers[mid]){
                    l = mid + 1;
                }else if(target - numbers[i] < numbers[mid]){
                    r = mid - 1;
                }
            }
        }
        return {0, 1};
    }
};
//
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> ans;
//        int i = 0, j = nums.size() - 1;
//        while (i < j) {
//            // 双指针问题，判断当前做差后，结果与nums[i]做比较，比它大则 i++， 比它小则i--。
//            if(target - nums[j] < nums[i]) j--;
//            else if(target - nums[j] > nums[i]) i++;
//            else break;
//        }
//        ans.push_back(nums[i]);
//        ans.push_back(nums[j]);
//        return ans;
//    }
//};

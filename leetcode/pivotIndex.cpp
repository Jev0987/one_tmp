//
// Created by Jev on 2023/4/22.
//
#include "string"
#include "vector"
#include "stack"
#include "queue"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = -1;

        int sum = 0;
        for(auto n : nums){
            sum += n;
        }
        int mid = 0;
        int left_sum, right_sum;
        while(mid < nums.size()){
            int left = mid - 1, right = mid + 1;
            if (left != -1){
                left_sum += nums[left];
            }else left_sum = 0;

            if(right != nums.size()){
                right_sum = sum - left_sum - nums[mid];
            }else right_sum = 0;

            if(left_sum == right_sum){
                ans = mid;
                break;
            }
            mid++;
        }
        return ans;
    }
};


class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        // vector 求和
        // accumulate(first, second, init)   first,second 开始和结束位置，init求和初始值
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> test = {1,7,3,6,5,6};
    cout << s.pivotIndex(test);
}
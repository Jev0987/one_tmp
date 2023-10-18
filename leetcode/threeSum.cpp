//
// Created by Jev on 2023/4/18.
//
#include "string"
#include "vector"
#include "stack"
#include "queue"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // 数组不是有序的
        sort(nums.begin(), nums.end());
        // 三个数字相加
        for (int i = 0; i < nums.size(); ++i) {
            // 记录尾巴数字，根据前两个，移动尾巴
            int j = nums.size() - 1;
            // 如果是重复的元素就往后继续
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for (int k = i + 1; k < j; ++k) {
                // 如果元素相同则往后继续
                if(k > i + 1 && nums[k] == nums[k - 1]) continue;
                // 如果尾巴还在第2个数字后面，且0减掉头两个数字后值还比比尾巴数字小，则尾巴往前找小的数字
                while(k < j && -(nums[i] + nums[k]) < nums[j]) --j;
                // 两个指针相遇：找不到了，结束吧
                if(k == j) break;
                // 找到了，记录下来
                if(nums[i] + nums[k] + nums[j] == 0){
                    ans.push_back({nums[i], nums[k], nums[j]});
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> test = {-1, -1, 0, 1};
    for(auto list : s.threeSum(test)){
        for(auto e : list){
            cout << e << ' ';
        }
        cout << endl;
    }
}
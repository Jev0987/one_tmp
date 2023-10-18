//
// Created by Jev on 2023/6/5.
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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // lambda匿名函数
        // [捕获外部变量列表](形参列表){
        //      函数体
        // }
        auto cmp = [&nums1, &nums2] (const pair<int, int> &a, const pair<int, int> &b){
            // (子节点，父节点)
            // 小根堆，父节点比根节点小
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < min(n1, k); ++i){
            pq.emplace(i, 0);
        }
        while(k-- && !pq.empty()){
            auto [x, y] = pq.top();
            pq.pop();
            vector<int> tmp = {nums1[x], nums2[y]};
            ans.emplace_back(tmp);
            if(y + 1 < n2) pq.emplace(x, y + 1);
        }
        return ans;

    }
};

int main(){
    Solution s;
    vector<int> t1 = {1,7,11};
    vector<int> t2 = {2,4,6};
    int k = 3;

    vector<vector<int>> ans = s.kSmallestPairs(t1, t2, k);


}
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
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int tmp = i;
            while(tmp){
                if(tmp & 1) count++;
                tmp >>= 1;  // 右移
            }
            ans.emplace_back(count);
        }
        return ans;
    }
};


int main(){
    Solution s;
    for (auto ans : s.countBits(2)){
        cout << ans << ' ';
    }
}
//
// Created by Jev on 2023/4/25.
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
    int permutation(string S) {
        int n = S.size();
        sort(S.begin(), S.end());
        vector<bool> used(n, false);
        string track;
        backtrack(S, used, track);
        return ans;

    }
private:
    int ans = 0;
    void backtrack(string s, vector<bool> used, string track){
        if(s.size() == track.size()){
            ans += 1;
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            // 剪枝1：当前元素和前一个元素相同，且同一层元素不重复
            if(i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;
            // 剪枝2：自身使用过了
            if(used[i]) continue;

            // 使用了s[i]
            used[i] = true;
            track.push_back(s[i]);

            backtrack(s, used, track);

            // 撤销操作
            track.pop_back();
            used[i] = false;
        }
    }
};

int main(){
    Solution s;
    string test = "ABA";
    int ans;
    ans = s.permutation(test);
    cout << ans;

}


//
// Created by Jev on 2023/4/23.
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
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> dic(26);

        for (auto s: s1) {
            --dic[s - 'a'];
        }

        int left = 0;
        for (int right = 0; right < n; ++right) {
            ++dic[s2[right] - 'a'];

            while (dic[s2[right] - 'a'] > 0) {
                --dic[s2[left] - 'a'];
                left++;
            }
            if(right - left + 1 == m) return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    string test1 = "aaabbbccc";
    string test2 = "aaccbbbbaaabbccc";
    cout << s.checkInclusion(test1, test2);
}
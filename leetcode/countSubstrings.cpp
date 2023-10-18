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
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // 回文串长度为奇数的情况，回文中心是一个数
            ans += countPalindrome(s, i, i);
            // 回文串长度为偶数，回文中心是两个数字
            ans += countPalindrome(s, i, i + 1);
        }
//        for (int i = 0; i < 2 * n - 1; ++i) {
//            int l = i / 2, r = i / 2 + i % 2;
//            while (l >= 0 && r < n && s[l] == s[r]) {
//                l--;
//                r++;
//                ans++;
//            }
//        }
        return ans;
    }
private:
    int countPalindrome(string s, int l, int r){
        int res = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    string test = "abacaca";
    cout << s.countSubstrings(test);
}
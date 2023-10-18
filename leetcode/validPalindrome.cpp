//
// Created by Jev on 2023/4/24.
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
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            char l = s[left];
            char r = s[right];
            // 找到不同的以后，跳过这个位置，继续判断，如果剩下的不是回文串，则返回false
            if(l != r){
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
private:
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    Solution s;
    string test = "eccer";
    cout << s.validPalindrome(test);
}

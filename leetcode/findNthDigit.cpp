//
// Created by Jev on 2023/4/2.
//

#include "vector"
#include "string"
#include "iostream"
using namespace std;
//class Solution {
//public:
//    int findNthDigit(int n) {
//        if(n < 10) return n;
//        vector<int> t;
//        for (int i = 10; i <= n; ++i) {
//            string s = to_string(i);
//            for (char c : s) {
//                t.push_back((int)c - 48);
//                if (t.size() == n - 9) break;
//            }
//        }
//        return t[n - 10];
//    }
//};

class Solution {
public:
    int findNthDigit(int n) {
        int start = 1, digit = 1;
        long long count = 9;
        while (n > count) {
            n -= count;
            start *= 10;
            digit += 1;
            count = (long long)9 * start * digit;
        }
        int num = start + (n - 1) / digit;
        int res = int(to_string(num)[(n - 1) % digit]) - '0';
        return res;
    }
};

int main(){
    Solution s;
    int ans = s.findNthDigit(11);
    cout << ans << endl;
}
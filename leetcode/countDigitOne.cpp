//
// Created by Jev on 2023/4/16.
//
#include "string"
#include "vector"
#include "stack"
#include "queue"
#include "iostream"
#include "math.h"

using namespace std;

//给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        int tmp = n;
        int digit_sum = 0;
        while(tmp){
            tmp /= 10;
            digit_sum++;
        }
        int high_num; // 高位数字
        int low_num;  // 低位数字
        int cur;      // 当前位数字
        for (int i = 1; i <= digit_sum; ++i) {
            high_num = n / pow(10, i);
            low_num = n % int(pow(10, i - 1));
            cur = int(n / pow(10, i - 1)) % 10;
            int digit = pow(10, i - 1);
            if (cur == 0) res += high_num * digit;
            else if (cur == 1) res += high_num * digit + low_num + 1;
            else res += high_num * digit + digit;
        }
        return res;
    }
};

int main(){
    int n = 12;
    Solution s;
    int ans = s.countDigitOne(n);
    cout << ans << endl;
}
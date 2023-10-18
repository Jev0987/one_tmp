//
// Created by Jev on 2022/10/25.
//
//剑指 Offer 45. 把数组排成最小的数
//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//输入: [10,2]
//输出: "102"

//输入: [3,30,34,5,9]
//输出: "3033459"

#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    void swap(vector<string> &s, int i, int j){
        string tmp;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    void Qsort(vector<string> &s, int l, int r){
        if(l >= r) return;
        int i = l - 1, j = r + 1;
        int mid = (l + r) >> 1;
        string key = s[mid];
        while(i < j){
            while(s[++i] + key < key + s[i]);
            while(s[--j] + key > key + s[j]);
            if(i < j) swap(s, i, j);
        }
        // swap(s, i, mid);
        Qsort(s, l, i - 1);
        Qsort(s, j + 1, r);
    }
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> s_tmp;
        for(int i = 0; i < n; i++){
            s_tmp.emplace_back(to_string(nums[i]));
        }
        Qsort(s_tmp, 0, s_tmp.size() - 1);
        string ans;
        for(string s : s_tmp){
            ans.append(s);
        }
        return ans;
    }
};
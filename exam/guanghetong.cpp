//
// Created by Jev on 2023/10/10.
//
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;//vector<int> ans;
//void func(int start, int n){
//    if(start == n) return;
//
//    if(start == 0) {
//        ans.push_back(0);
//    }else if(start == 1){
//        ans.push_back(1);
//    }else{
//        ans.push_back(ans[start - 1] + ans[start - 2]);
//    }
//
//    func(start + 1, n);
//}
//
//void func2(int n){
//    if(n == 1) ans.push_back(0);
//    else if(n == 2) {
//        func2(n - 1);
//        ans.push_back(1);
//    }
//    else{
//        func2(n - 1);
//        int size = ans.size();
//        ans.push_back(ans[size - 1] + ans[size - 2]);
//    }
//}
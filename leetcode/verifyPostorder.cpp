//
// Created by Jev on 2022/10/30.
//

//剑指 Offer 33. 二叉搜索树的后序遍历序列
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
// 假设输入的数组的任意两个数字都互不相同。
//     5
//    / \
//   2   6
//  / \
// 1   3

//输入: [1,6,3,2,5]
//输出: false

//输入: [1,3,2,6,5]
//输出: true
#include "vector"
using namespace std;
class Solution {
public:
    //二叉搜索树，必须判断是否左子树根节点，右子树大于跟节点
    bool verifyPostorder(vector<int>& postorder) {
        int root = postorder.back();
        int left = 0, right = INT16_MAX;
        for (int i = 0; i < postorder.size() - 1; ++i) {
            if(postorder[i] < root) left = i;
            else right = i;
            if(left > right) return false;
        }
        return true;
    }

};

//class Solution {
//public:
//    bool verifyPostorder(vector<int>& postorder) {
//        return recur(postorder, 0, postorder.size() - 1);
//    }
//private:
//    bool recur(vector<int>& postorder, int i, int j) {
//        if(i >= j) return true;
//        int p = i;
//        while(postorder[p] < postorder[j]) p++;
//        int m = p;
//        while(postorder[p] > postorder[j]) p++;
//        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
//    }
//};
//

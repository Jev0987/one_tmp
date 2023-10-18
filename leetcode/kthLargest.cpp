//
// Created by Jev on 2022/10/24.
//
//剑指 Offer 54. 二叉搜索树的第 k 大节点
//给定一棵二叉搜索树，请找出其中第 k 大的节点的值。
//输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 4

//输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 4

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        recur(root, k);
        return res;
    }
private:
    int res = 0;
    int signal = 0;
    void recur(TreeNode* root, int k){
        if(root == nullptr) return;

        recur(root->right, k);
        signal += 1;
        if(k == signal) res = root->val;
        recur(root->left, k);
    }
};
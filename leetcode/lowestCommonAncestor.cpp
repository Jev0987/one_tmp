//
// Created by Jev on 2022/10/28.
//
//剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
// 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include "queue"
using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val > root->val && q->val > root->val) root = root->right; //如果两个节点都比它大，则往右子树判断
            else if(p->val < root->val && q->val < root->val) root = root->left;//两个都小了，看左子树
            else break;//一大一小，刚好是公共祖先
        }
        return root;
    }
};
//
// Created by Jev on 2022/10/29.
//
//
// Created by Jev on 2022/10/28.
//
//二叉树的最近公共祖先

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root; // 越过叶子节点返回空，如果找到p ，q 则返回
        TreeNode *left = lowestCommonAncestor(root->left, p, q); // 左子树
        TreeNode *right = lowestCommonAncestor(root->right, p, q); // 右子树
        if(left == nullptr) return right; // 根据当前遍历的节点，若左子树找不到p ，q 则返回右子树遍历返回值
        if(right == nullptr) return left; //同上
        return root; // 返回
    }
};

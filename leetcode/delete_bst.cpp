//
// Created by Jev on 2023/8/31.
//
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};

TreeNode* get_min(TreeNode *root){
    while(root->left != nullptr) return root->left;
    return root;
}

TreeNode* searchBST(TreeNode *root, int key){
    if(!root) return nullptr;

    if(root->val == key) return root;

    if(root->val > key) return searchBST(root->left, key);

    if(root->val < key) return searchBST(root->right, key);

    return root;
}

TreeNode* addBST(TreeNode *root, int key){
    if(!root){
        TreeNode *n = new TreeNode(key);
        return n;
    }
    if(root->val < key) root->right = addBST(root->right, key);
    if(root->val > key) root->left = addBST(root->left, key);

    return root;
}

TreeNode* delete_node(TreeNode *root, int key){
    if(!root) return nullptr;

    if(root->val == key){
        // 删除节点
        if(root->left == nullptr) return root->right;
        if(root->right == nullptr) return root->left;

        // 左右都有子树，将右子树的最小值作为根节点返回
        TreeNode *min_n = get_min(root->right);

        root->right = delete_node(root->right, min_n->val);

        min_n->left = root->left;
        min_n->right = root->right;
        root = min_n;
    }else if(root->val > key){
        // 寻找左子树
        root->left = delete_node(root->left, key);
    }else if(root->val < key){
        // 寻找右子树
        root->right = delete_node(root->right, key);
    }
    return root;
}
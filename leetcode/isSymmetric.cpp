//
// Created by Jev on 2022/10/17.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //    1
//   / \
 //  2   2
// / \ / \
 //3  4 4  3
 //true

 //   1
//   / \
 //  2   2
//   \   \
 //   3    3
 //false
#include "vector"
#include "queue"
#include "stack"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || recur(root->left, root->right);
    }
private:
    bool recur(TreeNode* L, TreeNode* R) {
        if(L == nullptr && R == nullptr) return true;
        if(L == nullptr || R == nullptr || L->val != R->val) return false;
        return recur(L->left, R->right) && recur(L->right, R->left);
    }
};

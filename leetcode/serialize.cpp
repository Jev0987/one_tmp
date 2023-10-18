//
// Created by Jev on 2022/11/8.
//
// 请实现两个函数，分别用来序列化和反序列化二叉树。
//
// 你需要设计一个算法来实现二叉树的序列化与反序列化。
// 这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
//
// 提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅LeetCode 序列化二叉树的格式。
// 你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <string>
#include <queue>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void pre_serialize(TreeNode *root, string &ans){
        if(root == nullptr){
            ans += "None,";
            return;
        }
        string str = to_string(root->val) + ",";
        ans += str;
        pre_serialize(root->left, ans);
        pre_serialize(root->right, ans);
    }
    string serialize(TreeNode* root) {
        // 先序遍历, 得到结果
        string ans;
        pre_serialize(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    deque<string> sp(string data, char dec){
        deque<string> strs;
        int start = 0;
        int pos = 0;
        while(start < data.size()){

            while(pos < data.size() && data[pos] != dec) pos++;

            strs.emplace_back(data.substr(start, pos - start));

            pos++;
            start = pos;

        }
        cout << "split" << endl;
        return strs;
    }

    TreeNode* pre_build(deque<string> &strs){
        cout << "pre_build" << endl;
        if(strs.empty()) return nullptr;
        if(strs.front() == "None"){
            strs.pop_front();
            return nullptr;
        }
        int val = stoi(strs.front());
        cout << val << endl;
        strs.pop_front();
        TreeNode *root = new TreeNode(val);

        root->left = pre_build(strs);
        root->right = pre_build(strs);
        return root;
    }

    TreeNode* deserialize(string data) {
        // 反推先序遍历的序列
        deque<string> strs = sp(data, ',');

        return pre_build(strs);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

//
// Created by Jev on 2022/11/3.
//

//剑指 Offer 29. 顺时针打印矩阵

//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]

//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]

#include "vector"
using namespace std;

//答案利用了四条边界，不断往里收缩
//例如，如果是一行读完，则边界往下收缩。。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> res;
        while(true)
        {
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]); // left to right
            if (++t > b) break;
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]); // top to bottom
            if (l > --r) break;
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]); // right to left
            if (t > --b) break;
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]); // bottom to top
            if (++l > r) break;
        }
        return res;
    }
};
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        vector<int> ans;
//        if (matrix.empty()) return ans;
//        int i = 0, j = 0;
//        int n = matrix.size(), m = matrix[0].size();
//        int all = n * m;
//        int start = matrix[i][j];
//        ans.push_back(start);
//        matrix[i][j] = INT16_MAX;
//        int count = 1;
//        while(count < all) {
//            while(j + 1 < matrix[0].size() && matrix[i][j + 1] < INT16_MAX) {
//                ans.push_back(matrix[i][++j]);
//                matrix[i][j] = INT16_MAX;
//                count++;
//            }
//            while(i + 1 < matrix.size() && matrix[i + 1][j] < INT16_MAX) {
//                ans.push_back(matrix[++i][j]);
//                matrix[i][j] = INT16_MAX;
//                count++;
//            }
//            while(j - 1 >= 0 && matrix[i][j - 1]<INT16_MAX) {
//                ans.push_back(matrix[i][--j]);
//                matrix[i][j] = INT16_MAX;
//                count++;
//            }
//            while(i - 1 >= 0 && matrix[i - 1][j] < INT16_MAX) {
//                ans.push_back(matrix[--i][j]);
//                matrix[i][j] = INT16_MAX;
//                count++;
//            }
//
//        }
//        return ans;
//    }
//};
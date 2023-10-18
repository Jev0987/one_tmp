//
// Created by Jev on 2023/4/30.
//
#include "string"
#include "vector"
#include "stack"
#include "queue"
#include "iostream"
#include "unordered_map"

using namespace std;

int main(){
    int N, m;
    cin >> N >> m;  // 总钱数和物件数(<60)
    N /= 10;
    vector<vector<int>> prices(61, vector<int>(3, 0));  // 存放主件，附件价格，默认为0
    vector<vector<int>> pricesMutilplyPriority(61, vector<int>(3, 0)); //存放重要程度
    // 输入数据
    for (int i = 1; i <= m; ++i) {
        int v, p, q;
        cin >> v >> p >> q;
        v /= 10;
        p *= v;
        if(q == 0){
            // 为主件
            prices[i][0] = v;
            pricesMutilplyPriority[i][0] = p;
        }else {
            // 为附件
            if(prices[q][1] == 0){
                prices[q][1] = v;
                pricesMutilplyPriority[q][1] = p;
            }else{
                prices[q][2] = v;
                pricesMutilplyPriority[q][2] = p;
            }
        }
    }

    // 分组背包
    // dp数组记录 购买i个物品，剩余j元 所获得的最大满意度
    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for(int j = 1; j < N + 1; ++j){
            int a = prices[i][0]; int b = pricesMutilplyPriority[i][0];
            int c = prices[i][1]; int d = pricesMutilplyPriority[i][1];
            int e = prices[i][2]; int f = pricesMutilplyPriority[i][2];

            // 最大满意度
            // 剩余j元时，选择 i 件商品的最大满意度。钱够-》增加满意度，钱不够-》返回选择i-1件商品是的最大满意度
            dp[i][j] = j >= a ? max(dp[i - 1][j - a] + b, dp[i - 1][j]) : dp[i - 1][j];

            // 这里是dp[i][j] 的原因：在主件的基础上，选择了附件
            dp[i][j] = j >= (a + c) ? max(dp[i - 1][j - a - c] + b + d, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (a + e) ? max(dp[i - 1][j - a - e] + b + f, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (a + c + e) ? max(dp[i - 1][j - a - c - e] + b + d + f, dp[i][j]) : dp[i][j];
        }
    }
    cout << dp[m][N] * 10 << endl;
}
// 64 位输出请用 printf("%lld")


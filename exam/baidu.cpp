//
// Created by Jev on 2023/10/11.
//
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;
// 幸运数字 ： 6位， 前3位和后三位相同即可

// 给定数字n, m, k
// 数组[a1, a2, .. ,am]
// 判断n中有多少个区间【l，r】 刚好有k个数组元素落在区间中

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(i + (k - 1) >= m) break;

        int left = i == 0 ? a[i] : a[i] - a[i - 1];
        int right = (i + (k - 1)) == m - 1 ? n - a[i + (k - 1)] + 1 : (i + k) < m ? a[i + k] - a[i + (k - 1)]: 1;

        ans += left * right;
    }
    cout << ans << endl;
}


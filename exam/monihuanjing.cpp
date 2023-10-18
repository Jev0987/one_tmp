//
// Created by Jev on 2023/8/13.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;



int main(){
    int n, w;
    while(cin >> n >> w){
        vector<pair<int, int>> car_time(n, {0, 0});
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            car_time[i].first = tmp;  // 车测试所需时间
            car_time[i].second = 0;  // 可以出发的时间点
        }

        int t = 0;  // 时间点
        int cc = 0;  // 次数
        while(true){
            if(cc >= w){
                // 次数达到，退出循环
                t--;  // 上个时间点已经完成，所以时间要减1
                break;
            }
            for(auto &v : car_time){
                if(t == v.second){
                    // 当前时间点可以出发
                    v.second = t + v.first;  // 重新定义开始时间
                    if(t != 0) cc++;  // 测试次数+1
                }
            }
            t++;
        }

        cout << t << endl;
    }
}
//
//int ans;
//int cc;
//
//void dfs(map<int, int> mp, int w){
//    if(w <= 0){
////        cout << cc << endl;
//        ans = min(ans, cc);
//        return;
//    }
//
//    for(auto it : mp){
//        w -= it.second;
//        cc += it.first;
//
//        dfs(mp, w);
//
//        w += it.second;
//        cc -= it.first;
//    }
//
//}
//
//
//int main(){
//    // 最少需要多少时间能完成测试任务
//    // 3辆车,5趟, 每辆车用时 [1,2,3]
//    // 1 1 1  = 3趟
//    // 2 2    = 1趟
//    // 3   3  = 1趟
//    // 合计    = 5趟
//
//    int N, W;
//    while(cin >> N >> W){
//        vector<int> need_time;
//        map<int, int> time_o;
//        ans = INT_MAX;
//        cc = 0;
//        for(int i = 0; i < N; i++){
//            int t;
//            cin >> t;
//            need_time.emplace_back(t);
//            time_o[t]++;
//        }
//        sort(need_time.begin(),need_time.end());
//
//        map<int, int> mp;
//
//        for(int i = N - 1; i >= 0; i--){
//            int one_time = need_time[i];
//            int c = 0;
//            for(int j = 0; j < need_time.size(); j++){
//                c += one_time / need_time[j];
//            }
//            mp[one_time] = c;
//        }
//        for(auto it : mp){
//            cout << "key: " << it.first << " value : " << it.second << endl;
//        }
//        dfs(mp, W);
//
//        cout << ans << endl;
//    }
//}
//
// Created by Jev on 2023/10/8.
//
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

int cityMaxRoads(int n , vector<vector<int>> roads){
    int ans = 0;
    unordered_map<int, vector<int>> mp;  // 邻接表
    for(auto road : roads){
        int from = road[0];
        int end = road[1];
        mp[from].push_back(end);
        mp[end].push_back(from);
    }

    for(auto [_, value] : mp){
        ans = max(ans, int(value.size()));
    }

    return ans;
}
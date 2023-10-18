//
// Created by Jev on 2023/8/30.
//
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
    int n;

    while(cin >> n){
        unordered_map<string, int> mp;
        cin.get();
        for(int i = 0; i < n; i++){

            string key;

            for(int j = 0; j < 8; j++){
                string tmp;
                getline(cin, tmp);
                key += tmp;
            }
            mp[key]++;
            cout << mp[key] << endl;
        }

    }

    return 0;
}
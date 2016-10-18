//
//  main.cpp
//  poj 3342
//
//  Created by apple on 16/9/23.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
vector<int> tree[210];
int dp[210][110];
void init(int n){
    for (int i = 0; i<n; i++) {
        tree[i].clear();
    }
}
void dfs(int u){
    dp[u][1] = 1;
    dp[u][0] = 0;
    for (int i = 0; i<tree[u].size(); i++) {
        int v = tree[u][i];
        dfs(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][1], dp[v][0]);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    while (cin>>n&&n) {
        init(n);
        memset(dp, 0, sizeof(dp));
        map<string, int>mm;
        int cnt = 0;
        char a[110];
        char b[110];
        scanf("%s",a);
        mm[a] = cnt++;
        for (int i = 1; i<n; i++) {
            scanf("%s",a);
            scanf("%s",b);
            if (mm.find(a)==mm.end()) {
                mm[a] = cnt++;
            }
            if (mm.find(b)==mm.end()) {
                mm[b] = cnt++;
            }
            //cout<<mm[b]<<' '<<mm[a]<<endl;
            tree[mm[b]].push_back(mm[a]);
        }
        dfs(0);int flag = 0;
        for (int i = 0; i<cnt; i++) {
            if (dp[i][0]>dp[i][1]) {
                for (int j = 0; j<tree[i].size(); j++) {
                    if (dp[tree[i][j]][0] == dp[tree[i][j]][1]) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag) {
                break;
            }
        }
        cout<<max(dp[0][1], dp[0][0])<<' ';
        if (dp[0][1] == dp[0][0]||flag) {
            cout<<"No"<<endl;
        }
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}

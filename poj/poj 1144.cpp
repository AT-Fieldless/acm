//
//  main.cpp
//  poj 1144
//
//  Created by apple on 16/9/7.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
vector<int>G[1100];
int iscut[1100];
int low[1100];
int pre[1100];
int vis[1100];
int dfs_clock;
void init(int n){
    for (int i = 1; i<=n; i++) {
        G[i].clear();
    }
}
//pre要初始化为0
int dfs(int u,int fa){          //u在dfs树中的父结点是fa
    //cout<<u<<' ';
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;              //子结点数目
    for (int i = 0; i<G[u].size(); i++) {
        int v = G[u][i];
        if (!pre[v]) {          //没有访问过v
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu,lowv);        //用后代的low函数更新u的low函数
            if (lowv>=pre[u]) {
                iscut[u] = true;
            }
        }
        else if (pre[v]<pre[u]&&v!=fa){
            lowu = min(lowu, pre[v]);
        }
    }
    if (fa<0&&child == 1) {
        iscut[u] = 0;
    }
    low[u] = lowu;
    return lowu;
}
int main(){
    int n;
    while (cin>>n&&n) {
        int cnt = 0;
        //int
        init(n);
        int k;
        cin>>k;
        while (k) {
            int t;
            char ch;
            cin>>t;
            scanf("%c",&ch);
            G[k].push_back(t);
            G[t].push_back(k);
            while (ch == ' ') {
                cin>>t;
                scanf("%c",&ch);
                G[k].push_back(t);
                G[t].push_back(k);
            }
            cin>>k;
        }
        memset(iscut, -1, sizeof(iscut));
        memset(pre, 0, sizeof(pre));
        dfs_clock = 0;
        dfs(1, -1);
        for (int i = 1; i<=n; i++) {
            if (iscut[i] == 1) {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}

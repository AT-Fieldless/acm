//
//  main.cpp
//  poj 3713
//
//  Created by apple on 16/9/7.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int>G[1100];
int iscut[1100];
int low[1100];
int pre[1100];
int dfs_clock;
int cut;
void init(int n){
    for (int i = 0; i<n; i++) {
        G[i].clear();
    }
}
int dfs(int u,int fa){
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = 0; i<G[u].size(); i++) {
        int v = G[u][i];
        if (v == cut) {
            continue;
        }
        if (!pre[v]) {
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu,lowv);
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
int main(int argc, const char * argv[]) {
    int n,m;
    while (cin>>n>>m&&(n||m)) {
        if (n == 1) {
            cout<<"YES"<<endl;
            continue;
        }
        init(n);
        for (int i = 0; i<m; i++) {
            int a,b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int flag = 0;
        for (int i = 0; i<n; i++) {
            cut = i;
            dfs_clock = 0;
            memset(pre, 0, sizeof(pre));
            memset(iscut, 0, sizeof(iscut));
            if (i == 0) {
                dfs(1, -1);
            }
            else
                dfs(0, -1);
            for (int j = 0; j<n; j++) {
                if (j == cut) {
                    continue;
                }
                if (iscut[j] == 1||pre[j] == 0) {
                    //cout<<i<<' '<<pre[j]<<' ';
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (!flag) {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

//
//  main.cpp
//  poj 3586
//
//  Created by apple on 16/9/23.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 1<<20;
int dp[1010];
int vis[1010];
struct node{
    int v,w;
};
vector<node>tree[1010];
void init(int n){
    for (int i = 0; i<=n; i++) {
        tree[i].clear();
    }
}
void add_edge(int u,int v,int w){
    node t1;
    t1.v = v;t1.w = w;
    tree[u].push_back(t1);
    t1.v = u;
    tree[v].push_back(t1);
}
void dfs(int u,int limit){
    //cout<<u<<' ';
    vis[u] = 1;
    int flag = 0;
    for (int i = 0; i<tree[u].size(); i++) {
        int v = tree[u][i].v;
        int w = tree[u][i].w;
        if (!vis[v]) {
            flag = 1;
            dfs(v, limit);
            if (w>limit) {
                dp[u]+=dp[v];
            }
            else
                dp[u]+=min(dp[v], w);
        }
    }
    if (!flag) {
        dp[u] = INF;
    }
}
int main(int argc, const char * argv[]) {
    int n,m;
    while (~scanf("%d%d",&n,&m)&&(n||m)) {
        init(n);
        int r = 0;
        for (int i = 0; i<n-1; i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u, v, w);
            r = max(r, w);
        }
        r++;
        int l = 1,ans = -1;
        while (l<r) {
            memset(dp, -1, sizeof(dp));
            memset(vis, 0, sizeof(vis));
            int mid = (l+r)/2;
           // cout<<mid<<' ';
            dfs(1, mid);
            if (dp[1]<=m) {
                //cout<<mid<<' '<<l<<' '<<r<<endl;
                ans = mid;
                r = mid;
            }
            else
                l = mid+1;
            //cout<<l<<' '<<r<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}

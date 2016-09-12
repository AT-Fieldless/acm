//
//  main.cpp
//  poj 1258
//
//  Created by apple on 16/9/12.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110;
const int maxm = (maxn*maxn-maxn)/2;
int vis[maxn][maxn];
int n,m;
//假设第i条边的两个端点序号和权值分别保存在u[i],v[i]和w[i]中，而排序后第i小的边的序号保存在r[i]中，p[i]表示父节点
int w[maxm];
int u[maxm];
int v[maxm];
int r[maxm];
int p[maxn];
int cmp(const int i,const int j){
    return w[i]<w[j];
}
int Find(int x){
    return p[x] == x?x:p[x] = Find(p[x]);
}
int Kruskal(){
    int ans = 0;
    for (int i = 0; i<n; i++) {
        p[i] = i;
    }
    for (int i = 0; i<m; i++) {
        r[i] = i;
    }
    sort(r, r+m, cmp);
    for (int i = 0; i<m; i++) {
        int e = r[i];
        int x = Find(u[e]);
        int y = Find(v[e]);
        if (x!=y) {
            ans += w[e];
            p[x] = y;
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    while (cin>>n) {
        m = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                int x;
                scanf("%d",&x);
                if (!vis[i][j]&&x) {
                    u[m] = i;
                    v[m] = j;
                    w[m++] = x;
                    vis[i][j] = 1;
                    vis[j][i] = 1;
                }
            }
        }
        long long ans = Kruskal();
        printf("%lld\n",ans);
    }
    return 0;
}

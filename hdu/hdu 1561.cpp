//
//  main.cpp
//  hdu 1561
//
//  Created by apple on 2016/10/19.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 210;
int n,m;
int w[maxn];
int dp[maxn][maxn];
int vis[maxn];
vector<int>vc[maxn];
void init(int n){
    for (int i = 0; i<=n; i++) {
        vis[i] = 0;
        vc[i].clear();
    }
}
void dfs(int pa){
    //cout<<pa<<' ';
    vis[pa] = 1;
    for (int i = 0; i<vc[pa].size(); i++) {
        int son = vc[pa][i];
        if (!vis[son]) {
            dfs(son);
        }
        for (int j = m; j>=2; j--) {
            for (int k = 1; k<j; k++) {
                if (dp[pa][k]!=-1&&dp[son][j-k]!=-1) {
                    dp[pa][j]=max(dp[pa][j],dp[pa][k]+dp[son][j-k]);
                }
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    while (cin>>n>>m&&(n||m)) {
        init(n);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i<n; i++) {
            int a,b;
            cin>>a>>b;
            vc[a].push_back(i+1);
            w[i] = b;
            dp[i+1][1] = w[i];
        }
        m++;
        dp[0][1] = 0;
        dfs(0);
        cout<<dp[0][m]<<endl;
    }
    return 0;
}

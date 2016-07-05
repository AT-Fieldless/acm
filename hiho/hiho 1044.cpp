//
//  main.cpp
//  hiho 1044
//
//  Created by apple on 16/7/4.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
const int maxn = 1<<11;
int num[1100];
int dp[1100][maxn];
int main() {
    int n,m,q;
    while (~scanf("%d%d%d",&n,&m,&q)) {
        for (int i = 0; i<n; i++) {
            scanf("%d",&num[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<(1<<(m-1)); j++) {
                dp[i+1][j>>1] = max(dp[i][j],dp[i+1][j>>1]);
                int t = j;
                int ans = 0;
                while (t) {
                    if (t%2) {
                        ans++;
                    }
                    t = t>>1;
                }
                if (ans>=q) {
                    dp[i+1][j>>1] = max(dp[i][j],dp[i+1][j>>1]);
                }
                else{
                    dp[i+1][(j>>1)+(1<<(m-2))] = max(dp[i][j]+num[i],dp[i+1][(j>>1)+(1<<(m-2))]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i<(1<<(m-1)); i++) {
            ans = max(ans, dp[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

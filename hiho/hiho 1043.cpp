//
//  main.cpp
//  hiho 1043
//
//  Created by apple on 16/7/4.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int num[510];
int val[510];
int dp[510][110000];
int main() {
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        for (int i = 0; i<n; i++) {
            scanf("%d%d",&num[i],&val[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<=m; j++) {
                if (j<num[i]) {
                    dp[i+1][j] = dp[i][j];
                }
                else{
                    dp[i+1][j] = max(dp[i][j], dp[i+1][j-num[i]]+val[i]);
                }
            }
        }
        int ans = dp[n][m];
        printf("%d\n",ans);
    }
    return 0;
}

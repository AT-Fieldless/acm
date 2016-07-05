//
//  main.cpp
//  hiho 1037
//
//  Created by apple on 16/7/4.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[110][110];
int dp[110][110];
int main() {
    int n;
    while (~scanf("%d",&n)) {
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=i; j++) {
                scanf("%d",&num[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=i; j++) {
                if (j == 1) {
                    dp[i+1][j] = dp[i][j]+num[i][j];
                }
                else if (j == i){
                    dp[i+1][j] = dp[i][j-1]+num[i][j];
                }
                else{
                    dp[i+1][j] = max(dp[i][j],dp[i][j-1]);
                    dp[i+1][j] += num[i][j];
                }
               // cout<<dp[i+1][j]<<' ';
            }
            //cout<<endl;
        }
        int ans = 0;
        for (int i = 1; i<=n;i++) {
            ans = max(ans, dp[n+1][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

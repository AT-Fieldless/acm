//
//  main.cpp
//  poj 2385
//
//  Created by apple on 16/7/14.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1010][33][2];
int num[1010];
int main() {
    int t,w;
    while (~scanf("%d%d",&t,&w)) {
        memset(num, 0, sizeof(num));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i<=t; i++) {
            cin>>num[i];
            //cout<<num[i]<<' ';
        }
        if (num[1] == 1) {
            dp[1][0][0] = 1;
        }
        else{
            dp[1][0][0] = 0;
            dp[1][1][1] = 1;
        }
        for (int i = 2; i<=t; i++) {
            if (num[i] == 1) {
                dp[i][0][0] = dp[i-1][0][0]+1;
                dp[i][0][1] = dp[i-1][0][1];
            }
            else{
                dp[i][0][1] = dp[i-1][0][1]+1;
                dp[i][0][0] = dp[i-1][0][0];
            }
            for (int j = 1; j<=w; j++) {
                if (num[i] == 1) {
                    dp[i][j][0] = max(dp[i-1][j-1][1]+1,dp[i-1][j][0]+1);
                    dp[i][j][1] = dp[i-1][j][1];
                }
                else{
                    dp[i][j][1] = max(dp[i-1][j-1][0]+1,dp[i-1][j][1]+1);
                    dp[i][j][0] = dp[i-1][j][0];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i<=w; i++) {
            ans = max(dp[t][i][0], ans);
            ans = max(dp[t][i][1], ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}

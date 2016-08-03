//
//  main.cpp
//  poj 3176
//
//  Created by apple on 16/7/29.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int num[450][450];
int dp[450][450];
int main(int argc, const char * argv[]) {
    int n;
    while (~scanf("%d",&n)) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<=i; j++) {
                scanf("%d",&num[i][j]);
            }
        }
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<=i; j++) {
                if (j == 0) {
                    dp[i+1][j] = dp[i][j]+num[i][j];
                }
                else{
                    dp[i+1][j] = max(dp[i][j-1]+num[i][j], dp[i][j]+num[i][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i<=n; i++) {
            //cout<<dp[n][i]<<' ';
            ans = max(ans, dp[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

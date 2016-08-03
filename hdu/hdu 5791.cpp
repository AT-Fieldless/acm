//
//  main.cpp
//  hdu 5791
//
//  Created by apple on 16/8/3.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1000000007;
long long dp[1100][1100];
int a[1100];
int b[1100];
int main() {
    int n,m;
    while (cin>>n>>m) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i<=n; i++) {
            cin>>a[i];
        }
        for (int i = 1; i<=m; i++) {
            cin>>b[i];
        }
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=m; j++) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                dp[i][j] %= mod;
                if (a[i] == b[j]) {
                    dp[i][j] += dp[i-1][j-1]+1;
                    dp[i][j] %= mod;
                }
            }
        }
        cout<<(dp[n][m]+mod)%mod<<endl;
    }
    return 0;
}

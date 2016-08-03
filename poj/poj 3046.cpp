
//
//  main.cpp
//  poj 3046
//
//  Created by apple on 16/7/29.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 1e6;
int num[1100];
int dp[2][110000];
int main() {
    int t,a,s,b;
    while (cin>>t>>a>>s>>b) {
        memset(num, 0, sizeof(num));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i<a; i++) {
            int x;
            cin>>x;
            num[x]++;
        }
        int sum = 0;
        for (int i = 1; i<=t; i++) {
            int y = i&1,x = y^1;
            sum+=num[i];
            dp[y][0] = 1;
            for (int j = 1; j<=sum; j++) {
                if (j<num[i]+1) {
                    dp[y][j] = (dp[y][j-1]+dp[x][j])%mod;
                }
                else
                    dp[y][j] = (dp[y][j-1]+dp[x][j]-dp[x][j-1-num[i]])%mod;
            }
        }
        int ans = 0;
        int temp = t&1;
        for (int i = s; i<=b; i++) {
            ans += dp[temp][i];
            ans %= mod;
        }
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}
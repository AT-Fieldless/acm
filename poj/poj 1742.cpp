//
//  main.cpp
//  poj 1742
//
//  Created by apple on 16/6/23.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int dp[100100];
int num[110];
int sum[110];
int main() {
    int n,m;
    while (cin>>n>>m&&n&&m) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i<n; i++) {
            cin>>num[i];
        }
        for (int i = 0; i<n; i++) {
            cin>>sum[i];
        }
        dp[0] = 0;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<=m; j++) {
                if (dp[j]>=0) {
                    dp[j] = sum[i];
                }
                else if (j<num[i]||dp[j-num[i]]<=0)
                    dp[j] = -1;
                else
                    dp[j] = dp[j-num[i]]-1;
            }
        }
        int ans = 0;
        for (int i = 1; i<=m; i++) {
            if (dp[i]>=0) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

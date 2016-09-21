//
//  main.cpp
//  poj 2184
//
//  Created by apple on 16/9/21.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;
int dp[maxn];
int s[110];
int f[110];
int main(int argc, const char * argv[]) {
    int n;
    while (cin>>n) {
        for (int i = 0; i<maxn; i++) {
            dp[i] = -1*INF;
        }
        for (int i = 0; i<n; i++) {
            cin>>s[i]>>f[i];
        }
        dp[100000] = 0;
        for (int i = 0; i<n; i++) {
            if (s[i]>0) {
                for (int j = 200000; j>=s[i]; j--) {
                    if (dp[j-s[i]]>-INF) {
                        //cout<<i<<' '<<j-s[i]<<endl;
                        dp[j] = max(dp[j-s[i]]+f[i], dp[j]);
                    }
                }
            }
            else{
                for (int j = s[i]; j<=200000+s[i]; j++) {
                    if (dp[j-s[i]]>-INF) {
                        //cout<<i<<' '<<j+s[i]<<endl;
                        dp[j] = max(dp[j-s[i]]+f[i], dp[j]);
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 100000; j<=200000; j++) {
            if (dp[j]>=0) {
                ans = max(ans, dp[j]+j-100000);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

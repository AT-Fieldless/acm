//
//  main.cpp
//  hdu 5763
//
//  Created by apple on 16/8/1.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e5+10;
const int mod = 1000000007;
int seed = 10e8+7;
ull ah[maxn];
char a[maxn];
char b[maxn];
int dp[maxn];
int main() {
    int t,kase = 1;
    scanf("%d",&t);
    while (t--) {
        scanf("%s",a);
        scanf("%s",b);
        int l1 = strlen(a);
        int l2 = strlen(b);
        ull h = 0;
        ull t = 1;
        for (int i = 0; i<l2; i++) {
            h = h*seed+b[i];
            t *= seed;
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        ah[0] = a[0];
        for (int i = 1; i<l1; i++) {
            ah[i] = ah[i-1]*seed+a[i];
        }
        for (int i = 1; i<=l2-1; i++) {
            dp[i] = dp[i-1];
        }
        if (ah[l2-1] == h) {
            dp[l2-1] += dp[0];
        }
        for (int i = l2; i<l1; i++) {
            dp[i] = dp[i-1];
            if (ah[i]-ah[i-l2]*t == h) {
                dp[i] += dp[i-l2];
            }
            dp[i] %= mod;
        }
        printf("Case #%d: %d\n",kase++,dp[l1-1]);
    }
    return 0;
}

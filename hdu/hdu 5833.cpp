//
//  main.cpp
//  hdu 5833
//
//  Created by apple on 16/8/16.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 2e3+10;
const int mod = 1000000007;
typedef int Matrix[maxn][maxn];
Matrix ans;
int vis[maxn];
int prime[maxn];
int cnt;
void init(){
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (int i = 2; i<=2000; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            for (int j = i; j<=2000; j+=i) {
                vis[j] = 1;
            }
        }
    }
}
int solve(int m,int n){
    int i,j;
    i = 0,j = 0;
    while (i<m&&j<n) {
        int k = i;
        for (; k<m; k++) {
            if (ans[k][j]) {
                break;
            }
        }
        if (ans[k][j]) {
            if (k!=i) {
                for (int r = 0; r<=n; r++) {
                    swap(ans[i][r], ans[k][r]);
                }
            }
            for (k = i+1; k<m; k++) {
                if (ans[k][j]) {
                    for (int r = j; r<=n; r++) {
                        ans[k][r] ^= ans[i][r];
                    }
                }
            }
            i++;
        }
        j++;
    }
    return i;
}
long long fast_pow(int j){
    long long ans = 1;
    long long a = 2;
    while (j) {
        if (j&1) {
            ans *= a;
            ans %=mod;
        }
        a *= a;
        a %= mod;
        j>>=1;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int t,kase = 1;
    scanf("%d",&t);
    init();
    while (t--) {
        int n,m = 0;
        scanf("%d",&n);
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i<n; i++) {
            long long x;
            scanf("%lld",&x);
            for (int j = 0; j<cnt; j++) {
                while (x%prime[j] == 0) {
                    m = max(m,j);
                    ans[j][i] ^= 1;
                    x /= prime[j];
                }
            }
        }
        printf("Case #%d:\n",kase++);
        printf("%lld\n",fast_pow(n-solve(m+1, n))-1);
    }
    return 0;
}

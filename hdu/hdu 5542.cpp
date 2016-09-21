//
//  main.cpp
//  hdu 5542
//
//  Created by apple on 16/9/21.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
#define lowbit(x) x&-x
const int maxn = 1e3+10;
const int mod = 1000000007;
int n,m;
int tree[maxn][maxn];
int dp[maxn][maxn];
int num[maxn];
int sum(int i,int j){
    int ret = 0;
    while (j>0) {
        //cout<<j<<' ';
        ret += tree[i][j];
        if (ret>=mod) {
            ret %= mod;
        }
        //ret %= mod;
        j -= lowbit(j);
    }
    return ret;
}
void add(int i,int j,int d){
    while (j<=n) {
        //cout<<j<<' ';
        tree[i][j] += d;
        if (tree[i][j]>mod) {
            tree[i][j] %= mod;
        }
        j += lowbit(j);
    }
}
int main(int argc, const char * argv[]) {
    int t,cas = 1;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        map<int, int>mp;
        set<int> se;
        for (int i = 0; i<n; i++) {
            scanf("%d",&num[i]);
            se.insert(num[i]);
        }
        int cnt = 0;
        for (set<int>::iterator it = se.begin(); it!=se.end(); it++) {
            mp[*it] = ++cnt;
        }
        memset(dp, 0, sizeof(dp));
        memset(tree, 0, sizeof(tree));
        for (int i = 0; i<n; i++) {
            for (int j = 1; j<=m; j++) {
                if (j == 1) {
                    dp[i][j] = 1;
                }
                else{
                    int temp = sum(j-1, mp[num[i]]-1);
                    dp[i][j]+=temp;
                    if (dp[i][j]>=mod) {
                        dp[i][j] = dp[i][j]%mod;
                    }
                }
                add(j, mp[num[i]], dp[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i<n; i++) {
            ans += dp[i][m];
            if (ans >= mod) {
                ans %= mod;
            }
            //ans %= mod;
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}

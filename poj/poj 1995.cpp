//
//  main.cpp
//  poj 3641
//
//  Created by apple on 16/7/20.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll mod_pow(ll x,ll n,ll mod){
    ll res = 1;
    while (n>0) {
        if (n&1) {
            res = res*x%mod;
        }
        x = x*x%mod;
        n >>=1;
    }
    return res;
}
int main() {
    int z;
    scanf("%d",&z);
    while (z--) {
        int m;
        scanf("%d",&m);
        int h;
        scanf("%d",&h);
        ll ans = 0;
        for (int i = 0; i<h; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            ans += mod_pow(a, b, m);
            ans %= m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

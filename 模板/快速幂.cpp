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
bool is_prime(ll x){
    for (ll i = 2; i*i<=x; i++) {
        if (x%i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    ll p,a;
    while (scanf("%lld%lld",&p,&a)&&(p||a)) {
        if (mod_pow(a,p,p) == a&&!is_prime(p)) {
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}

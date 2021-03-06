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

struct matrix{
    long long a[maxn][maxn];
};
//矩阵乘法
matrix mul(matrix a,matrix b){
    matrix c;
    for (int i = 0; i<=d; i++) {
        for (int j = 0; j<=d; j++) {
            c.a[i][j] = 0;
        }
    }
    for (int i = 0; i<d; i++) {
        for (int j = 0; j<d; j++) {
            for (int k = 0; k<d; k++) {
                c.a[i][j] += a.a[i][k]*b.a[k][j];
                c.a[i][j] %= m;
            }
        }
    }
    //for (int i = 0; i<=d; i++) {
    //  for (int j = 0; j<=d; j++) {
    //cout<<c.a[i][j]<<' ';
    //}
    //cout<<endl;
    //}
    return c;
}
//矩阵快速幂
matrix mod_pow(matrix x,int k){
    matrix c;
    //单位矩阵
    for (int i = 0; i<d; i++) {
        for (int j = 0; j<d; j++) {
            c.a[i][j] = (i == j);
        }
    }
    while (k) {
        if (k&1) {
            c = mul(c, x);
        }
        x = mul(x, x);
        k>>=1;
    }
    return c;
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

//
//  main.cpp
//  hdu 5775
//
//  Created by apple on 16/7/31.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define lowbit(x) x&-x
const int maxn = 1e5+10;
int n;
int c[maxn];
int k[maxn];
int init[maxn];
int num[maxn];
int sum(int x){
    int ret = 0;
    while (x>0) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x,int d){
    while (x<=n) {
        c[x] += d;
        x += lowbit(x);
    }
}
int main() {
    int t,kase = 1;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        memset(c, 0, sizeof(c));
        for (int i = 0; i<n; i++) {
            scanf("%d",&num[i]);
            init[num[i]] = i+1;
        }
        for (int i = 0; i<n; i++) {
            add(num[i], 1);
            k[num[i]] = num[i]-sum(num[i])+init[num[i]];
        }
        printf("Case #%d:",kase++);
        for (int i = 1; i<=n; i++) {
            printf(" %d",abs(k[i]-min(init[i], i)));
        }
        cout<<endl;
    }
    return 0;
}

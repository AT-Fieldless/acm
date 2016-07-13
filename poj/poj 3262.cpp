//
//  main.cpp
//  poj 3262
//
//  Created by apple on 16/7/13.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    long long t;
    long long d;
}num[101000];
bool cmp(node a,node b){
    return a.d*1.0/a.t > b.d*1.0/b.t;
}
int main() {
    int n;
    while (~scanf("%d",&n)) {
        for (int i = 0; i<n; i++) {
            scanf("%lld%lld",&num[i].t,&num[i].d);
        }
        sort(num, num+n, cmp);
        long long ans = 0;long long t = 0;
        for (int i = 0; i<n; i++) {
            ans += t*num[i].d;
            t += 2*num[i].t;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

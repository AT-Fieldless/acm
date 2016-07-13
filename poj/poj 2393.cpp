//
//  main.cpp
//  poj 2393
//
//  Created by apple on 16/7/13.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
long long val[10100];
long long sum[10100];
int main() {
    int n,s;
    while (cin>>n>>s) {
        for (int i = 0; i<n; i++) {
            scanf("%lld",&val[i]);
            scanf("%lld",&sum[i]);
        }
        long long ans = 0;
        long long temp = INF;
        for (int i = 0; i<n; i++) {
            if (temp>val[i]) {
                temp = val[i];
            }
            ans += temp*sum[i];
            temp += s;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

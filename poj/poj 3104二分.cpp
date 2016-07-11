//
//  main.cpp
//  poj3104
//
//  Created by apple on 16/7/10.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
long long num[100100];
int main() {
    int n;
    while (~scanf("%d",&n)) {
        long long lp = 1,rp = 0;
        for (int i = 0; i<n; i++) {
            scanf("%lld",&num[i]);
            rp = max(rp, num[i]);
        }
        long long k;
        scanf("%lld",&k);
        long long ans = 0;
        if (k == 1) {
            printf("%lld\n",rp);
            continue;
        }
        k--;
        while (lp<=rp) {
            long long mid = (lp+rp)/2;
            long long temp = 0;
            for (int i = 0; i<n; i++) {
                if (num[i]>mid) {
                    temp += (num[i]-mid+k-1)*1/k;
                }
            }
            if (temp<=mid) {
                ans = mid;
                rp = mid-1;
            }
            else{
                lp = mid+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

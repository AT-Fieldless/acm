//
//  main.cpp
//  uva 10635
//
//  Created by apple on 16/5/2.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n1[62510];
int n2[62520];
int num[62510];
int main() {
    int t,kase = 1;
    cin>>t;
    while (t--) {
        int n,p,q;
        cin>>n>>p>>q;
        for (int i = 0; i<=p; i++) {
            n1[i] = i+1;
            int x;
            cin>>x;
            num[x] = i+1;
        }
        for (int i = 0; i<=q; i++) {
            int x;
            cin>>x;
            n2[i] = num[x];
        }
        for (int i = 1; i<=q+1; i++) {
            num[i] = 0x3f3f3f3f;
        }
        long ans = 0;
        for (int i = 0; i<=q; i++) {
            long j = lower_bound(num, num+q+1, n2[i])-num;
            if (j>ans) {
                ans = j;
            }
            num[j] = n2[i];
        }
        printf("Case %d: %ld\n",kase++,ans);
    }
    return 0;
}

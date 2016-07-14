//
//  main.cpp
//  poj 3616
//
//  Created by apple on 16/7/14.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node{
    int s;
    int e;
    int sum;
}num[1025];
bool cmp(node a,node b){
    return a.s<b.s;
}
int dp[1024];
int main() {
    int n,m,r;
    while (~scanf("%d%d%d",&n,&m,&r)) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i<m; i++) {
            scanf("%d%d%d",&num[i].s,&num[i].e,&num[i].sum);
            num[i].e += r;
        }
        sort(num, num+m, cmp);
        int ans = 0;
        for (int i = 0; i<m; i++) {
            dp[i] = num[i].sum;
        }
        for (int i = 0; i<m; i++) {
            for (int j = i+1; j<m; j++) {
                if (num[i].e<=num[j].s) {
                    dp[j] = max(dp[j], dp[i]+num[j].sum);
                }
                ans = max(ans, dp[j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

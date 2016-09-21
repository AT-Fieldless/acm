//
//  main.cpp
//  poj 2392
//
//  Created by apple on 16/9/14.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e3+10;
int dp[400100];
struct block{
    int h,a,c;
}num[maxn];
bool cmp(block i,block j){
    return i.a<j.a;
}
int main(int argc, const char * argv[]) {
    int k;
    while (~scanf("%d",&k)) {
        memset(dp, -1, sizeof(dp));
        int Max = 0;
        for (int i = 0; i<k; i++) {
            scanf("%d%d%d",&num[i].h,&num[i].a,&num[i].c);
            Max = max(Max, num[i].a);
        }
        sort(num, num+k, cmp);
        dp[0] = 0;
        for (int i = 0; i<k; i++) {
          //  cout<<i<<' ';
            for (int j = 0; j<=num[i].a; j++) {
                if (dp[j]>=0) {
                    dp[j] = num[i].c;
                }
                else if (j<num[i].h||dp[j-num[i].h]<=0)
                    dp[j] = -1;
                else
                    dp[j] = dp[j-num[i].h]-1;
                //cout<<j<<' '<<dp[j]<<endl;
            }
        }
        for (int i = Max; i>=0; i--) {
            if (dp[i]>=0) {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}

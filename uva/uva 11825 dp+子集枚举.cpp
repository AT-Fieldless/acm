//
//  main.cpp
//  uva 11825
//
//  Created by apple on 16/5/1.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int p[20];              //表示第i个组有哪些电脑
int cover[1<<17];       //用二进制来表示包含的所有p[i]的并集
int dp[1<<17];
int main() {
    int n,kase = 1;
    while (scanf("%d",&n)&&n) {
        for (int i = 0; i<n; i++) {
            int m;
            scanf("%d",&m);
            p[i] = 1<<i;
            while (m--) {
                int x;
                scanf("%d",&x);
                p[i] |= (1<<x);
            }
        }
        for (int i = 0; i<(1<<n); i++) {
            cover[i] = 0;
            for (int j = 0; j<n; j++) {
                if (i&(1<<j)) {
                    cover[i] |= p[j];
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i<(1<<n); i++) {
            for (int j = i; j; j = (j-1)&i) {   //子集枚举
                if (cover[j] == (1<<n)-1) {     //全部满足，可以进行攻击
                    dp[i] = max(dp[i],dp[i^j]+1);      //要么等于自身，要么等于补集+1
                }
            }
        }
        printf("Case %d: %d\n",kase++,dp[(1<<n)-1]);
    }
    return 0;
}
/*
3
2 1 2
2 0 2
2 0 1
4
1 1
1 0
1 3
1 2
0
*/
//
//  main.cpp
//  poj 2139
//
//  Created by apple on 16/7/15.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[310][310];
int num[310];
int main() {
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = INF;
            }
        }
        for (int i = 0; i<m; i++) {
            int x;
            scanf("%d",&x);
            for (int j = 0; j<x; j++) {
                scanf("%d",&num[j]);
                num[j]--;
            }
            for (int j = 0; j<x; j++) {
                for (int k = 0; k<x; k++) {
                    if (j == k) {
                        continue;
                    }
                    dp[num[j]][num[k]] = 1;
                }
            }
        }
        for (int k = 0; k<n; k++) {
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    if (j == i) {
                        continue;
                    }
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans = INF;
        for (int i = 0; i<n; i++) {
            int temp = 0;
            for (int j = 0; j<n; j++) {
                temp += dp[i][j];
            }
            ans = min(ans, temp);
        }
        cout<<int(double(ans*1.0/(n-1))*100)<<endl;
    }
    return 0;
}

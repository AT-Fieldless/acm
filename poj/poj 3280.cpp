//
//  main.cpp
//  poj 3280
//
//  Created by apple on 16/7/14.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char str[2100];
int cost[30];
int dp[2200][2200];
int main() {
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        memset(dp, 0, sizeof(dp));
        scanf("%s",str);
        for (int i = 0; i<n; i++) {
            char t;
            getchar();
            scanf("%c",&t);
            //putchar(t);
            int x,y;
            scanf("%d%d",&x,&y);
            cost[t-'a'] = min(x, y);
        }
        for (int i = 1; i<m; i++) {
            for (int j = i-1; j>=0; j--) {
                dp[j][i] = min(dp[j+1][i]+cost[str[j]-'a'], dp[j][i-1]+cost[str[i]-'a']);
                if (str[j] == str[i]) {
                    dp[j][i] = min(dp[j][i], dp[j+1][i-1]);
                }
            }
        }
        cout<<dp[0][m-1]<<endl;
    }
    return 0;
}

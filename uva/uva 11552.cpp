//
//  main.cpp
//  uva 11552
//
//  Created by apple on 16/9/11.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[1100][1100];
char str[1100];
int vis[200];
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d",&t);
    while (t--) {
        int k;
        for (int i = 0; i<=1000; i++) {
            for (int j = 0; j<=1000; j++) {
                dp[i][j] = INF;
            }
        }
        scanf("%d",&k);
        scanf("%s",str);
        int len = strlen(str);
        int t = len/k;
        for (int i = 0; i<t; i++) {
            memset(vis, 0, sizeof(vis));
            int cnt = 0;
            for (int j = 0; j<k; j++) {
                int temp = i*k+j;
                if (!vis[str[temp]]) {
                    cnt++;
                    vis[str[temp]]++;
                }
            }
            if (i == 0) {
                for (int j = 0; j<k; j++) {
                    dp[i][j] = cnt;
                }
                continue;
            }
            for (int j = 0; j<k; j++) {
                int rear = i*k+j;
                for (int a = 0; a<k; a++) {
                    int pre = (i-1)*k+a;
                    if (vis[str[pre]]&&(cnt == 1||str[pre] != str[rear])) {
                        dp[i][j] = min(dp[i][j], dp[i-1][a]+cnt-1);
                    }
                    else
                        dp[i][j] = min(dp[i][j], dp[i-1][a]+cnt);
                }
            }
        }
        int ans = INF;
        for (int i = 0; i<k; i++) {
            ans = min(dp[t-1][i], ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}

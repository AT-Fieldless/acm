//
//  main.cpp
//  uva 10891
//
//  Created by apple on 16/5/2.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int s[110];
int f[110][110];
int g[110][110];
int dp[110][110];
int main(int argc, const char * argv[]) {
    int n;
    memset(s, 0, sizeof(s));
    while (cin>>n&&n) {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(f));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i<=n; i++) {
            int x;
            cin>>x;
            f[i][i] = x;
            g[i][i] = x;
            dp[i][i] = x;
            s[i] = s[i-1]+x;
        }
        for (int i = 1; i<n; i++) {
            for (int j = 1; j+i<=n; j++) {
                int m = 0;
                m = min(m, f[j+1][j+i]);
                m = min(m, g[j][j+i-1]);
                dp[j][j+i] = s[j+i]-s[j-1]-m;
                f[j][j+i] = min(f[j+1][j+i], dp[j][j+i]);
                g[j][j+i] = min(g[j][j+i-1], dp[j][j+i]);
            }
        }
        cout<<2*dp[1][n]-s[n]<<endl;
    }
    return 0;
}
/*
4
4 -10 -20 7 
4
1 2 3 4
0
*/
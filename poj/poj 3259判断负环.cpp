//
//  main.cpp
//  poj 3259
//
//  Created by apple on 16/7/11.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstdio>
const int INF = 1000001;
using namespace std;
int d[510][510];
int main() {
    int f;
    scanf("%d",&f);
    while (f--) {
        int n,m,w;
        scanf("%d%d%d",&n,&m,&w);
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (i == j) {
                    d[i][i] = 0;
                    continue;
                }
                d[i][j] = INF;
                d[j][i] = INF;
            }
        }
        for (int i = 0; i<m; i++) {
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            s--;e--;
            if(d[s][e] < t) continue;
            d[s][e] = t;
            d[e][s] = d[s][e];
        }
        for (int i = 0; i<w; i++) {
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            s--;e--;
            d[s][e] = -t;
        }
        int flag = 0;
        for (int k = 0; k<n; k++) {
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    if (d[i][j]>d[i][k]+d[k][j]) {
                        d[i][j] = d[i][k]+d[k][j];
                    }
                }
                if (d[i][i]<0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

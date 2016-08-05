//
//  main.cpp
//  poj 1840
//
//  Created by apple on 16/8/5.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define lf(x) x*x*x
const int maxn = 2e6+7;
int ha[maxn+10];
int nxt[maxn+10];
int sum[maxn+10];
int id;
void get_hash(int x){
    int tx = x;
    if (x<0) {
        x*=-1;
    }
    int t = (x%maxn+x/maxn)%maxn;
    sum[id] = tx;
    nxt[id] = ha[t];
    ha[t] = id++;
}
int fi(int x){
    int tx = x;
    int ans = 0;
    if (x<0) {
        x*=-1;
    }
    int t = (x%maxn+x/maxn)%maxn;
    int temp = ha[t];
    while (temp) {
        if (sum[temp] == tx) {
            ans++;
        }
        temp = nxt[temp];
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int a1,a2,a3,a4,a5;
    while (cin>>a1>>a2>>a3>>a4>>a5) {
        memset(ha, 0, sizeof(ha));
        memset(nxt, 0, sizeof(nxt));
        memset(sum, 0, sizeof(sum));
        id = 1;
        for (int i = -50; i<=50; i++) {
            if (i == 0) {
                continue;
            }
            for (int j = -50; j<=50; j++) {
                if (j == 0) {
                    continue;
                }
                get_hash(a1*lf(i)+a2*lf(j));
            }
        }
        int ans = 0;
        for (int i = -50; i<=50; i++) {
            if (i == 0) {
                continue;
            }
            for (int j = -50; j<=50; j++) {
                if (j == 0) {
                    continue;
                }
                for (int k = -50; k<=50; k++) {
                    if (k == 0) {
                        continue;
                    }
                    ans+=fi(a3*lf(i)+a4*lf(j)+a5*lf(k));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

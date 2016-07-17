//
//  main.cpp
//  poj 3292
//
//  Created by apple on 16/7/15.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000001;
int is_h[1000011];
int is_sh[1000011];
int sum[maxn+10];
void init(){
    memset(is_h, 0, sizeof(is_h));
    memset(is_sh, 0, sizeof(is_sh));
    memset(sum, 0, sizeof(sum));
    for (int i = 5; i<=maxn; i+=4) {
        is_h[i] = 1;
    }
    for (int i = 5; i<=maxn; i+=4) {
        for (int j = 5; i*j<=maxn; j+=4) {
            if (is_h[i]&&is_h[j]) {
                is_sh[i*j] = 1;
            }
            else{
                is_sh[i*j] = 0;
            }
            is_h[i*j] = 0;
        }
    }
    int s = 0;
    for (int i = 5; i<=maxn; i+=4) {
        if (is_sh[i]) {
            s++;
        }
        sum[i] = s;
    }
}
int main() {
    int h;
    init();
    while (~scanf("%d",&h)&&h) {
        cout<<h<<' ';
        printf("%d\n",sum[h]);
    }
    return 0;
}

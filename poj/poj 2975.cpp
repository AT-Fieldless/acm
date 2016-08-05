//
//  main.cpp
//  poj 2975
//
//  Created by apple on 16/8/5.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[110];
void get_1(int n){
    int cnt = 1;
    while (n) {
        if (n&1) {
            num[cnt]++;
        }
        cnt++;
        n>>=1;
    }
}
int main(int argc, const char * argv[]) {
    int n;
    while (~scanf("%d",&n)&&n) {
        memset(num, 0, sizeof(num));
        long long temp = 0;
        for (int i = 0; i<n; i++) {
            int x;
            scanf("%d",&x);
            temp^=x;
            get_1(x);
        }
        int cnt = 1;
        int ans = 0;
        while (temp) {
            if (temp&1) {
                ans = cnt;
            }
            cnt++;
            temp>>=1;
        }
        cout<<num[ans]<<endl;
    }
    return 0;
}

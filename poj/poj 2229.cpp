//
//  main.cpp
//  poj 2229
//
//  Created by apple on 16/7/14.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
using namespace std;
long long dp[1001000];
const long long mod = 1000000000;
void init(){
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i<=1000000; i++) {
        if (i%2) {
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = (dp[i-1]+dp[i/2])%mod;
        }
        //cout<<dp[i]<<' ';
    }
}
int main() {
    init();
    int n;
    while (~scanf("%d",&n)) {
        printf("%lld\n",dp[n]);
    }
    return 0;
}

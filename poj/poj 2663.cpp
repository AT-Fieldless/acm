//
//  main.cpp
//  poj 2663
//
//  Created by apple on 2016/10/13.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
long long dp[33];
int main(int argc, const char * argv[]) {
    int n;
    memset(dp, 0, sizeof(dp));
    dp[2] = 3;
    dp[4] = 11;
    dp[0] = 1;
    for (int i = 6; i<=30; i+=2) {
        dp[i] = 4*dp[i-2]-dp[i-4];
    }
    while (cin>>n) {
        if (n == -1) {
            break;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

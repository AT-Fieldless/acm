//
//  main.cpp
//  uva 11584
//
//  Created by apple on 16/9/5.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
char str[1100];
int dp[1100];
bool is_ok(int i,int j){
    while (i<j) {
        if (str[i]!=str[j]) {
            return false;
        }
        i++;j--;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    while (t--) {
        scanf("%s",str+1);
        int len = strlen(str+1);
        dp[0] = 0;
        for (int i = 1; i<=len; i++) {
            dp[i] = dp[i-1]+1;
            for (int j = 1; j<i; j++) {
                if (is_ok(j, i)) {
                    //cout<<j<<' '<<i<<endl;
                    dp[i] = min(dp[i],dp[j-1]+1);
                }
            }
        }
        cout<<dp[len]<<endl;
    }
    return 0;
}

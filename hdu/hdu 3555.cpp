//
//  main.cpp
//  hdu 3555
//
//  Created by apple on 2016/10/18.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
using namespace std;
int num[100];
__int64 dp[100][10];
int main(int argc, const char * argv[]) {
    dp[0][0] = 1;
    for (int i = 0; i<=20; i++) {
        dp[i+1][0] = 10*dp[i][0]-dp[i][1];
        dp[i+1][1] = dp[i][0];
        dp[i+1][2] = 10*dp[i][2]+dp[i][1];
        //cout<<dp[i+1][2]<<endl;
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        __int64 temp;
        scanf("%I64d",&temp);
        temp++;
        int cnt = 0;
        while (temp) {
            num[++cnt] = temp%10;
            temp/=10;
        }
        int last=0,flag = 0;
        __int64 ans = 0;
        for (int i = cnt; i>0; i--) {
            ans += dp[i-1][2]*num[i];
            if (flag == 0&&num[i]>4) {
                ans += dp[i-1][1];
            }
            if (flag == 1) {
                ans += dp[i-1][0]*num[i];
            }
            if (last == 4&&num[i] == 9) {
                flag = 1;
            }
            last = num[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

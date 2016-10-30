//
//  main.cpp
//  hdu 5945
//
//  Created by apple on 2016/10/30.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
int dp[maxn];
int q[maxn];
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d",&t);
    while (t--) {
        int x,k,t;
        scanf("%d%d%d",&x,&k,&t);
        int head,tail;
        head = tail = 1;
        for (int i = 0; i<=x; i++) {
            dp[i] = INF;
        }
        dp[1] = 0;
        q[head++] = 1;
        for (int i = 2; i<=x; i++) {
            while (tail<head&&q[tail]<i-t) {
                tail++;
            }
            if (tail<head) {
                dp[i] = min(dp[i],dp[q[tail]]+1);
               // cout<<i<<' '<<dp[i]<<endl;
            }
            if (i%k == 0) {
                dp[i] = min(dp[i],dp[i/k]+1);
            }
            while (tail<head&&dp[q[head-1]]>dp[i]) {
                head--;
            }
            q[head++] = i;
        }
        printf("%d\n",dp[x]);
    }
    return 0;
}

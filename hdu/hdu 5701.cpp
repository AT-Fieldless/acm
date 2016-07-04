//
//  main.cpp
//  hdu 5701
//
//  Created by apple on 16/5/24.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int num[8100];
int sum1[16200];
int sum2[16200];
int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i = 1; i<=n; i++) {
            scanf("%d",&num[i]);
        }
        for (int i = 1; i<=n; i++) {
            memset(sum1, 0, sizeof(sum1));
            memset(sum2, 0, sizeof(sum2));
            int ans = 1;
            int cnt = 0;
            for(int j=i-1;j>=1;j--){
                if(num[j]<num[i]) cnt++;
                else cnt--;
                if(cnt==0) ans++;
                sum1[cnt+n]++;
            }
            cnt = 0;
            for(int j=i+1;j<=n;j++){
                if(num[j]>num[i]) cnt++;
                else cnt--;
                if(cnt==0) ans++;
                sum2[cnt+n]++;
            }
            for(int j=0;j<2*n;j++) ans+=sum1[j]*sum2[j];
            i != n?printf("%d ",ans):printf("%d\n",ans);
            
        }
    }
    return 0;
}

//
//  main.cpp
//  hdu 5773
//
//  Created by apple on 16/8/1.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 500010;
const int INF = 0x3f3f3f3f;
int a[maxn],b[maxn];
int Search(int num,int low,int high){
    int mid;
    while (low<=high) {
        mid = (low+high)/2;
        if (num>=b[mid]) {
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return low;
}
int DP(int n){
    int i,len,pos;
    b[1] = a[1];
    len = 1;
    for (i = 2; i<=n; i++) {
        if (a[i]>b[len]) {
            len = len+1;
            b[len] = a[i];
        }
        else{
            pos = Search(a[i], 1, len);
            b[pos] = a[i];
        }
    }
    return len;
}
int main() {
    int t,kase = 1;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        int temp = 0,flag = 1;
        for (int i = 1; i<=n; i++) {
            scanf("%d",&a[i]);
            if (a[i] == 0) {
                i--;
                n--;
                temp++;
            }
            else{
            a[i] -= temp;
                flag = 0;
            }
        }
        //n+=temp;
        int ans = DP(n);
        if (flag) {
            ans = 0;
        }
        ans += temp;
        printf("Case #%d: %d\n",kase++,ans);
    }
    return 0;
}

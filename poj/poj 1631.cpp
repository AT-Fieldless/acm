//
//  main.cpp
//  poj 1631
//
//  Created by apple on 16/9/14.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500010;
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
        if (a[i]>=b[len]) {
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
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while (n--) {
        int p;
        cin>>p;
        for (int i = 1; i<=p; i++) {
            cin>>a[i];
        }
        int ans = DP(p);
        cout<<ans<<endl;
    }
    return 0;
}

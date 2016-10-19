//
//  main.cpp
//  cf 732B
//
//  Created by apple on 2016/10/19.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[510][10];
int num[510];
int main(int argc, const char * argv[]) {
    int n,k;
    while (cin>>n>>k) {
        for (int i = 0; i<n; i++) {
            cin>>num[i];
        }
        int ans = 0;
        for (int i = 1; i<n; i++) {
            if (k>num[i]+num[i-1]) {
                ans += k-num[i]-num[i-1];
                num[i]+= k-num[i]-num[i-1];
            }
        }
        cout<<ans<<endl;
        for (int i = 0; i<n; i++) {
            cout<<num[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

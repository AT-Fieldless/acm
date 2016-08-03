//
//  main.cpp
//  poj 2718
//
//  Created by apple on 16/8/3.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[22];
char ch[100];
int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    getchar();
    while (t--) {
        gets(ch);
        int len = strlen(ch);
        int n = 0;
        for (int i = 0; i<len; i++) {
            if (ch[i]>='0'&&ch[i]<='9') {
                a[n++] = ch[i] - '0';
            }
        }
        if (n == 1) {
            printf("%d\n",a[0]);
            continue;
        }
        if (n == 2) {
            printf("%d\n",abs(a[1]-a[0]));
            continue;
        }
        int ans = INF;
        while (a[0] == 0) {
            next_permutation(a, a+n);
        }
        int mid = (n+1)/2;
        do {
            if (!a[mid]) {
                continue;
            }
            int x = 0;
            int y = 0;
            for (int i = 0; i<mid; i++) {
                x = x*10+a[i];
            }
            for (int i = mid; i<n; i++) {
                y = y*10+a[i];
            }
            if (abs(x-y)<ans) {
                ans = abs(x-y);
            }
        }while(next_permutation(a, a+n));
        cout<<ans<<endl;
    }
    return 0;
}

//
//  main.cpp
//  poj 2376
//
//  Created by apple on 16/7/12.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct t{
    int s;
    int e;
}num[26000];
const int INF = 0x3f3f3f3f;
bool cmp(t a,t b){
    if (a.s == b.s) {
        return a.e<b.e;
    }
    else
        return a.s<b.s;
}
int main() {
    int n,t;
    while (~scanf("%d%d",&n,&t)) {
        for (int i = 0; i<n; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            num[i].s = a;
            num[i].e = b;
        }
        num[n].s = num[n].e = INF;
        sort(num, num+n, cmp);
        if (num[0].s!=1) {
            cout<<-1<<endl;
            continue;
        }
        int s = 0,e = s,flag = 0,ans = 0;
        for (int i = 0; i<n; i++) {
            if (num[i].s<=s+1) {
                if (num[i].e>e) {
                    e = num[i].e;
                    flag = 1;
                }
                if (num[i+1].s>s+1&&flag) {
                    flag = 0;
                    s = e;
                    ans++;
                }
            }
        }
        if (e != t) {
            cout<<-1<<endl;
        }
        else
            cout<<ans<<endl;
    }
    return 0;
}

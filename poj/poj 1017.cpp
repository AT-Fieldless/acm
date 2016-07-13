//
//  main.cpp
//  poj 1017
//
//  Created by apple on 16/7/13.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int a,b,c,d,e,f;
    while (cin>>a>>b>>c>>d>>e>>f&&(a||b||c||d||e||f)) {
        int ans = 0;
        ans += f;
        ans += e;
        a = max(0, a-(e*11));
        ans += d;
        if(b>=d*5)
            b-=d*5;
        else
        {
            a=max(0,a-4*(d*5-b));
            b=0;
        }
        
        ans+=(c+3)/4;
        c%=4;
        if(c)
        {
            if(b>=7-2*c)
            {
                b-=7-2*c;
                a=max(0,a-(8-c));
            }
            else
            {
                a=max(0,a-(36-9*c-4*b));
                b=0;
            }
        }
        ans += (b+8)/9;
        b = b%9;
        if (b) {
            a = max(0, a-(36-4*b));
        }
        ans += (a+35)/36;
        printf("%d\n",ans);
    }
    return 0;
}

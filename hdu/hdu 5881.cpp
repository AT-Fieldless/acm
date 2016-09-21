//
//  main.cpp
//  hdu 5881
//
//  Created by apple on 16/9/17.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, const char * argv[]) {
    long long l,r;
    while (~scanf("%lld%lld",&l,&r)) {
        if (r<=1) {
            cout<<0<<endl;
            continue;
        }
        if (r<=2) {
            cout<<1<<endl;
            continue;
        }
        if (l == r||l == r-1) {
            cout<<2<<endl;
            continue;
        }
        if (l<=1) {
            l = 1;
        }
        cout<<(r-l)/2+1<<endl;
    }
    return 0;
}

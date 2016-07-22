//
//  main.cpp
//  hdu 1517
//
//  Created by apple on 16/7/22.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    while (~scanf("%lld",&n)) {
        int flag = 1;
        while (n!=1) {
            if (flag) {
                n = (n+8)/9;
            }
            else{
                n = (n+1)/2;
            }
            //cout<<n<<endl;
            flag ^= 1;
        }
        if (!flag) {
            cout<<"Stan wins."<<endl;
        }
        else{
            cout<<"Ollie wins."<<endl;
        }
    }
    return 0;
}

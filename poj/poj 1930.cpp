//
//  main.cpp
//  poj 1930
//
//  Created by apple on 16/7/31.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned ull;
const int INF = 0x3f3f3f3f;
char str[1000000];
ull gcd(ull a,ull b){
    if (b == 0) {
        return a;
    }
    return gcd(b,a%b);
}
int main() {
    while (~scanf("%s",str)) {
        int len = strlen(str);
        if (len == 1) {
            break;
        }
        ull x = INF,y = INF;
        ull fenmu = 0;
        ull fenzi = 0;
        for (int i = 2; i<len; i++) {
            if (str[i] == '.') {
                break;
            }
            fenzi=fenzi*10+str[i]-'0';
        }
        if (fenzi == 0) {
            printf("0/1\n");
            continue;
        }
        len -= 4;
        ull temp = fenzi;
        for (int i = len; i>1; i--) {
            fenmu*=10;
            fenmu+=9;
            fenmu*=(int)pow(10.0,i-2);
            temp/=10;
            ull k = gcd(fenmu, fenzi-temp);
            if (fenmu/k<y) {
                y = fenmu/k;
                x = (fenzi-temp)/k;
            }
            fenmu/=(int)pow(10.0, i-2);
        }
        cout<<x<<'/'<<y<<endl;
    }
    return 0;
}

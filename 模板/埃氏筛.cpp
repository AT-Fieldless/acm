//
//  main.cpp
//  aoj 0009
//
//  Created by apple on 16/7/15.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int is_prime[1999999];
int prime[999999];
int sieve(int n){
    int p = 0;
    for (int i = 0; i<=n; i++) {
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i<=n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2*i; j<=n; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    return p;
}
int main() {
    
    return 0;
}

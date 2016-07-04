//
//  main.cpp
//  hdu 2203
//
//  Created by apple on 16/5/18.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;
const ull m = 100000007;
bool contain(string a,string b)
{
    int al = a.length(),bl = b.length();
    if (al>bl) {
        return false;
    }
    ull t = 1;
    for (int i = 0; i<al; i++) {
        t *= m;
    }
    ull ah = 0,bh = 0;
    for (int i = 0; i<al; i++) {
        ah = ah*m+a[i];
    }
    for (int i = 0; i<al; i++) {
        bh = bh*m+b[i];
    }
    for (int i = 0; i+al<=bl; i++) {
        if (ah == bh) {
            return true;
        }
        if (i+al<bl) {
            bh = bh*m+b[i+al]-b[i]*t;
        }
    }
    return false;
}
int main() {
    string s1,s2;
    while (cin>>s1>>s2) {
        s1 += s1;
        if (contain(s2, s1)) {
            cout<<"yes"<<endl;
        }
        else
            cout<<"no"<<endl;
    }
    return 0;
}

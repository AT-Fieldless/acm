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
const ull m = 100000007;    //哈希的基数
bool contain(string a,string b)     //a是否在b中出现
{
    int al = a.length(),bl = b.length();
    if (al>bl) {
        return false;
    }
    ull t = 1;      //计算B的al次方
    for (int i = 0; i<al; i++) {
        t *= m;
    }
    //计算a和b长度为al的前缀对应的哈希值
    ull ah = 0,bh = 0;
    for (int i = 0; i<al; i++) {
        ah = ah*m+a[i];
    }
    for (int i = 0; i<al; i++) {
        bh = bh*m+b[i];
    }
    //对b不断右移一位,更新哈希值并判断
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

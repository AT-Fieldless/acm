//
//  main.cpp
//  poj 3421
//
//  Created by apple on 16/7/15.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int>>vec[100000];
void init()
//先把100000以内的所有的数进行分解质因数。就不用为每一组数据再重复计算了。
{
    for (int i = 2; i<=100000; i++) {
        //因为n最大为100000，所以肯定能包含所有情况。
        long long temp = i;
        for (int j = 2; j*j<=temp; j++) {
            if (temp%j == 0) {
                long long c1 = 0;
                while (temp%j == 0) {
                    temp /= j;
                    c1++;
                }
                vec[i].push_back(make_pair(j,c1));
            }
        }
        if (temp > 1) {
            vec[i].push_back(make_pair(temp, 1));
        }
    }
}
int main() {
    int x;
    return 0;
}

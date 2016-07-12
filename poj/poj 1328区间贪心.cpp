//
//  main.cpp
//  poj 1328
//
//  Created by apple on 16/7/12.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-6;
struct node{
    double x;
    double y;
}num[1010],temp[1010];
int n,d;
double jiaodian1(node a){
    return -sqrt(d*d*1.0-a.y*a.y)+1.0*a.x;
}
double jiaodian2(node a){
    return sqrt(d*d*1.0-a.y*a.y)+1.0*a.x;
}
bool cmp(node a,node b){
    return a.x < b.x ;
}
int main() {
    int kase = 1;
    while (cin>>n>>d&&n) {
        int flag = 0;
        for (int i = 0; i<n; i++) {
            cin>>num[i].x>>num[i].y;
            if (num[i].y-d>eps) {
                flag = 1;
            }
        }
        if (flag) {
            printf("Case %d: -1\n",kase++);
            continue;
        }
        else{
            int ans = 1;
            for (int i = 0; i<n; i++) {
                temp[i].x = jiaodian1(num[i]);
                temp[i].y = jiaodian2(num[i]);
            }
            sort(temp, temp+n, cmp);
            double t1 = temp[0].y;
            for (int i = 1; i<n; i++) {
                if (temp[i].x>t1) {
                    ans++;
                    t1 = temp[i].y;
                }
                else if (temp[i].y < t1)
                    t1 = temp[i].y;
            }
            printf("Case %d: %d\n",kase++,ans);
        }
    }
    return 0;
}
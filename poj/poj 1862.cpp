//
//  main.cpp
//  poj 1862
//
//  Created by apple on 16/7/13.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<double,vector<double>,less<double> >q;
double lalala(double a,double b){
    return 2*sqrt(1.0*a*b);
}
int main() {
    int n;
    while (cin>>n) {
        for (int i = 0; i<n; i++) {
            int x;
            cin>>x;
            q.push(x);
        }
        while (q.size()>1) {
            double a = q.top();
            q.pop();
            double b = q.top();
            q.pop();
            double c = lalala(a,b);
            q.push(c);
        }
        printf("%.3lf\n",q.top());
    }
    return 0;
}

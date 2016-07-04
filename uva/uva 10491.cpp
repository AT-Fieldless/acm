//
//  main.cpp
//  uva 10491
//
//  Created by apple on 16/5/3.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    while (cin>>a>>b>>c) {
        double x = b*1.0/(a+b);
        x = x*(b-1)/(a+b-c-1);
        double y = a*1.0/(a+b);
        y = y*(b)/(a+b-c-1);
        x += y;
        printf("%.5lf\n",x);
    }
    return 0;
}
/*
2 1 1
5 3 2
2000 2700 900
*/
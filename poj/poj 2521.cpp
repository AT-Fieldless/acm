//
//  main.cpp
//  poj 2521
//
//  Created by apple on 16/6/30.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n,m,p,c;
    while (cin>>n>>m>>p>>c) {
        if (n == 0&&m == 0&&p == 0&&c == 0) {
            break;
        }
        int s1 = n+c;
        int s2 = m+c-p;
        cout<<s1-s2<<endl;
    }
    return 0;
}

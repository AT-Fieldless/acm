//
//  main.cpp
//  hiho 1163
//
//  Created by apple on 16/7/22.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int m;
    while (cin>>m) {
        int ans = 0;
        for (int i = 0; i<m; i++) {
            int x;
            cin>>x;
            ans ^= x;
        }
        if (ans == 0) {
            cout<<"Bob"<<endl;
        }
        else
            cout<<"Alice"<<endl;
    }
    return 0;
}

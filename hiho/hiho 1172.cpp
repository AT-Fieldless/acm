//
//  main.cpp
//  hiho 1172
//
//  Created by apple on 16/7/22.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
char ch[10100];
int main() {
    int n;
    while (cin>>n) {
        scanf("%s",ch);
        int ans = 0;
        int len = strlen(ch);
        for (int i = 0; i<len; i++) {
            if (ch[i] == 'H') {
                ans ^= i+1;
            }
        }
        if (ans) {
            cout<<"Alice"<<endl;
        }
        else
            cout<<"Bob"<<endl;
    }
    return 0;
}

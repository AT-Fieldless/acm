//
//  main.cpp
//  poj 3185
//
//  Created by apple on 16/8/4.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int num[100];
int tmp[100];
int f[100];
int main(int argc, const char * argv[]) {
    while (cin>>num[0]) {
        tmp[0] = num[0];
        memset(f, 0, sizeof(f));
        for (int i = 1; i<=19; i++) {
            cin>>num[i];
            tmp[i] = num[i];
        }
        int cnt1 = 0;
        for (int i = 0; i<=19; i++) {
            if (num[i]) {
                if (i == 19) {
                    cnt1 = INF;
                    break;
                }
                cnt1++;
                num[i+1]^=1;
                num[i+2]^=1;
            }
        }
        int cnt2 = 0;
        for (int i = 19; i>=0; i--) {
            if (tmp[i]) {
                if (i == 0) {
                    cnt2 = INF;
                    break;
                }
                cnt2++;
                tmp[i-1] ^=1;
                tmp[i-2]^=1;
            }
        }
        cout<<min(cnt1, cnt2)<<endl;
    }
    return 0;
}

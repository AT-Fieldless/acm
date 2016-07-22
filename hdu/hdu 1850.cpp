//
//  main.cpp
//  hdu 1850
//
//  Created by apple on 16/7/22.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
using namespace std;
int num[110];
int main(int argc, const char * argv[]) {
    int m;
    while (cin>>m&&m) {
        int ans = 0;
        for (int i = 0; i<m; i++) {
            cin>>num[i];
            ans ^= num[i];
        }
        if (ans == 0) {
            cout<<0<<endl;
        }
        else{
            int ans = 0;
            for (int i = 0; i<m; i++) {
                int temp = 0;
                for (int j = 0; j<m; j++) {
                    if (i!=j) {
                        temp ^= num[j];
                    }
                }
                if (temp<num[i]) {
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

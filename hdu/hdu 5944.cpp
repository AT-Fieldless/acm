//
//  main.cpp
//  hdu 5944
//
//  Created by apple on 2016/10/30.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char str[10100];
char tmp[10100];
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%s",str);
        int len = strlen(str);
        int ans = 0;
        for (int i = 0; i<len; i++) {
            tmp[i+1] = str[i];
        }
        for (int i = 1; i<=len; i++) {
            if (tmp[i] == 'y') {
                for (int j = 2; i*j*j<=len; j++) {
                    if (tmp[i*j] == 'r'&&tmp[i*j*j] == 'x') {
                        ans++;
                    }
                }
            }
        }
        for (int i = len; i>=0; i--) {
            if (tmp[i] == 'y') {
                for (int j = 2; i/j/j>=1; j++) {
                    if (i%j == 0&&(i/j)%j == 0&&tmp[i/j] == 'r'&&tmp[i/j/j] == 'x') {
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

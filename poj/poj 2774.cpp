//
//  main.cpp
//  poj 2774
//
//  Created by apple on 16/7/25.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int l1,l2;
const int maxn = 2e5+5;
const ull m = 1e8+7;
char s1[maxn];
char s2[maxn];
char temp[maxn];
ull base[maxn];
ull ah[maxn];
bool judge(int len){
    ull temp = 0;
    for (int i = 0; i<len; i++) {
        temp = temp*m+s1[i];
    }
    ah[0] = temp;
    for (int i = 0; i+len<=l1; i++) {
        ah[i+1] = ah[i]*m+s1[i+len]-s1[i]*base[len];
    }
    sort(ah, ah+l1-len+1);
    temp = 0;
    for (int i = 0; i<len; i++) {
        temp = temp*m+s2[i];
    }
    for (int i = 0; i+len<=l2; i++) {
        if (binary_search(ah, ah+l1-len+1, temp)) {
            return 1;
        }
        temp = temp*m+s2[i+len]-s2[i]*base[len];
    }
    return 0;
}
int main() {
    base[0] = 1;
    for (int i = 0; i<maxn; i++) {
        base[i+1] = base[i]*m;
    }
    while (~scanf("%s%s",s1,s2)) {
        l1 = strlen(s1);
        l2 = strlen(s2);
        if (l1<l2) {
            swap(l1, l2);
            strcpy(temp, s1);
            strcpy(s1, s2);
            strcpy(s2, temp);
        }
        int l = 0,r = l2+1,mid;
        while (l<r) {
            mid = (l+r)>>1;
            if (judge(mid)) {
                l = mid+1;
            }
            else
                r = mid;
        }
        printf("%d\n",l-1);
    }
    return 0;
}

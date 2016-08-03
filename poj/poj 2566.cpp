//
//  main.cpp
//  poj 2566
//
//  Created by apple on 16/8/1.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
pair<int, int> p[maxn];
int main() {
    int n,k;
    while (~scanf("%d%d",&n,&k)&&(n||k)) {
        p[0] = make_pair(0, 0);
        for (int i = 1; i<=n; i++) {
            int x;
            scanf("%d",&x);
            p[i].first = p[i-1].first+x;
            p[i].second = i;
        }
        sort(p, p+n+1);
        while (k--) {
            int t;
            scanf("%d",&t);
            int l = 0,r = 1,minn = INF,ans;
            int al = 0,ar = 1;
            while (l<=n&&r<=n&&minn) {
                int temp = p[r].first-p[l].first;
                if (abs(temp-t)<minn) {
                    ans = temp;
                    al = p[l].second;
                    ar = p[r].second;
                    minn = abs(temp-t);
                }
                if (temp<t) {
                    r++;
                }
                else if (temp>t){
                    l++;
                }
                if (r == l) {
                    r++;
                }
            }
            if (al>ar) {
                swap(al, ar);
            }
            printf("%d %d %d\n",ans,al+1,ar);
        }
    }
    return 0;
}

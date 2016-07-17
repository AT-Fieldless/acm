//
//  main.cpp
//  poj 3421
//
//  Created by apple on 16/7/15.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>>vec[1148576];
int vis[1148576];
void init(int n)
{
        long long temp = n;
        for (int j = 2; j*j<=temp; j++) {
            if (temp%j == 0) {
                long long c1 = 0;
                while (temp%j == 0) {
                    temp /= j;
                    c1++;
                }
                vec[n].push_back(make_pair(j,c1));
            }
        }
        if (temp>1) {
            vec[n].push_back(make_pair(temp, 1));
        }
}
long long zuheshu(int n,int m){
    long long a,b,c;
    a = b = c = 1;
    for (int i = 2; i<=n; i++) {
        a *= i;
    }
    for (int i = 2; i<=m; i++) {
        b *= i;
    }
    for (int i = 2; i<=n-m; i++) {
        c *= i;
    }
    return a/(b*c);
}
int main() {
    int x;
    memset(vis, 0, sizeof(vis));
    while (~scanf("%d",&x)) {
        if (!vis[x]) {
            vis[x] = 1;
            init(x);
        }
        long long cnt = 0,temp,sum = 1;
        for (int i = 0; i<vec[x].size(); i++) {
            cnt+=vec[x][i].second;
        }
        if (vec[x].size() == 1) {
            cout<<cnt<<' '<<1<<endl;
            continue;
        }
        if (x == 1) {
            cout<<1<<' '<<1<<endl;
            continue;
        }
        temp = cnt;
        for (int i = 0; i<vec[x].size()-1; i++) {
            sum *= zuheshu(temp, vec[x][i].second);
            temp -= vec[x][i].second;
        }
        cout<<cnt<<' '<<sum<<endl;
    }
    return 0;
}

//
//  main.cpp
//  poj 3614
//
//  Created by apple on 16/7/18.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >que;
typedef pair<int, int> P;
P spf[2510],cows[2510];
int main() {
    int c,l;
    while (cin>>c>>l) {
        for (int i = 0; i<c; i++) {
            cin>>cows[i].first>>cows[i].second;
        }
        for (int i = 0; i<l; i++) {
            cin>>spf[i].first>>spf[i].second;
        }
        int j = 0,ans = 0;
        sort(spf, spf+l);
        sort(cows, cows+c);
        for (int i = 0; i<l; i++) {
            while (j<c&&cows[j].first<=spf[i].first) {
                que.push(cows[j].second);
                j++;
            }
            while (spf[i].second&&que.size()) {
                int temp = que.top();
                if (temp>=spf[i].first) {
                    spf[i].second--;
                    ans++;
                }
                que.pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

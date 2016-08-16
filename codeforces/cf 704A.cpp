//
//  main.cpp
//  cf 704A
//
//  Created by apple on 16/8/10.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 3e5+10;
queue<int>q1[maxn];
queue<pair<int, int>>q2;
int vis[maxn];
int main(int argc, const char * argv[]) {
    int n,q;
    while (~scanf("%d%d",&n,&q)) {
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 0; i<q; i++) {
            int t,x;
            scanf("%d%d",&t,&x);
            if (t == 1) {
                ans++;
                q1[x].push(cnt);
                q2.push(make_pair(cnt++, x));
                cout<<ans<<endl;
            }
            if (t == 2) {
                while (q1[x].size()) {
                    ans--;
                    int top = q1[x].front();
                    vis[top]=1;
                    q1[x].pop();
                }
                cout<<ans<<endl;
            }
            if (t == 3) {
                while (q2.size()&&q2.front().first<x) {
                    //cout<<q2.front().first<<' ';
                    int temp = q2.front().second;
                    if (!vis[q2.front().first]) {
                        vis[q2.front().first] = 1;
                        q1[temp].pop();
                        ans--;
                    }
                    q2.pop();
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}

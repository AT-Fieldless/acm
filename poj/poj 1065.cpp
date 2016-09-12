//
//  main.cpp
//  poj 1065
//
//  Created by apple on 16/9/12.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5010;
int l[maxn];
int w[maxn];
int r[maxn];
int vis[maxn];
bool cmp(int x,int y){
    if (l[x] == l[y]) {
        return w[x]<w[y];
    }
    return l[x]<l[y];
}
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(vis, 0, sizeof(vis));
        int n;
        scanf("%d",&n);
        for (int i = 0; i<n; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            l[i] = x;
            w[i] = y;
            r[i] = i;
        }
        sort(r, r+n, cmp);
        int tw = 0,ans = 0;
        int cnt = 0;
        for (int i = 0; i<n; i++) {
            if (cnt==n) {
                break;
            }
            if (vis[i]) {
                continue;
            }
            vis[i] = 1;
            tw = w[r[i]];
            ans++;
            for(int j = i+1; j<n; j++) {
                //cout<<w[j]<<' ';
                if (w[r[j]]>=tw&&!vis[j]) {
                  //  cout<<j<<' ';
                    cnt++;
                    vis[j] = 1;
                    tw = w[r[j]];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

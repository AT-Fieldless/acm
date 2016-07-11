//
//  main.cpp
//  poj 1979
//
//  Created by apple on 16/7/11.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
using namespace std;
char mp[22][22];
int vis[22][22];
int ans,w,h;
int d1[4] = {-1,0,1,0};
int d2[4] = {0,1,0,-1};
void dfs(int a,int b){
    if (mp[a][b] == '.') {
        ans++;
    }
    else if (mp[a][b] == '#') {
        return;
    }
    for (int i = 0; i<4; i++) {
        int tx = a+d1[i];
        int ty = b+d2[i];
        if (!vis[tx][ty]&&tx<h&&ty<w&&tx>=0&&ty>=0) {
            vis[tx][ty] = 1;
            dfs(tx, ty);
        }
    }
}
int main() {
    while (cin>>w>>h&&w) {
        memset(vis, 0, sizeof(vis));
        ans = 1;
        for (int i = 0; i<h; i++) {
            scanf("%s",mp[i]);
        }
        int x,y;
        for (int i = 0; i<h; i++){
            for (int j = 0; j<w; j++) {
                if (mp[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        dfs(x, y);
        cout<<ans<<endl;
    }
    return 0;
}

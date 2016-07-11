//
//  main.cpp
//  poj 3669
//
//  Created by apple on 16/7/11.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define judge(x,y) x>=0&&x<=305&&y>=0&&y<=305
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int mt[310][310];
int vis[310][310];
int dis[310][310];
int bfs(){
    if (mt[0][0] == 0) {
        return -1;
    }
    queue<P>que;
    for (int i = 0; i<=305; i++) {
        for (int j = 0; j<=305; j++) {
            dis[i][j] = INF;
        }
    }
    que.push(P(0,0));
    dis[0][0] = 0;
    while (que.size()) {
        P p = que.front();
        que.pop();
        if (mt[p.first][p.second] == -1) {
            return dis[p.first][p.second];
        }
       // cout<<p.first<<' '<<p.second<<endl;
        for (int i = 0; i<4; i++) {
            int tx = p.first+dx[i];
            int ty = p.second+dy[i];
            if (judge(tx, ty)&&dis[tx][ty] == INF&&(mt[tx][ty]>dis[p.first][p.second]+1||mt[tx][ty] == -1)) {
                que.push(P(tx,ty));
                dis[tx][ty] = dis[p.first][p.second]+1;
            }
        }
    }
    return -1;
}
int main() {
    int m;
    while (cin>>m) {
        memset(vis, 0, sizeof(vis));
        memset(mt, -1, sizeof(mt));
        for (int i = 0; i<m; i++) {
            int x,y,t;
            cin>>x>>y>>t;
            if (mt[y][x]==-1) {
                mt[y][x] = t;
            }
            else
                mt[y][x] = min(mt[y][x], t);
            for (int i = 0; i<4; i++) {
                int tx = y+dx[i];
                int ty = x+dy[i];
                if (judge(tx, ty)) {
                    if (mt[tx][ty] == -1) {
                        mt[tx][ty] = t;
                    }
                    else
                        mt[tx][ty] = min(mt[tx][ty], t);
                }
            }
        }
        cout<<bfs()<<endl;
    }
    return 0;
}

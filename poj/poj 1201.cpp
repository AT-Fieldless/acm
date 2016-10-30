//
//  main.cpp
//  poj 1201
//
//  Created by apple on 2016/10/30.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int MAXN = 100010;
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].push_back(make_pair(v,d));
}
void init(int n){
    for(int i=0;i<n;i++)G[i].clear();
}
int vis[MAXN];
int dis[MAXN];
int ma,mi;
void spfa(int s,int n){
    for(int i = mi;i<=ma;i++)dis[i] = (i == s ? 0 : -INF);
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
      //  cout<<x<<endl;
        q.pop();
        vis[x] = 0;
        for(int i = 0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
          //  cout<<y<<' ';
            if(dis[y] < dis[x] + d){
                dis[y] = dis[x] + d;
                //cout<<dis[y]<<endl;
                if(!vis[y]){
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        init(50001);
        int u,v,d;
        ma = 0;
        mi = INF;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&u,&v,&d);
            add_edge(u-1,v,d);
            ma = max(v, ma);
            mi = min(mi, u-1);
        }
        for (int i = mi; i<ma; i++) {
            add_edge(i, i+1, 0);
            add_edge(i+1, i, -1);
        }
        spfa(mi, ma+1);
        printf("%d\n",dis[ma]);
    }
}

/*
 8
 4 9 5
 8 9 1
 5 6 1
 3 9 5
 7 9 1
 2 5 2
 3 4 1
 2 5 3
*/

//
//  main.cpp
//  poj 3159
//
//  Created by apple on 2016/10/29.
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

const int MAXN = 100010;
struct qnode{
    int v,c;
    bool operator <(const qnode &r) const{
        return c>r.c;
    }
};
struct Edge{
    int v,cost;
    int next;
};
Edge edge[200000];
int tot;
int head[MAXN];
int vis[MAXN];
int dis[MAXN];
void add_edge(int u,int v,int w){
    edge[tot].v = v;
    edge[tot].cost = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dijkstra(int s,int n){
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<qnode>q;
    qnode temp;
    temp.v = 0;
    temp.c = 0;
    q.push(temp);
    while(!q.empty()){
        //cout<<"lala";
        qnode p = q.top();
        int x = p.v;
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i=head[x];i!=-1;i = edge[i].next){
            int y = edge[i].v;
            int d = edge[i].cost;
            //cout<<y<<endl;
            if(!vis[y]&&dis[x] + d < dis[y]){
                dis[y] = dis[x] + d;
                temp.v = y;
                temp.c = dis[y];
                q.push(temp);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        tot = 0;
        memset(head, -1, sizeof(head));
        int u,v,d;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&d);
            u--;v--;
            add_edge(u,v,d);
        }
        dijkstra(0,n);
        int ans = dis[n-1];
        if(ans == INF)ans = -1;
        
        cout<<ans<<endl;
    }
}

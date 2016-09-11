//
//  main.cpp
//  hiho 1369
//
//  Created by apple on 16/9/11.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
//复杂度O(F|E|)
//用于表示变得结构体（终点、容量、反向边）
struct edge{int to,cap,rev;};

vector<edge> G[maxn];//图的邻接表表示
bool used[maxn];//DFS中用到的访问标记
//向图中增加一条从s到t容量为cap的边
void add_edge(int from,int to,int cap){
    edge e1,e2;
    e1.to = to;e1.cap = cap;e1.rev = G[to].size();
    e2.to = from;e2.cap = 0;e2.rev = G[from].size();
    G[from].push_back(e1);
    G[to].push_back(e2);
}
//通过dfs寻找增广路
int dfs(int v,int t,int f){
    if (v == t) {
        return f;
    }
    used[v] = true;
    for (int i = 0; i<G[v].size(); i++) {
        edge &e = G[v][i];
        if (!used[e.to]&&e.cap>0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d>0) {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
//求解s到t的最大流
int max_flow(int s,int t){
    int flow = 0;
    for (; ; ) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0) {
            return flow;
        }
        flow += f;
    }
}
void init(int n){
    for (int i = 0; i<n; i++) {
        G[i].clear();
    }
}
int main(int argc, const char * argv[]) {
    int n,m;
    while (cin>>n>>m) {
        int s = 1,t = n;
        init(t+1);
        for (int i = 0; i<m; i++) {
            int u,v,c;
            cin>>u>>v>>c;
            add_edge(u, v, c);
        }
        cout<<max_flow(s,t)<<endl;
    }
    return 0;
}

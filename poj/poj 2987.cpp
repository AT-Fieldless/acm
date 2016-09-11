//
//  main.cpp
//  poj 1150
//
//  Created by apple on 16/9/8.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAX_V = 1e5+10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct edge{long long to,cap,rev;};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from,int to,int cap){
    long long a = G[to].size();
    long long b = G[from].size();
    G[from].push_back((edge){to,cap,a});
    G[to].push_back((edge){from,0,b});
}
void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i<G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap>0&&level[e.to]<0) {
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}
long long dfs(int v,int t,long long f){
    if (v == t) {
        return f;
    }
    for (int &i = iter[v]; i<G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap>0&&level[v]<level[e.to]) {
            long long d = dfs(e.to, t, min(f, e.cap));
            if (d>0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
long long max_flow(int s,int t){
    long long flow = 0;
    for (; ; ) {
        bfs(s);
        if (level[t]<0) {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        long long f;
        while ((f = dfs(s, t, INF))>0) {
            flow += f;
        }
    }
}
void init(int n){
    for (int i = 0; i<n; i++) {
        G[i].clear();
    }
}
int vised[MAX_V];
int sum;
void solve(int u){
    vised[u] = 1;
    sum++;
    for (int i = 0; i<G[u].size(); i++) {
        edge &e = G[u][i];
        if (!vised[e.to]&&e.cap>0) {
            solve(e.to);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    sum = 0;
    long long s = 0,t = n+1,ans = 0;
    for (int i = 1; i<=n; i++) {
        int x;
        scanf("%d",&x);
        if (x>0) {
            ans += x;
            add_edge(s, i, x);
        }
        else
            add_edge(i, t, -x);
    }
    for (int i = 0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(a, b, INF);
    }
    ans -= max_flow(s, t);
    solve(s);
    sum--;
    printf("%d %lld\n",sum,ans);
    return 0;
}
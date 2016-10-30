//Dinic 复杂度O(|E||V|*|V|)

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAX_V = 5100;
const int INF = 0x3f3f3f3f;
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
int level[MAX_V];           //顶点到源点的距离标号
int iter[MAX_V];            //当前弧，在其之前的边已经没有用了
void add_edge(int from,int to,int cap){
    int a = G[to].size();
    int b = G[from].size();
    G[from].push_back((edge){to,cap,a});
    G[to].push_back((edge){from,0,b-1});
}
void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++i)
        {
            edge& e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

// 通过DFS寻找增广路
int dfs(int v, int t, int f)
{
    if (v == t)
    {
        return f;
    }
    for (int& i = iter[v]; i < G[v].size(); ++i)
    {
        edge& e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to])
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    
    return 0;
}

// 求解从s到t的最大流
int max_flow(int s, int t)
{
    int flow = 0;
    for (;;)
    {
        bfs(s);
        if (level[t] < 0) 
        {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, 0x3f3f3f3f)) > 0)
        {
            flow += f;
        }
    }
}
void init(int n){
    for (int i = 0; i<n; i++) {
        G[i].clear();
    }
}






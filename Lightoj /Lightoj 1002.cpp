//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
int maps[510][510];
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
}
void init(int n){
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            maps[i][j] = INF;
        }
    }
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
int vis[MAXN];
int dis[MAXN];
void dijkstra(int s,int n){
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<PII,VII,greater<PII> >q;
    q.push(MP(dis[s],s));
    while(!q.empty()){
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            int temp = max(d, dis[x]);
            if(!vis[y]&&temp<dis[y]){
                dis[y] = temp;
                q.push(MP(dis[y],y));
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int t,kase = 1;
    scanf("%d",&t);
    while (t--) {
        init(510);
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i<m; i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            maps[u][v] = min(maps[u][v], w);
            maps[v][u] = maps[u][v];
        }
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (maps[i][j]!=INF) {
                    add_edge(i, j, maps[i][j]);
                }
            }
        }
        int t;
        scanf("%d",&t);
        dijkstra(t, n);
        printf("Case %d:\n",kase++);
        for (int i = 0; i<n; i++) {
            if (i == t) {
                printf("0\n");
                continue;
            }
            if (dis[i] == INF) {
                printf("Impossible\n");
            }
            else{
                printf("%d\n",dis[i]);
            }
        }
    }
    return 0;
}

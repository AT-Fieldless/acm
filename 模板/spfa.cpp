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
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].push_back(make_pair(v,d));
}
void init(int n){
    for(int i=0;i<n;i++)G[i].clear();
}
int vis[MAXN];
int dis[MAXN];
void spfa(int s,int n){
    for(int i = 0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = 0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(dis[y] > dis[x] + d){
                dis[y] = dis[x] + d;
                if(!vis[y]){
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin>>n>>m){
        init(n);
        int u,v,d;
        for(int i=0;i<m;i++){
            cin>>u>>v>>d;
            //u--;v--;
            add_edge(u,v,d);
            add_edge(v,u,d);
        }
        int s,t;
        cin>>s>>t;
        spfa(s,n);
        int ans = dis[t];
        if(ans == INF)ans = -1;

        cout<<ans<<endl;
    }
}

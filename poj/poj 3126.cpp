#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
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
int cnt = 0;
const int MAXN = 100010;
vector<PII> G[MAXN];
bool is_prime[1000000];
bool vis1[1000000];
int id[100000];
void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
}
void init(int n){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
void lalala()
{
    memset(is_prime, 0, sizeof(is_prime));
    memset(vis1, 0, sizeof(vis1));
    for (int i = 2; i<=10000; i++) {
        if (!vis1[i]) {
            is_prime[i] = 1;
            for (int j = 2*i; j<=10000; j += i) {
                is_prime[j] = 0;
                vis1[j] = 1;
            }
        }
    }
    for (int i = 1000; i<=9999; i++) {
        if (is_prime[i]) {
            id[i] = cnt++;
        }
    }
    for (int i = 1000; i<=9999; i++) {
        if (is_prime[i]) {
            int a = i%10;
            int b = i/10%10;
            int c = i/100%10;
            int d = i/1000;
            int t1 = d*1000+c*100+b*10;
            int t2 = d*1000+c*100+a;
            int t3 = d*1000+b*10+a;
            int t4 = c*100+b*10+a;
            for (int j = 0; j<=9; j++) {
                if (is_prime[t1+j]&&(t1+j)!=i) {
                    //cout<<t1+j<<' '<<i<<endl;
                    add_edge(id[t1+j], id[i], 1);
                }
            }
            for (int j = 0; j<=9; j++) {
                if (is_prime[t2+j*10]&&(t2+j*10)!=i) {
                    add_edge(id[t2+j*10], id[i], 1);
                }
            }
            for (int j = 0; j<=9; j++) {
                if (is_prime[t3+j*100]&&(t3+j*100)!=i) {
                    add_edge(id[t3+j*100], id[i], 1);
                }
            }
            for (int j = 1; j<=9; j++) {
                if (is_prime[t4+j*1000]&&(t4+j*1000)!=i) {
                    add_edge(id[t4+j*1000], id[i], 1);
                }
            }
        }
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
            if(!vis[y]&&dis[x] + d < dis[y]){
                dis[y] = dis[x] + d;
                q.push(MP(dis[y],y));
            }
        }
    }
}
int main()
{
    int n;
    init(10000);
    lalala();
    
    while (~scanf("%d",&n)) {
        while (n--) {
            int a,b;
            cin>>a>>b;
            dijkstra(id[a], cnt);
            if (vis[id[b]]) {
                cout<<dis[id[b]]<<endl;
            }
            else
                cout<<"Impossible"<<endl;
        }
    }
    
}
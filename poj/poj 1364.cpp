//
//  main.cpp
//  poj 1364
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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int MAXN = 100010;
vector<PII> G[MAXN];
int vis[MAXN];
int dis[MAXN];
int cnt[MAXN];
void add_edge(int u,int v,int d){
    G[u].push_back(make_pair(v,d));
}
void init(int n){
    for(int i=0;i<n;i++)G[i].clear();
    memset(cnt, 0, sizeof(cnt));
}
int spfa(int s,int n){
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
                    if (++cnt[y]>n) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin>>n&&n){
        cin>>m;
        init(n+2);
        int u,v,k;
        char o[10];
        for(int i=0;i<m;i++){
            cin>>u>>v>>o>>k;
            if (o[0] == 'g') {
                add_edge(u+v, u-1, -k-1);
            }
            else
                add_edge(u-1, u+v, k-1);
        }
        for (int i = 0; i<=n; i++) {
            add_edge(n+1, i, 0);
        }
        if (spfa(n+1, n+2)) {
            cout<<"lamentable kingdom"<<endl;
        }
        else
            cout<<"successful conspiracy"<<endl;
        //int s,t;
        //cin>>s>>t;
        //spfa(s,n);
      //  int ans = dis[t];
        //if(ans == INF)ans = -1;
        
        //cout<<ans<<endl;
    }
}


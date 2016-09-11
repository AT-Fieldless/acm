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
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
#define maxn 10
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;


int Ans[maxn];              //记录拓扑排序的答案
int G[maxn][maxn];
int n,m;
int deg[maxn];              //入度

bool toposort(int n){       //返回是否存在拓扑排序
	int t=0;
	queue<int >que;
	for(int i=0;i<n;++i){
		if(deg[i]==0)que.push(i);
	}
	while(!que.empty()){
		int v=que.front();que.pop();
		Ans[t++]=v+1;
		for(int i=0;i<n;++i){
			if(G[v][i]==1){
				deg[i]--;
				if(deg[i]==0)que.push(i);
			}
		}
	}
	if(t<n)return false;
	return true;
}
int main()
{
	cin>>n>>m;
	memset(G,0,sizeof(G));
	memset(deg,0,sizeof(deg));
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a][b]=1;
		deg[b]++;
	}
	if(toposort(n)){
	 	for(int i=0;i<n;++i){
		 	cout<<Ans[i]<<" ";
		 }
		 cout<<endl;
	}
	return 0;
}













#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int>G[1100];
int iscut[1100];
int low[1100];
int pre[1100];
int dfs_clock;
//pre要初始化为0
int dfs(int u,int fa){          //u在dfs树中的父结点是fa
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;              //子结点数目
    for (int i = 0; i<G[u].size(); i++) {
        int v = G[u][i];
        if (!pre[v]) {          //没有访问过v
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu,lowv);        //用后代的low函数更新u的low函数
            if (lowv>=pre[u]) {
                iscut[u] = true;
            }
        }
        else if (pre[v]<pre[u]&&v!=fa){
            lowu = min(lowu, pre[v]);
        }
    }
    if (fa<0&&child == 1) {
        iscut[u] = 0;
    }
    low[u] = lowu;
    return lowu;
}

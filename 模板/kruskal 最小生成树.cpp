
#include <iostream>
using namespace std;
const int maxn = 1e4;
int n,m;
//假设第i条边的两个端点序号和权值分别保存在u[i],v[i]和w[i]中，而排序后第i小的边的序号保存在r[i]中，p[i]表示父节点
int w[maxn];
int u[maxn];
int v[maxn];
int r[maxn];
int p[maxn];
int cmp(const int i,const int j){
    return w[i]<w[j];
}
int Find(int x){
    return p[x] == x?x:p[x] = Find(p[x]);
}
int Kruskal(){
    int ans = 0;
    for (int i = 0; i<n; i++) {
        p[i] = i;
    }
    for (int i = 0; i<m; i++) {
        r[i] = i;
    }
    sort(r, r+m, cmp);
    for (int i = 0; i<m; i++) {
        int e = r[i];
        int x = Find(u[e]);
        int y = Find(v[e]);
        if (x!=y) {
            ans += w[e];
            p[x] = y;
        }
    }
    return ans;
}


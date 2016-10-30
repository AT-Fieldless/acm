//  poj 2914



//Stoer-Wagner算法
//无向图全局最小割，用求prim类似方法o（n^3)
/*
 1.min=MAXINT，固定一个顶点P
 2.从点P用类似prim的s算法扩展出“最大生成树”，记录最后扩展的顶点和最后扩展的边
 3.计算最后扩展到的顶点的切割值（即与此顶点相连的所有边权和），若比min小更新min
 4.合并最后扩展的那条边的两个端点为一个顶点（当然他们的边也要合并，这个好理解吧？）
 5.转到2，合并N-1次后结束
 6.min即为所求，输出min
 prim本身复杂度是O(n^2)，合并n-1次，算法复杂度即为O(n^3)
 如果在prim中加堆优化，复杂度会降为O((n^2)logn)
 */
#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int mat[600][600];
int res;

void Mincut(int n) {
    int node[600], dist[600];
    bool visit[600];
    int i, prev, maxj, j, k;
    for (i = 0; i < n; i++)
        node[i] = i;
    while (n > 1) {
        int maxj = 1;
        for (i = 1; i < n; i++) { //初始化到已圈集合的割大小
            dist[node[i]] = mat[node[0]][node[i]];  //默认把0加入到已圈集合中
            if (dist[node[i]] > dist[node[maxj]])
                maxj = i;           //找下一个dist最大的点
        }
        prev = 0;
        memset(visit, false, sizeof (visit));
        visit[node[0]] = true;
        for (i = 1; i < n; i++) {
            if (i == n - 1) { //只剩最后一个没加入集合的点，更新最小割
                res = min(res, dist[node[maxj]]);
                for (k = 0; k < n; k++) //合并最后一个点以及推出它的集合中的点
                    mat[node[k]][node[prev]] = (mat[node[prev]][node[k]] += mat[node[k]][node[maxj]]);
                node[maxj] = node[--n]; //缩点后的图
            }
            visit[node[maxj]] = true;
            prev = maxj;
            maxj = -1;
            for (j = 1; j < n; j++)
                if (!visit[node[j]]) { //将上次求的maxj加入集合，合并与它相邻的边到割集
                    dist[node[j]] += mat[node[prev]][node[j]];
                    if (maxj == -1 || dist[node[maxj]] < dist[node[j]])
                        maxj = j;
                }
        }
        
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    while (cin>>n>>m) {
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i<m; i++) {
            int a,b,c;
            cin>>a>>b>>c;
            mat[a][b] += c;
            mat[b][a] += c;
        }
        res = INF;
        Mincut(n);
        cout<<res<<endl;
    }
}




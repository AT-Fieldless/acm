#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<string>
#include<stack>
#include<cmath>
#include<cctype>
#include<iostream>
#include<set>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define MAXN 1000000007
#define judge(x,y) x>=0&&x<h&&y>=0&&y<w&&map[x][y]!=1
int map[30][30];
int w,h,sx,sy,ex,ey,step,steps,fin;
int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct node
{
    int x;int y;
    int step;
};

void DFS(int x,int y)
{
    int i;if(step>10)return;
    for(i=0;i<4;i++)
    {
        int nx,ny,ok;
        ok=0;
        nx=x+d[i][0],ny=y+d[i][1];
        while(judge(nx,ny))
        {
            ok=1;
            if(nx==ex&&ny==ey)if(step<steps)steps=step;
            nx+=d[i][0],ny+=d[i][1];
        }
        if(map[nx][ny]==1&&ok)
        {
            step++;map[nx][ny]=0;
            DFS(nx-d[i][0],ny-d[i][1]);
            step--;map[nx][ny]=1;
        }
    }
}
int main()
{
    while(~scanf("%d%d",&w,&h)&&w&&h)
    {
        mem(map);
        int i,j;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==2)sx=i,sy=j;
                if(map[i][j]==3)ex=i,ey=j;
            }
        }
        steps=1000000;
        step=1;
        DFS(sx,sy);
        printf("%d\n",steps>10?-1:steps);
    }
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_N 100000 * 2 + 16
int parent[MAX_N];
int height[MAX_N];

void init(const int& n)
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
        height[i] = 0;
    }
}

int find(const int& x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }
    
    if (height[x] < height[y])
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
        if (height[x] == height[y])
        {
            ++height[x];
        }
    }
}

bool same(const int& x, const int& y)
{
    return find(x) == find(y);
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        init(2*n);
        for (int i = 0; i<m; i++) {
            char ch;
            int a,b;
            getchar();
            scanf("%c%d%d",&ch,&a,&b);
            if (ch == 'A') {
                if (same(a, b)) {
                    cout<<"In the same gang."<<endl;
                }
                else if (same(a, b+n)){
                    cout<<"In different gangs."<<endl;
                }
                else{
                    cout<<"Not sure yet."<<endl;
                }
            }
            else{
                unite(a, b+n);
                unite(a+n, b);
            }
        }
    }
    return 0;
}
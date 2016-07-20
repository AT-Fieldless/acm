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
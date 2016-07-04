#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Trie
{
    int ch[1010000][26];
    int val[1010000];
    int sz;             //结点总数
    Trie(){sz = 1;memset(ch[0], 0, sizeof(ch[0]));}     //初始时只有一个根节点
    int idx(char c){return c-'a';}      //字符c的编号
    void insert(char* s,int v)    //插入字符串s,附加信息为v。注意v必须非0，因为0代表“本节点不是单词结点”
    {
        int u = 0,n = strlen(s);
        for(int i = 0;i<n;i++)
        {
            int c = idx(s[i]);
            if(!ch[u][c])       //结点不存在
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];       //往下走
        }
        val[u] = v;
    }
    int query(char* v)      //进行查询操作
    {
        //puts(v);
        int u = 0,n = strlen(v);
        for(int i = 0;i<n;i++)
        {
            //cout<<u<<' ';
            int c = idx(v[i]);
            if(!ch[u][c])
            {
                return -1;
            }
            u = ch[u][c];
        }
        return u;
    }
};
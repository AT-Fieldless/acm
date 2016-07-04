#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Trie
{
    int ch[1010000][26];
    char val[1010000][12];
    int sz;             //结点总数
    Trie(){sz = 1;memset(ch[0], 0, sizeof(ch[0]));}     //初始时只有一个根节点
    int idx(char c){return c-'a';}      //字符c的编号
    void insert(char* s,char* v)    //插入字符串s,附加信息为v。注意v必须非0，因为0代表“本节点不是单词结点”
    {
        //puts(s);
        //puts(v);
        int u = 0,n = strlen(s),len = strlen(v);
        for(int i = 0;i<n;i++)
        {
            int c = idx(s[i]);
            //cout<<u<<' ';
            if(!ch[u][c])       //结点不存在
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz][0] = 'e';
                val[sz][1] = 'h';
                ch[u][c] = sz++;
            }
            u = ch[u][c];       //往下走
        }
        for(int j = 0;j<len;j++)
        val[u][j] = v[j];
        //puts(val[sz]);
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
}xixi;
int main()
{
    char english[12];
    char ch[12];
    while (true) {
        char a;
        a = getchar();
        if (a == '\n') {
            break;
        }
        english[0] = a;
        int i = 1;
        while (true) {
            a = getchar();
            if (a == ' ') {
                english[i] = '\0';
                break;
            }
            else
            english[i++] = a;
        }
        scanf("%s",ch);
        getchar();
        xixi.insert(ch,english);
    }
    while (scanf("%s",ch)!=EOF) {
        //puts(ch);
        int ans = xixi.query(ch);
        if (ans == -1) {
            cout<<"eh"<<endl;
        }
        else
        cout<<xixi.val[ans]<<endl;
    }
}
//
//  main.cpp
//  poj2513
//
//  Created by apple on 16/4/30.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;
int sz = 0;
int num[550100];
int val[550100];
int size = 1;
struct Trie
{
    int ch[550100][26];
    Trie(){sz = 1;memset(ch[0], 0, sizeof(ch[0]));}     //初始时只有一个根节点
    int idx(char c){return c-'a';}      //字符c的编号
   int insert(char* s)    //插入字符串s,附加信息为v。注意v必须非0，因为0代表“本节点不是单词结点”
    {
        //puts(s);
        //puts(v);
        int u = 0,n = strlen(s),c;
        for(int i = 0;i<n;i++)
        {
            c = idx(s[i]);
            //cout<<u<<' ';
            if(!ch[u][c])       //结点不存在
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                ch[u][c] = sz++;
                num[sz] = 0;
            }
            u = ch[u][c];       //往下走
        }
        //cout<<endl;
        if(!num[u])
            num[u] = size++;
        //cout<<num[u]<<endl;
        return num[u];
    }
}xixi;
int pre[550100];
int find(int x)
{
    int r = x;
    while (pre[r]!= r)
        r=pre[r];
    int i = x,j;
    while(i != r)
    {
        j = pre[i]; // 在改变上级之前用临时变量  j 记录下他的值
        pre[i] = r ; //把上级改为根节点
        i = j;
    }
    return r ;
}
void join(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
    pre[fx]=fy;
}
int main() {
    char a[12];
    char b[12];
    for (int i = 0; i<550000; i++) {
        pre[i] = i;
    }
    memset(val, 0, sizeof(val));
    memset(num, 0, sizeof(num));
    while (scanf("%s",a)!=EOF) {
        int n = xixi.insert(a);
        val[n]++;
        scanf("%s",b);
        int m = xixi.insert(b);
        val[m]++;
        join(n, m);
    }
    //cout<<"lala";
    int s1 = 0,s2 = 0;
    for (int i = 1; i<size; i++) {
        //cout<<val[i]<<endl;
        if (pre[i] == i) {
            s1++;
        }
        if (val[i]%2) {
            s2++;
        }
    }
    if (s1 <= 1&&(s2 == 0||s2 == 2)) {
        printf("Possible\n");
    }
    else
        printf("Impossible\n");
    return 0;
}

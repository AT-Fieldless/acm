//查询树中不超过k的最大数字
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
struct node
{
    node* ch[2];            //左右子树
    int r;                  //优先级。数值越大，优先级越高
    int v;                  //值
    node(int v){
        this->v = v;
        ch[0] = ch[1] = NULL;
        r = rand();         //优先级是随机生成的
    }
    int cmp(int x) const{
        if(x == v) return -1;
        return x < v ? 0 : 1;
    }
};
void rotate(node* &o,int d){            //d=0代表左旋,d=1代表右旋
    node* k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o = k;
}
void insert(node* &o,int x){       //在以o为根的子树中插入键值,修改o
    if(o == NULL){
        o = new node(x);
    }
    else{
        //cout<<o->v<<' ';
        int d = o->cmp(x);
        if(d == -1)             //相等不插
            return;
        insert(o->ch[d],x);
        if(o->ch[d]->r > o->r)          //权值大，进行旋转
            rotate(o,d^1);
    }
    //cout<<o->v<<' ';
}
void query(node* o,node* pre,int x,int& ans){
    if(o == NULL){
        return ;
    }
    if(o->v <= x)
    {
        ans = max(ans,o->v);
    }
    int d = o->cmp(x);
    if(d == -1)
        return;
    query(o->ch[d],o,x,ans);
}
void zhongxu(node* o)
{
    if(o == NULL)
        return;
    zhongxu(o->ch[0]);
    cout<<o->v<<' ';
    zhongxu(o->ch[1]);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        node* root = NULL;
        int Min = INF;
        for(int i = 0;i<n;i++)
        {
            char c;int k;
            getchar();
            scanf("%c %d",&c,&k);
            Min = min(Min,k);
            if(c == 'I')
            {
                insert(root,k);
            }
            else
            {
                int ans = Min;
                query(root,root,k,ans);
                printf("%d\n",ans);
            }
            //zhongxu(root);
        }
        
    }
}

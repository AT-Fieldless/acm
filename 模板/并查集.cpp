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
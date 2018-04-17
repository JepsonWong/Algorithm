/*
https://blog.csdn.net/hg_zhh/article/details/68943680
感觉和BFS两种方法有一种是错的。
*/
#include<iostream>
using namespace std;
int vn[2005][2];
int fa[1005];
int n,m,u,v;
int find(int a)
{
    if (fa[a]==a)
        return a;
    return fa[a]=find(fa[a]);
}
bool islink(int out)
{
    for (int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for (int i=1;i<=m;i++)
    {
        if (vn[i][0]==out||vn[i][1]==out)
        {
            continue;
        }
        int a=find(vn[i][0]);
        int b=find(vn[i][1]);
        if (a<b)
            fa[b]=a;
        else if (a==b)
            ;
        else
            fa[a]=b;

    }
    int a=find(u);
    int b=find(v);
    if (a==b)
        return 1;
    return 0;
}


int main()
{
    int total=0;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        vn[i][0]=a;
        vn[i][1]=b;
    }
    cin>>u>>v;
    if (!islink(-1))//当去掉的节点为-1时，相当于不去掉节点
    {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        if(i==u||i==v) ////如果是被询问的点,跳过,无需遍历,此处是最关键的部分
        {
            continue;
        }
        if (!islink(i))//去掉节点i，看u，v是否还是联通的，
            total++;
    }
    cout << "total: ";
    cout<<total<<endl;
    return 0;
}

/*
https://blog.csdn.net/hg_zhh/article/details/68943680
感觉和并查集两种方法有一个是错的
*/
#include<iostream>
#include<queue>
using namespace std;
int vn[1005][1005];
int dist[1005];//存储当前节点到起始节点的最短距离
int n;
int m;
int u,v,a,b,temp;
void bfs()
{
    queue <int> q;
    q.push(u);
    dist[u]=0;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for (int i=1;i<=n;i++)
        {
            if (vn[temp][i]==1&&dist[i]==10000)
            {
                dist[i]=dist[temp]+1;
                q.push(i);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>a>>b;
        vn[a][b]=1;
        vn[b][a]=1;
    }
    for (int i=0;i<=n;i++)
    {
        dist[i]=10000;
    }
    cin>>u>>v;//u起始节点，v结束节点
    bfs();
    int num=dist[v]-dist[u]-1;

    for (int  i=1;i<=n;i++)
        cout<<dist[i]<<endl;
    cout << "num: ";
    if (num>n)
        cout<<"-1";
    else
        cout<<num<<endl;

    return 0;
}

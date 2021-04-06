#include<bits/stdc++.h>
using namespace std;
int a[3010][3010];
int d[3010];///d[i]表示起点1到节点i的最短路径长度
int n,m;
bool vis[3010];
void dijkstra()
{
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[1]=0;
    for(int i=1;i<n;++i)///重复进行n-1次
    {
        int x=0;///找到离起点距离最小值的点
        for(int j=1;j<=n;++j)
        {
            if(vis[j]==0&&(x==0||d[j]<d[x]))
                x = j;
        }
        vis[x]=1;
        for(int y=1;y<=n;++y)
        {
            d[y]=min(d[y],d[x]+a[x][y]);
        }
    }
}
int main()
{
    cin>>n>>m;
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=n;++i)
        a[i][i]=0;
    for(int i=1;i<=m;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    dijkstra();
    for(int i=1;i<=n;++i)
        cout<<d[i]<<endl;
}

#include<bits/stdc++.h>
using namespace std;
const int N=100010;
const int M=1000010;///最多N个点,M条边
struct edge
{
    int u,v,w;
    int next;
}e[M];
int head[N];
int tot;
int d[N];
bool vis[N];
void addedge(int x,int y,int z)
{
    ++tot;
    e[tot].u=x;
    e[tot].v=y;
    e[tot].w=z;
    e[tot].next=head[x];
    head[x]=tot;
}
struct node
{
    int id;
    int dis;
    node(int Id,int Dis){
        id=Id;
        dis=Dis;
    }
};
bool operator<(node a,node b)
{
    return a.dis>b.dis;
}
priority_queue<node>q;
void dijkstra()
{
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[1]=0;
    q.push(node(1,0));
    while(q.size())
    {
        int x=q.top().id;
        q.pop();
        if(vis[x]);
            continue;
        vis[x]=1;
        ///如果要求了终点，可以提前退出循环
        /*
            if(x==n)
                break;
        */
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].v;
            int z=e[i].w;
            if(d[x]+z<d[y])
            {
                d[y]=d[x]+z;
                q.push(node(y,d[y]));
            }
        }

    }
}
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;++i)
  {
      int x,y,z;
      cin>>x>>y>>z;
      addedge(x,y,z);
  }
  dijkstra();
  for(int i=1;i<=n;++i)
    cout<<d[i]<<endl;
}

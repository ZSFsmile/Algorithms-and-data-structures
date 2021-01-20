#include<bits/stdc++.h>
using namespace std;
bool vis1[101];//记录遍历过的点
bool vis2[101][101];//记录遍历过的边
int e[101][101];//存储边
int n;int m;//n个点 m条边
void Init()
{
    printf("请输入图的点数:");
    cin>>n;
    printf("请输入图的边数:");
    cin>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j)e[i][j]=0;
            else    e[i][j]=-1;
        }
    }
    printf("请输入每条边对应的起点 终点 权值:\n");
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        e[a][b]=c;e[b][a]=c;
    }
}

void dfs_solve(int cur)
{
    cout<<cur<<' ';
    for(int i=1;i<=n;++i){
        if(e[cur][i]==-1||i==cur)//满足条件则无边
            continue;
        if(vis1[i]==true)//满足条件则此边已经访问
            continue;
        vis1[i]=true;
        dfs_solve(i);
    }
}
void dfs(int start)//深度遍历所有点
{
    vis1[start]=true;
    dfs_solve(start);
}
void bfs(int start)//广度遍历所有点
{

    int que[10001],head,tail;
    head=tail=1;
    que[tail++]=start;
    vis1[start]=true;
    while(head<tail)
    {
        if(tail>n)
            break;
        int cur=que[head];
        for(int i=1;i<=n;++i){
            if(e[cur][i]==-1||cur==i)//满足条件则无边
                continue;
            if(vis1[i]==true)//满足条件则此边已经访问
                continue;
            vis1[i]=true;
            que[tail++]=i;
        }
        head++;
    }
    for(int i=1;i<tail;++i)
        cout<<que[i]<<' ';
}
int main()
{
    Init();
    bfs(1);
}

/**Dijkstra + 优先队列 = BFS + 优先队列**/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int N;
const int inf=0x3f3f3f3f;
int mp[150][150];
int dis[150][150];///dis记录到起点的最短距离
bool vis[150][150];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

struct node
{
    friend bool operator<(const node& a,const node& b)
    {
        return a.s>b.s;
    }
    int x,y,s;
};

void bfs()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    priority_queue<node>q;
    vis[0][0]=1;
    dis[0][0]=mp[0][0];
    node start={0,0,dis[0][0]};
    q.push(start);
    while(!q.empty())
    {
        node now=q.top();
        q.pop();
        if(now.x==N-1&&now.y==N-1)
        {
            break;
        }
        for(int i=0;i<4;++i)
        {
            node tmp=now;
            tmp.x+=dir[i][0];
            tmp.y+=dir[i][1];
            if(tmp.x<0||tmp.x>N-1||tmp.y<0||tmp.y>N-1)
                continue;
            tmp.s+=mp[tmp.x][tmp.y];
            if(vis[tmp.x][tmp.y]==1)
            {
                if(tmp.s>dis[tmp.x][tmp.y])
                    continue;
                dis[tmp.x][tmp.y]=tmp.s;
            }
            else
            {
                vis[tmp.x][tmp.y]=1;
                dis[tmp.x][tmp.y]=tmp.s;
                q.push(tmp);
            }
        }
    }
}
int main()
{
    int k=0;
    while(cin>>N&&N)
    {
        ++k;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>mp[i][j];
        }
    }
    bfs();
    cout<<"Problem "<<k<<": "<<dis[N-1][N-1]<<endl;
    }

    return 0;
}

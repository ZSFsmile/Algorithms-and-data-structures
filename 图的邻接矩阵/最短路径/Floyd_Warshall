#include<bits/stdc++.h>
using namespace std;
bool vis1[101];//记录遍历过的点
bool vis2[101][101];//记录遍历过的边
int e[101][101];//存储边
int n;
int m;//n个点 m条边
int inf=999999999;
void init()
{
    printf("请输入图的点数:");
    cin>>n;
    printf("请输入图的边数:");
    cin>>m;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
        }
    }
    printf("请输入每条边对应的起点 终点 权值:\n");
    for(int i=1; i<=m; ++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        e[a][b]=c;
    }
}

int main()
{
    init();
    for(int k=1; k<=n; ++k)
    {
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
                if(e[i][k]<inf&&e[k][j]<inf&&e[i][j]>e[i][k]+e[k][j])
                {
                    e[i][j]=e[i][k]+e[k][j];
                }
        }
    }
    
}


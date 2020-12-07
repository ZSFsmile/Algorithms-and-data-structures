#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define InfoType int
#define VertexType int
#define MaxVertex 1005
///ver顶点的意思，arc弧的意思,adj邻接的意思
typedef struct ArcNode///ArcNode,弧结点，一般是弧的首
{
    int adjver;///邻结点域,该弧所指向的顶点的位置下标
    struct ArcNode* nextarc;///链域，指向链表下一个结点，指向下一条弧的指针
    InfoType* info;///该弧相关信息的指针
}ArcNode;

typedef struct VNode
{
    char vername[10];///顶点名字
    VertexType data;///顶点信息
    ArcNode* firstarc;/// 此指针指向第一条依附该顶点弧
}VNode;///顶点


typedef struct ALGraph
{
    VNode ver[MaxVertex];
    int vernum;///当前顶点数
    int arcnum;///当前弧数
    ///int kind;///图的种类标志

}ALGraph;///邻结表图

ALGraph* ALGraphInit()
{
    ALGraph* G=(ALGraph*)malloc(sizeof(ALGraph));
    if(G==NULL)
        return NULL;
    G->arcnum=0;
    G->vernum=0;
    return G;
}
int ALGraphSearch(ALGraph* G,char name[])
{
    for(int i=0;i<G->vernum;++i)
    {
        if(!strcmp(G->ver[i].vername,name))
            return i;
    }
    return -1;
}

bool vis1[MaxVertex];///全局初始化为false
void ALGraphDfs(ALGraph* G,int v)///从v顶点出发搜索
{
    if(G==NULL)
        return;
    if(v<0)
        return;
    vis1[v]=true;
    printf("%s ",G->ver[v].vername);
    ArcNode* p=G->ver[v].firstarc;///p是指向当前所在的结点的下一个结点
    while(p!=NULL)
    {
        if(vis1[p->adjver]==false)
            ALGraphDfs(G,p->adjver);
        p=p->nextarc;
    }
    return;
}


bool vis2[MaxVertex];
void ALGraphBfs(ALGraph* G,int v)
{
    if(G==NULL)
        return;
    if(v<0)
        return;
    vis2[v]=true;
    printf("%s ",G->ver[v].vername);
    queue<int>qu;
    qu.push(v);
    ArcNode* p;
    while(!qu.empty())
    {
        p=G->ver[qu.front()].firstarc;
        while(p!=NULL)
        {
            if(vis2[p->adjver]==false)
            {
                printf("%s ",G->ver[p->adjver].vername);
                vis2[p->adjver]=true;
                qu.push(p->adjver);
            }
            p=p->nextarc;
        }
        qu.pop();
    }
}

void ALGraphCreat(ALGraph* G)
{
    if(G==NULL)
        return;
    cout<<"请输入图的顶点个数:";
    cin>>G->vernum;
    cout<<"请输入边数:";
    cin>>G->arcnum;
    for(int i=0;i<G->vernum;++i)
    {
        cout<<"第"<<i+1<<"个顶点的名称:";
        cin>>G->ver[i].vername;
        G->ver[i].data=0;
        G->ver[i].firstarc=NULL;
    }
    for(int i=0;i<G->arcnum;++i)
    {
        cout<<"请输入第"<<i+1<<"条边的起始位置与终止位置:";
        char name1[10],name2[10];
        cin>>name1>>name2;
        int x=ALGraphSearch(G,name1);
        int y=ALGraphSearch(G,name2);
        ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));///要插入的结点
        p->adjver=y;
        p->nextarc=NULL;
        if(G->ver[x].firstarc==NULL)
        {
            G->ver[x].firstarc=p;
        }
        else
        {
            ArcNode* q=G->ver[x].firstarc;
            while(q->nextarc!=NULL)
                q=q->nextarc;
            q->nextarc=p;
        }
    }
}


int main()
{
    ALGraph* G=ALGraphInit();
    ALGraphCreat(G);
    cout<<"深度遍历排序：";
    ALGraphDfs(G,0);
    printf("\n");
    cout<<"广度遍历排序：";
    ALGraphBfs(G,0);
	return 0;
}

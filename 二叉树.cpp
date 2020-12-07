#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<queue>
#define elemtype char
using namespace std;
typedef struct BiNode
{
	elemtype data;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode;

BiNode* BiNodeInit()//结点初始化 
{
	BiNode* root=(BiNode*)malloc(sizeof(BiNode));
	if(root==NULL)
		return NULL;
	root->lchild=NULL;
	root->rchild=NULL;
	return root;
}

/*创建二叉树两种方法 */
/* 已知一个数组创建元素  */
int index=0; 
void BiTreeCreat1(BiNode** root,elemtype data[])
{
	elemtype value=data[index++];
	if(value=='#')
		return;
	(*root)=BiNodeInit();
	(*root)->data=value;
	BiTreeCreat1(&(*root)->lchild,data);
	BiTreeCreat1(&(*root)->rchild,data);
	return;
}


/*先序创建二叉树*/
void BiTreeCreat2(BiNode** proot)
{
	elemtype value;
	cin >> value;
	if (value == '#')
		return;
	(*proot) = BiNodeInit();
	(*proot)->data = value;
	BiTreeCreat2(&(*proot)->lchild);
	BiTreeCreat2(&(*proot)->rchild);
	return;
}

/*根据下标创建完全二叉树*/ 
void BiTreeCreat3(BiNode** root,elemtype data[],int len,int index)
{
	if(index>len-1)
	 	return;
	(*root)=BiNodeInit();
	(*root)->data=data[index];
	BiTreeCreat(&(*root)->lchild,data,len,index*2);
	BiTreeCreat(&(*root)->rchild,data,len,index*2+1);
	return;
}
/*用括号表示法创建二叉树*/
void BiTreeCreat(BiNode** proot,const elemtype str[],int len)
{
	BiNode* st[105];
	int top=0;
	int flag=0;
	(*proot)->data=str[0];
	BiNode* node=(*proot);
	for(int i=1;i<len;++i)
	{
		switch(str[i])
		{
			case'(':
				st[top++]=node;
				flag=1;
				break;
			case',':
				flag=2;
				break;
			case')':
				--top;
				break;
			default:
				node=BiNodeInit();
				node->data=str[i];
				if(flag==1)
				{
					st[top-1]->lchild=node;
				}
				if(flag==2)
				{
					st[top-1]->rchild=node;
				}
		        break;
		}
		
	}
	return;
}
/*括号表示法打印二叉树*/
void BiTreePrint(BiNode* root)
{
	if(root==NULL)
		return;
	printf("%c",root->data);
	if(root->lchild!=NULL||root->rchild!=NULL)
	{
		printf("(");
		if(root->lchild!=NULL)
			BiTreePrint(root->lchild);
		if(root->rchild!=NULL)
		{
			printf(",");
			BiTreePrint(root->rchild);
		}
		printf(")");	
	}
	return;
}

void showtree(BiNode* root)
{
	if (NULL == root)
		return;
	printf("%c ", root->data);//递归前序遍历
	showtree(root->lchild);
	showtree(root->rchild);

	//showtree(root->lchild);
	//printf("%c ", root->data);//递归中序遍历
	//showtree(root->rchild);

	//showtree(root->lchild);
	//showtree(root->rchild);
	//printf("%c ", root->data);//递归后序遍历
	return;
}

void leafNum(BiNode* root,int* p)//叶子数
{
	if (NULL == root)
		return;
	if (root->lchild == NULL && root->rchild == NULL)
	{
		(*p)++;
		return;
	}
	leafNum(root->lchild, p);
	leafNum(root->rchild, p);
	return;
}

int treeHeigh(BiNode* root)//树的高度
{
	if (root == NULL)
	{
		return 0;
	}
	int lheigh = treeHeigh(root->lchild);
	int rheigh = treeHeigh(root->rchild);
	int heigh = lheigh > rheigh ? lheigh + 1 : rheigh + 1;
	return heigh;
}

BiNode* treeCopy(BiNode* root)//树的复制
{
	if (NULL == root)
		return NULL;
	BiNode* lchild = treeCopy(root->lchild);
	BiNode* rchild = treeCopy(root->rchild);
	BiNode* newnode = (BiNode*)malloc(sizeof(BiNode));
	if (newnode == NULL)
		return NULL;
	newnode->lchild = lchild;
	newnode->rchild = rchild;
	newnode->data = root->data;
	return newnode;
}

void freetree(BiNode* root)//树的释放
{
	if (root == NULL)
		return;
	free(root->lchild);
	free(root->rchild);
	free(root);
	return;
}

void preOrder(BiNode* root)//非递归前序遍历
{
	if (root == NULL)
		return;
	stack<BiNode*>st;
	BiNode* p = root;
	while (p != NULL || !st.empty())
	{
		if (p != NULL)
		{
			st.push(p);
			printf("%c ", p->data);//中
			p = p->lchild;//左
		}
		else
		{
			p = st.top();
			st.pop();
			p = p->rchild;//右
		}
	}
	return;
}

void midOrder(BiNode* root)//非递归中序遍历
{
	if (root == NULL)
		return;
	stack<BiNode*>st;
	BiNode* p = root;
	while (p != NULL || !st.empty())
	{
		if (p != NULL)
		{
			st.push(p);
			p = p->lchild;//左
		}
		else
		{
			p = st.top();
			printf("%c ", p->data);//中
			st.pop();
			p = p->rchild;//右
		}
	}
	return;
}

void postOrder(BiNode* root)//非递归后序遍历
{
	if (root == NULL)
		return;
	stack<BiNode*>st1, st2;
	BiNode* p = root;
	while (p != NULL || !st1.empty())
	{
		if (p != NULL)
		{
			st1.push(p);
			st2.push(p);
			p = p->rchild;
		}
		else
		{
			p = st1.top();
			st1.pop();
			p = p->lchild;
		}
	}
	while (!st2.empty())
	{
		printf("%c ", st2.top()->data);
		st2.pop();
	}
	return;
}

void levelOrder(BiNode* root)//层次遍历
{
	if (root == NULL)
		return;
	queue<BiNode*>qu;
	BiNode* p = root;
	qu.push(p);
	while(!qu.empty())
	{
		printf("%c ", qu.front()->data);
		if (qu.front()->lchild != NULL)
			qu.push(qu.front()->lchild);
		if (qu.front()->rchild != NULL)
			qu.push(qu.front()->rchild);
		qu.pop();
	}
}
void test06()
{
	
	BiNode* root=BiNodeInit();
	elemtype data[15] = { 'A','B','D','#','#','E','#','#','C','F','#','#','G','#','#' };
	BiTreeCreat1(&root,data);
	showtree(root);
	int num = 0;
	leafNum(root,&num);
	printf("\n叶子数=%d\n", num);
	int heigh = treeHeigh(root);
	printf("树高=%d\n", heigh);
	BiNode* newnode = treeCopy(root);
	printf("递归遍历 ");
	showtree(newnode);
	printf("\n");
	printf("非递归前序遍历 ");
	preOrder(newnode);
	printf("\n");
	printf("非递归中序遍历 ");
	midOrder(newnode);
	printf("\n");
	printf("非递归后序遍历 ");
	postOrder(newnode);
	printf("\n");
	printf("非递归层次遍历 ");
	levelOrder(newnode);

	freetree(newnode);
}
int main()
{
	test06();
	return 0;
}

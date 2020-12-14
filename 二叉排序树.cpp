#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define elemtype int
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

void BSTreeInsert(BiNode** proot,int value)
{
    if((*proot)==NULL)
    {
        *proot=BiNodeInit();
        (*proot)->data=value;
        return;
    }
    if(value==(*proot)->data)
        return;
    if(value<(*proot)->data)
        return BSTreeInsert(&(*proot)->lchild,value);
    if(value>(*proot)->data)
        return BSTreeInsert(&(*proot)->rchild,value);
    return;
}

bool BSTreeSearch(const BiNode* root,int value)
{
    if(root==NULL)
        return false;
    if(value==root->data)
        return true;
    if(value<root->data)
        return BSTreeSearch(root->lchild,value);
    if(value>root->data)
        return BSTreeSearch(root->rchild,value);
}

void showtree(BiNode* root)
{
	if (NULL == root)
		return;
	//printf("%d ", root->data);//递归前序遍历
	//showtree(root->lchild);
	//showtree(root->rchild);

	showtree(root->lchild);
	printf("%d ", root->data);//递归中序遍历
	showtree(root->rchild);

	//showtree(root->lchild);
	//showtree(root->rchild);
	//printf("%d ", root->data);//递归后序遍历
	return;
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



void test()
{

	BiNode* root=NULL;
	int n,value;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
    {

        scanf("%d",&value);
        BSTreeInsert(&root,value);
    }
    scanf("%d",&value);
    if(BSTreeSearch(root,value))
    {
        printf("ok\n");
    }
    else
        printf("error");
    showtree(root);
	freetree(root);
}
int main()
{
	test();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct linknode
{
	void* data;
	struct linknode* next;
}linknode;
typedef struct linklist
{
	linknode head;//链表头结点
	int size;
}linklist;//linklist不是头结点

linklist* linklistInit()//初始化
{
	linklist* list = (linklist*)malloc(sizeof(linklist));
	if (NULL == list)
		return NULL;
	list->head.next = NULL;
	list->size = 0;
	return list;
}
void linklistInsert(linklist* list, int index, void* data)//下标index前插入
{
	if (NULL == list)
		return;
	if (NULL == data)
		return;
	if (index<0 || index>list->size)
		index = list->size;
	linknode* cnt = &(list->head);
	for (int i = 0; i < index; ++i)
		cnt = cnt->next;
	linknode* newnode = (linknode*)malloc(sizeof(linknode));
	if (NULL == newnode)
		return;
	newnode->data = data;
	newnode->next = NULL;
	newnode->next = cnt->next;
	cnt->next = newnode;
	list->size++;
}

void linklistDelByIndex(linklist* list, int index)//按位置删除，删除下标为index的节点
{
	if (NULL == list)
		return;
	if (index<0 || index>list->size - 1)
		return;
	linknode* node = &list->head;
	for (int i = 0; i < index; ++i)
	{
		node = node->next;
	}
	linknode* pDel = node->next;
	node->next = pDel->next;
	free(pDel);
	pDel = NULL;
	list->size--;
}

//void linklistDelByVal(linklist* list, void* data)//按值删除，删除数据域为data的节点
//{
//	if (NULL == list)
//		return;
//
//}

void linklistClear(linklist* list)//清空链表
{
	if (NULL == list)
		return;
	linknode* nextnode = &list->head;
	nextnode = nextnode->next;
	while (nextnode)
	{
		linknode* clearnode = nextnode;
		nextnode = nextnode->next;
		free(clearnode);
		clearnode = NULL;
	}
	list->head.next = NULL;
	list->size = 0;
	return;
}
void linklistDestory(linklist* list)//销毁链表
{
	if (NULL == list)
		return;
	linklistClear(list);
	free(list);
	list = NULL;
	return;
}
void test02()
{
	linklist* list = linklistInit();
	int arr02[10] = { 0 };
	for (int i = 0; i < 4; ++i)
		scanf("%d", &arr02[i]);
	for (int i = 0; i < 4; ++i)
		linklistInsert(list, 10, &arr02[i]);
	linknode* test02 = &list->head;
	for (int i = 0; i < 4; ++i)
	{
		test02 = test02->next;
		printf("%d ", *(int*)test02->data);
	}
}
int main()
{
	test02();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct linknode
{
	void* data;
	struct linknode* next;
}linknode;
typedef struct linkstack
{
	linknode head;
	int size;
}linkstack;

linkstack* linkstackInit()//初始化
{
	linkstack* stack = (linkstack*)malloc(sizeof(linkstack));
	if (NULL == stack)
		return;
	stack->size = 0;
	return stack;
}

void linkstackPop(linkstack* stack)//出栈
{
	if (NULL == stack)
		return;
	if (stack->size <= 0)
		return;
	linknode* node = &stack->head;
	linknode* pDel = node->next;
	node->next = pDel->next;
	free(pDel);
	pDel = NULL;
	stack->size--;
	return;
}

void linkstackPush(linkstack* stack, void* data)//入栈
{
	if (NULL == stack)
		return;
	if (NULL == data)
		return;
	linknode* node = &stack->head;
	linknode* newnode = (linknode*)malloc(sizeof(linknode));
	if (NULL == newnode)
		return;
	newnode->data = data;
	newnode->next = node->next;
	node->next = newnode;
	stack->size++;
	return;
}

void* linkstackTop(linkstack* stack)//栈顶元素
{
	if (NULL == stack)
		return;
	if (stack->size <= 0)
		return;
	linknode* node = &stack->head;
	return node->next;
}

int linkstackSize(linkstack* stack)
{
	if (NULL == stack)
		return;
	if (stack->size < 0)
		return -1;
	return stack->size;
}

void linkstackDestory(linkstack* stack)
{
	if (NULL == stack)
		return;
	free(stack);
	stack = NULL;
}

int main()
{
	return 0;
}

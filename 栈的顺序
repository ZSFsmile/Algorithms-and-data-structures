#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100005
typedef struct sqstack
{
	void* data[MAX];
	int size;
}sqstack;

sqstack* sqstackInit()//初始化
{
	sqstack* stack = (sqstack*)malloc(sizeof(sqstack));
	if (NULL == stack)
		return NULL;
	memset(stack, 0, sizeof(sqstack));
	stack->size = 0;
	return stack;
}
void sqstackPop(sqstack* stack)//出栈
{
	if (NULL == stack)
		return;
	if (stack->size <= 0)
		return;
	stack->size--;
	stack->data[stack->size] = NULL;
	return;
}
void sqstackPush(sqstack* stack, void* data)//入栈
{
	if (NULL == stack)
		return;
	if (NULL == data)
		return;
	stack->data[stack->size] = data;
	stack->size++;
	return;
}

void* sqstackTop(sqstack* stack)//栈顶元素
{
	if (NULL == stack)
		return NULL;
	if (stack->size <= 0)
		return NULL;
	return stack->data[stack->size - 1];

}

int sqstackSize(sqstack* stack)//获取栈大小
{
	if (NULL == stack)
		return -1;
	return stack->size;
}
void sqstackDestory(sqstack* stack)//销毁栈
{
	if (NULL == stack)
		return;
	free(stack);
	return;
}

void test03()
{
	sqstack* stack = sqstackInit();
	int arr03[10] = { 0 };
	for (int i = 0; i < 4; ++i)
	{
		scanf("%d", &arr03[i]);
		sqstackPush(stack, &arr03[i]);
	}
	int len = sqstackSize(stack);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", *((int*)sqstackTop(stack)));
		sqstackPop(stack);
	}
	return;
}

int main03()
{
	test03();
	return 0;
}

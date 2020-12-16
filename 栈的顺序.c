#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100005
typedef struct sqstack
{
	int data[MAX];
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
	return;
}
void sqstackPush(sqstack* stack, int data)//入栈
{
	if (NULL == stack)
		return;
	stack->data[stack->size] = data;
	stack->size++;
	return;
}

int sqstackTop(sqstack* stack)//栈顶元素
{
	if (NULL == stack)
		return NULL;
	if (stack->size <= 0)
		return NULL;
	return stack->data[(stack->size) - 1];

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

void test()
{
	sqstack* stack = sqstackInit();
	printf("按顺序打印入栈元素: ");
	int x;
	while (scanf("%d", &x) != EOF)
    {
        sqstackPush(stack, x);
        char ch=getchar();
        if(ch=='\n')
            break;
    }
	int len = sqstackSize(stack);

	printf("按顺序打印出栈元素: ");
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", sqstackTop(stack));
		sqstackPop(stack);
	}
	return;
}

int main()
{
	test();
	return 0;
}

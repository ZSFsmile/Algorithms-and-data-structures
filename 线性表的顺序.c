#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct sqlist
{
	void** data;//void*指针可以指向所有类型
	int len;
	int size;
}sqlist;

sqlist* sqlistInit(int size)//线性表分配空间并初始化
{
	if (size <= 0)
		return NULL;
	sqlist* list = (sqlist*)malloc(sizeof(sqlist));
	if (NULL == list)
		return NULL;
	list->size = size;
	list->data = (void**)malloc(sizeof(void*) * list->size);
	list->len = 0;
	return list;
}
void sqlistInsert(sqlist* list, int index, void* data)//顺序表插入,index是下标
{
	if (NULL == list)
		return;
	if (NULL == data)
		return;
	if (index<0 || index>list->len)//return;
	{
		index = list->len;//如果插入位置不符，就将其放在最后
	}
	if (list->len >= list->size)
	{
		void** newdata = (void**)malloc(sizeof(void*) * list->size * 2);
		if (NULL == newdata)
			return;
		memcpy(newdata, list->data, sizeof(void*) * list->size);
		free(list->data);
		list->data = newdata;
		list->size *= 2;
	}
	for (int i = list->len - 1; i >= index; --i)
	{
		list->data[i + 1] = list->data[i];
	}
	list->data[index] = data;
	list->len++;
	return;
}


//sqlist* mergeList(sqlist* a, sqlist* b)//两个有序数组归并成一个数组


void sqlistDelByIndex(sqlist* list, int index)//按位置删除，删除数组下标index元素
{
	if (NULL == list)
		return;
	if (index<0 || index>list->len - 1)
		return;
	for (int i = index; i < list->len - 1; i++)
	{
		list->data[i] = list->data[i + 1];
	}
	list->len--;
	return;

}


void sqlistDestory(sqlist* list)//销毁顺序表
{
	if (NULL == list)
		return;
	if (list->data != NULL)
	{
		free(list->data);
		list->data = NULL;
	}
	free(list);
	list = NULL;
}

void test01()
{
	sqlist* list = sqlistInit(100);
	int arr01[10] = { 0 };
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &arr01[i]);
		sqlistInsert(list, 100, &arr01[i]);
	}
	for (int i = 0; i < 10; ++i)
		printf("%d ", *(int*)(list->data[i]));
	return;
}
int main()
{
	test01();
	return 0;
} 

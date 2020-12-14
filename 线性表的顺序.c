#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsize 100
#define elemtype int
typedef struct sqlist
{
    elemtype* data;
    int len;
    int size;
}sqlist;
sqlist* sqlistInit()
{
    sqlist* list = (sqlist*)malloc(sizeof(sqlist));
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->size = maxsize;
    list->data = (elemtype*)malloc(sizeof(elemtype) * maxsize);
    if (list->data == NULL)
        return NULL;
    return list;
}

void sqlistInsert(sqlist* list, int index, elemtype data)
{
    if (list == NULL)
        return;
    if (index > list->len || index < 0)
        return;
    if (list->len >= list->size)
    {
        //list->size*=2;
        //list=(sqlist*)realloc(list,list->size);
        elemtype* newdata = (elemtype*)malloc(sizeof(elemtype) * list->size * 2);
        if (newdata == NULL)
            return;
        memcpy(newdata, list->data, sizeof(elemtype) * list->size);
        free(list->data);
        list->data = newdata;
        list->size *= 2;

    }
    for (int i = list->len - 1; i >= index; i--)
    {
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = data;
    list->len++;
    return;
}

void sqlistDel(sqlist* list, int index)
{
    if (list == NULL)
        return;
    if (index > list->len - 1 || index < 0)
        return;
    for (int i = index + 1; i < list->len; i++)
    {
        list->data[i - 1] = list->data[i];
    }
    list->len--;
    return;
}

void sqlistFree(sqlist* list)
{
    if (list == NULL)
        return;
    if (list->data != NULL)
    {
        free(list->data);
        list->data = NULL;
    }
    free(list);
    list = NULL;
    return;
}

void sqlistPrint(sqlist* list)
{
    if (list == NULL)
        return;
    for (int i = 0; i < list->len; ++i)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return;
}

void test()
{
    int n;
    int index, data;
    sqlist* list = sqlistInit();
    printf("请输入顺序表元素的个数:\n");
    scanf("%d", &n);
    printf("请输入顺序表各元素的值,以空格为间隔:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data);
        sqlistInsert(list, i, data);
    }
    printf("请输入要插入元素的位置及元素值,以空格为间隔:\n");
    scanf("%d %d", &index, &data);
    sqlistInsert(list, index - 1, data);
    printf("插入后的元素表为:\n");
    sqlistPrint(list);
    printf("请输入要删除元素的位置:\n");
    scanf("%d", &index);
    printf("所删除的元素为: %d\n", list->data[index - 1]);
    sqlistDel(list, index - 1);
    printf("删除后的顺序表为:\n");
    sqlistPrint(list);
    sqlistFree(list);
}
int main()
{
    test();
    return 0;
}

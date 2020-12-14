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
    if (index > list->len+1 || index < 1)
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
    for (int i = list->len; i >= index; i--)
    {
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = data;
    list->len++;
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
    return ;
}

int sqlistSSearch(sqlist* list,elemtype value)
{
    if(list==NULL)
        return 0;
    int res=0;
    list->data[0]=value;//取第一个元素(下标为0)为哨兵节点
    for(int i=list->len;i>=0;--i)
    {
        if(list->data[i]==value)
        {
            res=i;
            break;
        }
    }
    return res;
}

int sqlistBSearch(sqlist* list,elemtype value)
{
     if(list==NULL)
        return -1;//查找失败返回-1
     int l=1,r=list->len;
     while(l<=r)
     {
         int mid=l+((r-l)>>1);
         if(list->data[mid]==value)
            return mid;
         if(list->data[mid]>value)
            r=mid-1;
         if(list->data[mid]<value)
            l=mid+1;
     }
     return -1;
}

void sqlistPrint(sqlist* list)
{
    if (list == NULL)
        return;
    for (int i = 1; i <= list->len; ++i)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return;
}

void test01()//顺序查找
{
    printf("1904010828 张帅峰\n");
    int n;
    int index, data;
    sqlist* list = sqlistInit();
    printf("请输入顺序表元素的个数: ");
    scanf("%d", &n);
    printf("请输入顺序表各元素的值: ");
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &data);
        sqlistInsert(list, i, data);
    }
    printf("顺序查找: ");
    scanf("%d",&data);
    index=sqlistSSearch(list,data);
    if(index)
        printf("查找成功,下标为%d\n",index);
    else
        printf("查找失败\n");
    sqlistFree(list);
}

void test02()//折半查找
{
    printf("1904010828 张帅峰\n");
    int n;
    int index, data;
    sqlist* list = sqlistInit();
    printf("请输入顺序表元素的个数: ");
    scanf("%d", &n);
    printf("请输入顺序表各元素的值: ");
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &data);
        sqlistInsert(list, i, data);
    }
    printf("折半查找: ");
    scanf("%d",&data);
    index=sqlistBSearch(list,data);
    if(index!=-1)
        printf("查找成功,下标为%d\n",index);
    else
        printf("查找失败\n");
    sqlistFree(list);
}
int main()
{
    test02();
    return 0;
}

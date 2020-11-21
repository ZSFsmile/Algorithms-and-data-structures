#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define elemtype int
typedef struct linknode
{
    elemtype data;
    struct linknode* next;
}linknode;
typedef struct linklist
{
    int len;
    linknode head;
}linklist;
linklist* linklistInit()
{
    linklist* list = (linklist*)malloc(sizeof(linklist));
    if (list == NULL)
        return NULL;
    list->head.next = NULL;
    list->len = 0;
    return list;
}
void linklistInsertHead(linklist* list, elemtype data)//头插法
{

    if (list == NULL)
        return;
    linknode* pnode = (linknode*)malloc(sizeof(linknode));
    if (pnode == NULL)
        return;
    pnode->data = data;
    pnode->next = NULL;
    linknode* phead = &list->head;
    pnode->next = phead->next;
    phead->next = pnode;
    list->len++;
    return;
}

void linklistInsertMid(linklist* list, elemtype insertdata, elemtype data)
{
    if (list == NULL)
        return;
    linknode* pnode = (linknode*)malloc(sizeof(linknode));
    if (pnode == NULL)
        return;
    pnode->data = data;
    pnode->next = NULL;
    linknode* phead = &list->head;
    linknode* p = phead->next;
    while (p != NULL)
    {
        if (p->data == insertdata)
        {
            pnode->next = p->next;
            p->next = pnode;
            list->len++;
            break;
        }
        p = p->next;
    }
    return;
}

void linklistDel(linklist* list, elemtype data)//按值删除
{
    if (list == NULL)
        return;
    linknode* phead = &list->head;
    linknode* p = phead;
    while (p->next != NULL)
    {
        if (p->next->data == data)
        {
            p->next = p->next->next;
            list->len--;
            break;
        }
        p = p->next;
    }
    return;
}
void linklistChange(linklist* list, elemtype changedata, elemtype data)
{
    if (list == NULL)
        return;
    linknode* phead = &list->head;
    linknode* p = phead->next;
    while (p != NULL)
    {
        if (p->data == changedata)
        {
            p->data = data;
            break;
        }
        p = p->next;
    }
    return;
}
void linklistPrint(linklist* list)
{
    linknode* phead = &list->head;
    linknode* p = phead->next;
    while (p != NULL)
    {
        if (p != phead->next)
            printf("->");
        printf("%d", (int)p->data);
        p = p->next;
    }
    printf("\n");
    return;
}
void linklistClear(linklist* list)
{
    if (list == NULL)
        return;
    linknode* phead = &list->head;
    linknode* pnode = phead->next;
    while (pnode)
    {
        linknode* clearnode = pnode;
        pnode = pnode->next;
        free(clearnode);
        clearnode = NULL;
    }
    list->len = 0;
    list->head.next = NULL;
    return;
}
void linklistDes(linklist* list)
{
    if (list == NULL)
        return;
    linklistClear(list);
    free(list);
    list = NULL;
    return;
}

void test02()
{
    int x, data, insertdata, changedata;
    linklist* list = linklistInit();
    printf("输入多个结点数值,以空格为间隔,以0为终止符\n");
    while (scanf("%d", &x) != EOF)
    {
        if (x == 0)
            break;
        linklistInsertHead(list, x);
    }
    linklistPrint(list);
    printf("请输入要删除的元素:");
    scanf("%d", &data);
    linklistDel(list, data);
    linklistPrint(list);
    printf("请输入插入位置的元素值(将待插元素插入到它的后面):");
    scanf("%d", &insertdata);
    printf("请输入待插元素值:");
    scanf("%d", &data);
    linklistInsertMid(list, insertdata, data);
    linklistPrint(list);
    printf("请输入要修改前,后的元素值:");
    scanf("%d %d", &changedata, &data);
    linklistChange(list, changedata, data);
    linklistPrint(list);

    linklistDes(list);
}
int main()
{
    test02();
    return 0;
}

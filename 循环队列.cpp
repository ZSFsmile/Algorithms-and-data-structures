#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define elemtype int
#define maxsize 15
typedef struct squeue
{
    elemtype* data;
    int head;
    int tail;
    int size;//队列长度
}squeue;
squeue* squeueInit()
{
	squeue* queue=(squeue*)malloc(sizeof(squeue));
	if(queue==NULL)
        return NULL;
    queue->data=(elemtype*)malloc(sizeof(int)*maxsize);
    if(queue->data==NULL)
        return NULL;
    queue->head=0;
    queue->tail=0;
    queue->size=maxsize;
    return queue;
}

void squeuePop(squeue* queue)
{
    if(queue==NULL)
        return;
    if(queue->data==NULL)
        return;
    if(queue->head==queue->tail)
        return;
    queue->head=(queue->head+1)%(queue->size);
    return ;
}

void squeuePush(squeue* queue,elemtype data)
{
    if(queue==NULL)
        return;
    if(queue->data==NULL)
        return;
    if((queue->tail+1)%(queue->size)==queue->head)
        return;
    queue->data[queue->tail]=data;
    queue->tail=(queue->tail+1)%(queue->size);
    return ;
}
elemtype squeueFront(squeue* queue)
{
    if(queue==NULL)
        return -1;
    if(queue->data==NULL)
        return -1;
    if(queue->head==queue->tail)
        return -1;
    return queue->data[queue->head];
}
int squeueSize(squeue* queue)
{
    if(queue->data==NULL)
        return -1;
    return (queue->tail-queue->head+queue->size)%queue->size;
}

void squeueFree(squeue* queue)
{
    if (queue == NULL)
        return;
    if (queue->data != NULL)
    {
        free(queue->data);
        queue->data = NULL;
    }
    free(queue);
    queue = NULL;
    return;
}

void test()
{
    squeue* queue=squeueInit();
    printf("按顺序打印入队元素: ");
    int x=0;
	while (scanf("%d", &x) != EOF)
    {
        squeuePush(queue,x);
        char ch=getchar();
        if(ch=='\n')
            break;
    }
    int len=squeueSize(queue);
    printf("按顺序打印出队元素: ");
	for(int i=0;i<len;++i)
    {
        printf("%d ",squeueFront(queue));
        squeuePop(queue);
    }
    squeueFree(queue);
	return;
}
int main()
{
    test();
	return 0;
}

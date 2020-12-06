#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct linknode
{
	void* data;
	struct linknode* next;
}linknode;
typedef struct linkqueue
{
	linknode head;//头结点
	linknode tail;//尾结点
	int size;
}linkqueue;

linkqueue* linkqueueInit()
{
	linkqueue* queue = (linkqueue*)malloc(sizeof(linknode));
	if (NULL == queue)
		return NULL;
	queue->head.next = NULL;
	queue->tail.next = queue->head.next;
	queue->size = 0;
	return queue;
}

void linkqueuePop(linkqueue* queue)//队列头部出
{
	if (queue == NULL)
		return;
	if (queue->size <= 0)
		return;
	linknode* head = &queue->head;
	head->next = head->next->next;
	queue->size--;
	return;
}
void linkqueuePush(linkqueue* queue, void* data)//队列尾部入
{
	if (NULL == queue)
		return;
	if (data == NULL)
		return;
	linknode* newnode = (linknode*)malloc(sizeof(linknode));
	newnode->data = data;
	newnode->next = NULL;
	linknode* tail = &queue->tail;
	tail->next = newnode;
	tail = newnode;
	queue->size++;
	return;
}
void* linkqueueFront(linkqueue* queue)
{
	if (queue == NULL)
		return NULL;
	if (queue->size <= 0)
		return NULL;
	linknode* head = &queue->head;
	return head->next;
}

void linkqueueDestory(linkqueue* queue)
{
	if (queue == NULL)
		return;
	free(queue);
	queue = NULL;
	return;
}
int main()
{
	return 0;
}

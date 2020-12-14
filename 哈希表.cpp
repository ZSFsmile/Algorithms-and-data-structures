#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define elemtype int
#define maxsize 15
#define nullkey -1
typedef struct HashTable
{
    elemtype* data;
    int len;
    int size;
}HashTable;
HashTable* HashTableInit()
{
    HashTable* H=(HashTable*)malloc(sizeof(HashTable));
    if(H==NULL)
        return NULL;
    H->len=0;
    H->size=maxsize;
    H->data = (elemtype*)malloc(sizeof(elemtype) * maxsize);
    if (H->data == NULL)
        return NULL;
    for(int i=0;i<H->size;++i)
        H->data[i]=nullkey;
    return H;
}
int HashFun(HashTable* H,int key)//哈希函数，除留余数法
{
    return key%(H->size);
}

void HashTableInsert(HashTable* H,int key)//用开放定址法处理哈希冲突
{
    if(H==NULL)
        return;
    if(H->len>=H->size)
        return;
    int k=HashFun(H,key);
    while(H->data[k]!=nullkey)
    {
        k=(k+1)%(H->size);
    }
    H->data[k]=key;
    H->len++;
    return ;
}

int HashTableSearch(HashTable* H,int key)
{
    if(H==NULL)
        return -1;
    if(H->len>=H->size)
        return -1;
    int k=HashFun(H,key);
    while(H->data[k]!=nullkey)
    {
        if(H->data[k]==key)
            return k;
        k=(k+1)%(H->size);
    }
    return -1;
}


int main()
{
    HashTable* H=HashTableInit();
    int n,key;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&key);
        HashTableInsert(H,key);
    }
    scanf("%d",&key);
    int index=HashTableSearch(H,key);
    if(index==-1)
        printf("查无此数");
    else
        printf("查找成功，下标为%d",index);
}

#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[],int len)//冒泡排序
{
    for(int i=0; i<len; i++)
    {
        bool flag=false;
        for(int j=0; j<len-i-1; ++j)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
        if(flag==false)
            break;
    }
    return ;
}

void selectSort(int arr[],int len)//选择排序
{
    for(int i=0; i<len; i++)
    {
        int pos=i;
        for(int j=i+1; j<len; ++j)
        {
            if(arr[j]<arr[pos])
                pos=j;
        }
        swap(arr[i],arr[pos]);
    }
    return ;
}

void insertSort(int arr[],int len)//插入排序
{
    if(len<=1)
        return;
    for(int i=1; i<len; ++i)
    {
        int j=i-1;
        int insertvalue=arr[i];
        for(; j>=0; j--)
        {
            if(arr[j]>insertvalue)
            {
                arr[j+1]=arr[j];
            }
            else
                break;
        }
        arr[j+1]=insertvalue;
    }
    return;
}

void quickSort(int arr[],int l,int r)//快速排序
{
    if(l>=r)
        return;
    int pivot=arr[r];///基准元素
    int i=l;///i是两区间分界点,循环中arr[i]大于基准数
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    quickSort(arr,l,i-1);
    quickSort(arr,i+1,r);
    return ;
}

void MergeSort(int arr[],int l,int r) //归并排序
{
	if(l == r) return;
	int mid((l+r)>>1);
	MergeSort(arr,l,mid);
	MergeSort(arr,mid+1,r);
	inplace_merge(arr+l,arr+mid+1,arr+r+1);
    return ;
}

int main()
{
    int arr[1005];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    for(int i=0; i<n; ++i)
    {
        printf("%d ",arr[i]);
    }
}

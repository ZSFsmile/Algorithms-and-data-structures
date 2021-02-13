#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100];
int ans[100];
void Merge(int a[],int l,int mid,int r)
{
    int pl=l,pr=mid+1;
    int k=l;
    while(pl<=mid&&pr<=r)
    {
        if(a[pl]<=a[pr])
            ans[k++]=a[pl++];
        else
            ans[k++]=a[pr++];
    }
    while(pl<=mid)
    {
        ans[k++]=a[pl++];
    }
    while(pr<=r)
    {
        ans[k++]=a[pr++];
    }
    for(int i=l; i<=r; i++)
        a[i]=ans[i];
}
void MergeSort(int a[],int l,int r)
{
    if(l==r)
        return;
    int mid=(l+r)>>1;
    MergeSort(a,l,mid);
    MergeSort(a,mid+1,r);
    Merge(a,l,mid,r);
}
int main()
{
    for(int i=1; i<=10; i++)
    {
        cin>>a[i];
    }
    MergeSort(a,1,10);
    for(int i=1; i<=10; i++)
    {
        cout<<a[i]<<' ';
    }
}
/*******
void MergeSolve(int arr[],int l,int r) //归并排序简单形式
{
	if(l == r) return;
	int mid((l+r)>>1);
	MergeSolve(arr,l,mid);
	MergeSolve(arr,mid+1,r);
	inplace_merge(arr+l,arr+mid+1,arr+r+1);
    return ;
}
void MergeSort(int arr[],int len)
{
    MergeSolve(arr,0,len-1);
    return;
}
*******/

#include<bits/stdc++.h>
using namespace std;
/******二分查找while版
int bsearch(int arr[],int n,int value)
{
    int l=0,r=n-1;
    while(l<=r)//注意是l<=r,有等号
    {
        int mid=l+((r-l)>>1);//这一行的括号一个也不能少(l+r)/2
        if(arr[mid]==value)
            return mid;
        else if(arr[mid]<value)
            l=mid+1;//l与r之后的更新必须怎么写，否则会死循环
        else
            r=mid-1;
    }
    return -1;
}
******/

int binternally(int arr[],int l,int r,int value)
{
    if(l>r)
        return -1;
    int mid=l+(r-l)/2;
    if(arr[mid]==value)
        return mid;
    if(arr[mid]<value)
        return binternally(arr,mid+1,r,value);
    if(arr[mid]>value)
        return binternally(arr,l,mid-1,value);
}
int bsearch(int arr[],int n,int value)
{
    return binternally(arr,0,n-1,value);
}
int main()
{
    int a[105];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int value;
    scanf("%d",&value);
    int in=bsearch(a,n,value);
    printf("%d %d",in,a[in]);
    return 0;
}

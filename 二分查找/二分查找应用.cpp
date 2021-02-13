#include<bits/stdc++.h>
using namespace std;
/***二分法重复元素***/

/** 查找第一个值等于给定值的元素**/
int bsearch1(int arr[],int n,int value)
{
    int l=0,r=n-1;
    while(l<=r)///注意是l<=r,有等号
    {
        int mid=l+((r-l)>>1);///这一行的括号一个也不能少(l+r)/2
        if(arr[mid]<value)
            l=mid+1;///l与r之后的更新必须怎么写，否则会死循环
        if(arr[mid]>value)
            r=mid-1;
        if(arr[mid]==value)
        {
            if((mid==0)||(arr[mid-1]!=value))
                return mid;
            else
                r=mid-1;
        }
    }
    return -1;
}
/** 查找最后一个值等于给定值的元素**/
int bsearch2(int arr[],int n,int value)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+((r-l)>>1);
        if(arr[mid]<value)
            l=mid+1;
        if(arr[mid]>value)
            r=mid-1;
        if(arr[mid]==value)
        {
            if(mid==n-1||arr[mid+1]!=value)
                return mid;
            else
                l=mid+1;
        }
    }
    return -1;
}
/** 查找第一个大于等于给定值的元素，
或者说大于等于给定值的元素最小一个**/
int bsearch3(int arr[],int n,int value)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+((r-l)>>1);
        if(arr[mid]>=value)
        {
            if((mid==0)||(arr[mid-1]<value))
                return mid;
            else
                r=mid-1;
        }
        else
            l=mid+1;
    }
    return -1;
}
/** 查找最后一个小于等于给定值的元素，
或者说小于等于给定值的元素最大一个**/
int bsearch4(int arr[],int n,int value)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+((r-l)>>1);
        if(arr[mid]<=value)
        {
            if((mid==n-1)||(arr[mid+1]>value))
                return mid;
            else
                l=mid+1;
        }
        else
            r=mid-1;
    }
    return -1;
}

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
    return 0;
}

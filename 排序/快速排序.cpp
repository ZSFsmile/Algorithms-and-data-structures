void quickSolve(int arr[],int l,int r)//快速排序
{
    //每次选一个基准值，按大于小于基准值 将排序的数分在左右两侧
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
    quickSolve(arr,l,i-1);
    quickSolve(arr,i+1,r);
    return ;
}

void quickSort(int arr[],int len)
{
    quickSolve(arr,0,len-1);
    return;
}

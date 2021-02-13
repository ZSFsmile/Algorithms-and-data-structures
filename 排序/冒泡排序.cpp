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

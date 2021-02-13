void MergeSolve(int arr[],int l,int r) //归并排序
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

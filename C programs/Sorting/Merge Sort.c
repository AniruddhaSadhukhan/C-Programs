//55. Implementation of Merge Sort.
#include<stdio.h>
#define MAX_SIZE 100
void merge(int a[],int low,int mid,int high)
{
	int b[MAX_SIZE],left,right,i;
	left=low;
	right=mid+1;
	i=low;
	while(left<=mid && right<=high)
	{
		if(a[left]<a[right])
			b[i++]=a[left++];
		else b[i++]=a[right++];
	}
	while(left<=mid)
		b[i++]=a[left++];
	while(right<=high)
		b[i++]=a[right++];
	for(i=low;i<=high;i++)
		a[i]=b[i];
}
void mergeSort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int arr[MAX_SIZE],n,i;
	printf("Enter size: ");
	scanf("%d",&n);
	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1);
	printf("After sort       : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
/*Output:
Enter size: 5
Enter 5 elements:  5 20 15 10 25
After sort      :  5 10 15 20 25
*/

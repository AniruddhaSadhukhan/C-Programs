//56. Implementation of Quick Sort.
#include<stdio.h>
#define MAX_SIZE 10
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int a[],int low,int high)
{
	int left=low,right=high-1,pivot=a[high]; //Choose the highest index value has pivot
	while(1)
	{
		while(a[left]<pivot)
			left++;  
		while(a[right]>=pivot && right > left)
			right--; 
		if(left==right)
		{
			swap(&a[left],&a[high]);
			break;
		}
		else if(left==high)
			break;	
		else swap(&a[left],&a[right]);
	}
	return left;	
}
void quick_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int p=partition(a,low,high);
		quick_sort(a,low,p-1);
		quick_sort(a,p+1,high);	
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
	quick_sort(arr,0,n-1);
	printf("After sort       : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
/*Output:
Enter size: 10
Enter 10 elements: 564 65 152 54 498 35 16 258 57 47 
After sort       : 16 35 47 54 57 65 152 258 498 564
*/

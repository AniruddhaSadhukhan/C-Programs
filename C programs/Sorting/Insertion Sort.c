//53. Insertion Sort.
#include<stdio.h>
#define MAX_SIZE 10
void insertion_sort(int a[],int n)
{
	int i,j,k;
	for(i=1;i<n;i++)
	{
		k=a[i];
		j=i-1;
		while((k<a[j])&&(j>=0))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=k;
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
	insertion_sort(arr,n);
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

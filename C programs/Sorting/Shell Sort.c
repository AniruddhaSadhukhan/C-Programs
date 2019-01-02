//57. Implementation of Shell Sort.
#include<stdio.h>
#define MAX_SIZE 10
void shell_sort(int a[],int n)
{
	int i,j,k,gap;
	for (gap = n/2; gap > 0; gap=gap/2)
	{
		for(i=gap;i<n;i=i+gap)
		{
			k=a[i];
			j=i-gap;
			while((k<a[j])&&(j>=0))
			{
				a[j+gap]=a[j];
				j=j-gap;
			}
			a[j+gap]=k;
		}
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
	shell_sort(arr,n);
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

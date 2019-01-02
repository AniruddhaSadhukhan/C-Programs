//1. Create an array and insert an element in the array. 
#include<stdio.h>
#define MAX 5
int main()
{
	int arr[MAX],n,i;
	printf("Enter values:");
	for(i=0;i<MAX;i++)
		scanf("%d",&arr[i]);
	printf("Array is : ");
	for(i=0;i<MAX;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
/* Output:
Enter values:5 10 20 32 50
Array is : 5 10 20 32 50 */

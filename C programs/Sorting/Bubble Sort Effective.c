//51. Implementation of Efficient Bubble Sort (time complexity O(n))  
#include<stdio.h>
#define MAX_SIZE 10
void effective_bubble_sort(int a[],int n)
{
	int i,j,temp,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
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
	effective_bubble_sort(arr,n);
	printf("After sort       :  ");
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

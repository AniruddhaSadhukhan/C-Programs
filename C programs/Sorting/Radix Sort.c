//54. Implementation of Radix Sort.
#include<stdio.h>
#define MAX_SIZE 10
void radix_sort(int a[],int n)
{
	int bucket[10][20],bucketCount[10];
	int i,j,k,r,digit=0,d=1,l=a[0],passNo;
	for(i=1;i<n;i++)	//find largest number
		if(a[i]>l)
			l=a[i];
	while(l>0)	//count digit in largest number
	{
		digit++;
		l=l/10;
	}
	for(passNo=0;passNo<digit;passNo++)
	{
		for(i=0;i<10;i++)	
			bucketCount[i]=0;	//initialise bucket count
		for(i=0;i<n;i++)	//keeping in bucket
		{
			r=(a[i]/d)%10;
			bucket[r][bucketCount[r]++]=a[i];
		}
		d=d*10;
		i=0;
		for(j=0;j<10;j++)	//collecting element from bucket
			for(k=0;k<bucketCount[j];k++)
				a[i++]=bucket[j][k];	
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
	radix_sort(arr,n);
	printf("After sort      : ");
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

//43. Binary Search using iteration.
#include<stdio.h>
#define MAX_SIZE 10
int binary_search(int a[],int n,int val)
{
	int beg=0,end=n-1,mid=(n-1)/2;
	while(beg<=end && val!=a[mid])
	{
		if(val<a[mid])
			end=mid-1;
		else beg=mid+1;
		mid=(beg+end)/2;
	}
	return (val==a[mid])?(++mid):-1;
}
int main()
{
	int arr[MAX_SIZE],n,val,x,i;
	printf("Enter size: ");
	scanf("%d",&n);
	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Search which element?: ");
	scanf("%d",&val);
	x=binary_search(arr,n,val);
	if(x==-1)
		printf("Not found\n");
	else printf("Position = %d\n",x);
	return 0;
}
/*Output:
Enter size: 5
Enter 5 elements:  5 10 15 20 25
Search which element?: 20
Position = 4

*/

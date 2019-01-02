//45. Interpolation Search using iteration.
#include<stdio.h>
#define MAX_SIZE 10
int interpolation_search(int a[],int n,int val)
{
	int beg=0,end=n-1,mid=(n-1)/2;
	mid=(val-a[0])*(n-1)/(a[n-1]-a[0]);
	while(beg<=end && val!=a[mid])
	{
		if(val<a[mid])
			end=mid-1;
		else beg=mid+1;
		mid=beg+(val-a[beg])*(end-beg)/(a[end]-a[beg]);
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
	x=interpolation_search(arr,n,val);
	if(x==-1)
		printf("Not found\n");
	else printf("Position = %d\n",x);
	return 0;
}
/*Output:
Enter size: 5
Enter 5 elements: 1 3 5 7 9
Search which element?: 7
Position = 4
*/

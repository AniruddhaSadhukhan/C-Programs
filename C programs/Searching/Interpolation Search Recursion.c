//46. Interpolation Search using recursion.
#include<stdio.h>
#define MAX_SIZE 10
int interpolation_search_recursion(int a[],int beg,int end,int val)
{
	int mid;
	if(beg>end)
		return -1;
	else 
	{
		mid=beg+(val-a[beg])*(end-beg)/(a[end]-a[beg]);
		if (val==a[mid])
			return ++mid;
		if(val<a[mid])
			return interpolation_search_recursion(a,beg,mid-1,val);
		else return interpolation_search_recursion(a,mid+1,end,val);
	}
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
	x=interpolation_search_recursion(arr,0,n-1,val);
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

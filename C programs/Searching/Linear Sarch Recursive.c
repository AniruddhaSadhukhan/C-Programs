//42. Liner Search using recursion.
#include<stdio.h>
#define MAX_SIZE 10
int linear_search_recursion(int a[],int n,int val)
{
	if(n==0)
		return -1;
	if(a[n-1]==val)
		return n;
	else return linear_search_recursion(a,n-1,val);
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
	x=linear_search_recursion(arr,n,val);
	if(x==-1)
		printf("Not found\n");
	else printf("Position = %d\n",x);
	return 0;
}
/*Output:
Enter size: 5
Enter 5 elements: 5 25 10 15 50
Search which element?: 15
Position = 4
*/

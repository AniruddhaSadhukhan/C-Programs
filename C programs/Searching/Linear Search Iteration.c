//41. Liner Search using iteration.
#include<stdio.h>
#define MAX_SIZE 10
int linear_search(int a[],int n,int val)
{
	int i,pos=1;
	for(i=0;i<n;i++)
	{
		if(a[i]==val)
			break;
		pos++;
	}
	return pos>n?-1:pos;
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
	x=linear_search(arr,n,val);
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

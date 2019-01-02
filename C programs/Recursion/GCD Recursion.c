//11. GCD using recursion.
#include<stdio.h>
int GCD(int x,int y)
{
	if(x==y)
		return x;
	else if(x>y)
		return GCD(x-y,y);
	else
		return GCD(x,y-x);
}
int main()
{
	int n1,n2;
	printf("\nEnter two numbers: ");
	scanf("%d %d",&n1,&n2);
	printf("GCD of %d and %d is: %d\n",n1,n2,GCD(n1,n2));
	return 0;
}
/*Output:
Enter two numbers: 4 6
GCD of 4 and 6 is: 2
*/


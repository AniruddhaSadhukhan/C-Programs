//14. Implement Fibonacci series using recursion.
#include<stdio.h>
int Fibonacci(int x)
{
	if(x<=1)
		return x;
	else
		return (Fibonacci(x-1)+Fibonacci(x-2));
}

int main()
{
	int a,i;
	printf("Enter size of the Fibonacci series: ");
	scanf("%d",&a);
	for(i=0;i<a;i++)
		printf("%d ",Fibonacci(i));
	printf("\n");
	return 0;
}
/*Output:
Enter size of the Fibonacci series: 10
0 1 1 2 3 5 8 13 21 34
*/

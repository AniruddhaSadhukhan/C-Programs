//10. Factorial using recursion.
#include <stdio.h>
int Factorial(int n)
{
	if (n == 0)
		return 1;   
	else
		return n*Factorial(n-1);        
}
int main()
{
	int n;
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	printf("Factorial = %d\n",Factorial(n));
	return 0;
}
/*Output:
Enter a positive integer: 6
Factorial = 720*/

//13.  Factorial using tail recursion.  
#include <stdio.h>
int Fact(int n,int r)
{
	if (n == 0)
		return r;   
	else
		return Fact(n-1,n*r);        
}
int Factorial(int n)
{	
	return Fact(n,1);        
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

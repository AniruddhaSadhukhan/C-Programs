//12. GCD using tail recursion.  
#include<stdio.h>
int tryDivisor(int m,int n,int g) 
{
	if(((m % g) == 0) && ((n % g) == 0))
		return g;
	else
		return tryDivisor(m, n, g - 1);
}
int gcd(int m, int n)
{
	return tryDivisor(m, n, n);
}
int main()
{
	int n1,n2;
	printf("\nEnter two numbers: ");
	scanf("%d %d",&n1,&n2);
	printf("GCD of %d and %d is: %d\n",n1,n2,gcd(n1,n2));
	return 0;
}
/*Output:
Enter two numbers: 4 6
GCD of 4 and 6 is: 2
*/


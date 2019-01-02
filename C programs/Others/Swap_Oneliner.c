#include<stdio.h>

//Program to Swap Values in One Line 
//	by Aniruddha
int main()
{
	int a=5,b=100;
	printf("Before Swapping: a= %d ; b= %d\n",a,b);
	
	a= a + b - (b = a);
	
	printf("After Swapping: a= %d ; b= %d\n",a,b);
	return 0;
}

/*Sample Output
Before Swapping: a= 5 ; b= 100
After Swapping: a= 100 ; b= 5
*/

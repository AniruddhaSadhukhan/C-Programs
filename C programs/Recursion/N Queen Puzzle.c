//16. Implement 8 queen puzzle.  
#include<stdio.h>
#include<stdlib.h>
int a[30];
int place(int pos) 
{
	int i;
 	for (i=1;i<pos;i++) 	
 	{
 		if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
 		return 0;
 	}
 	return 1;
}
void print_sol(int n) 
{
	int i,j;
 	printf("\n\nSolution :\n");
 	for (i=1;i<=n;i++) 
 	{
 		for (j=1;j<=n;j++) 
 		{
 			if(a[i]==j)
 				printf("Q "); 
 			else
 			 printf("* ");
 		}
 		printf("\n");
 	}
}
void queen(int n) 
{
	int k=1;
 	a[k]=0;
 	while(k!=0) 
 	{
 		a[k]=a[k]+1;
 		while((a[k]<=n)&&!place(k))
 			a[k]++;
 		if(a[k]<=n) 
 		{
 			if(k==n)
 			{
 				print_sol(n);
 				return;
 			}
 			else 
 			{
 				k++;
 				a[k]=0;
 			}
 		} 
 		else
 			k--;
 	}
}
int main() 
{
 	int n;
 	printf("Enter the number of Queens ");
 	scanf("%d",&n);
 	queen(n);
 	return 0;
 }
/*Output:
Enter the number of Queens 8

Solution :
Q * * * * * * * 
* * * * Q * * * 
* * * * * * * Q 
* * * * * Q * * 
* * Q * * * * * 
* * * * * * Q * 
* Q * * * * * * 
* * * Q * * * * 
*/

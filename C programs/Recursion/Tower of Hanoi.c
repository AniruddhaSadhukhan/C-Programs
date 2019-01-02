//15. Tower Of Hanoi using recursion.
#include <stdio.h>
void ToH(char A, char B, char C,int n)
{
	if (n == 1)
	{
		printf("%c --> %c\n",A,C);
		return;
	}
	else
	{
		ToH(A,C,B,n-1);
		ToH(A,B,C,1);
		ToH(B,A,C,n-1);
	}
}
int main()
{
	int n;
	printf("Enter the number of disks : ");
	scanf("%d",&n);
    	printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    	ToH('A', 'B','C', n);
	return 0;
}
/*Output:
Enter the number of disks : 3
The sequence of moves involved in the Tower of Hanoi are :
A --> C
A --> B
C --> B
A --> C
B --> A
B --> C
A --> C
*/


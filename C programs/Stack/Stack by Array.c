//30. Implementation of stack using array.
#include<stdio.h>
#define MAX 5
int a[MAX],tos=0;
void push(int n)
{
	a[++tos]=n;
}
int pop()
{
	return a[tos--];
}
int main()
{
	int z,n;
	while(1)
	{
		printf("Enter 1 to push,2 to pop,3 to display,4 to exit: ");
		scanf("%d",&z);
		switch(z)
		{
			case 1:	if (tos == MAX)
                 		printf("Stack Overflow\n");
                 		else 
                 		{
               				printf("Insert value= ");
              				scanf("%d", &n);
               				push(n);
            		  	}
           	 		break;
          		case 2:	if (tos == 0)
              		 		printf("Stack Underflow\n");
           	 		else 
              		 		printf("Deleted value= %d.\n",pop());
            	 		break;
          		case 3:	for(int i=tos;i>0;i--)
          				printf("  %d\n",a[i]);
          			break;
          		case 4:return 0;;
      		}
      	}  
}
/*Output:
Enter 1 to push,2 to pop,3 to display,4 to exit: 1
Insert value= 5
Enter 1 to push,2 to pop,3 to display,4 to exit: 1
Insert value= 10
Enter 1 to push,2 to pop,3 to display,4 to exit: 1
Insert value= 20
Enter 1 to push,2 to pop,3 to display,4 to exit: 2
Deleted value= 20.
Enter 1 to push,2 to pop,3 to display,4 to exit: 3
  10
  5
Enter 1 to push,2 to pop,3 to display,4 to exit: 4
	
*/

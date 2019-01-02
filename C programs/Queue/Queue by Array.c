//36. Implementation Queue using Array. 
#include<stdio.h>
#define MAX 5
int a[MAX],head=0,tail=0;
void push(int n)
{
	if(tail<MAX)
	a[tail++]=n;
	else printf("Error\n");
}
void pop()
{
	if(head<MAX && head<tail)
		printf("Deleted element= %d.\n", a[head++]);
	else printf("Error\n");
}
int main()
{
	int z,n;
	while(1)
	{
		printf("Enter 1 to insert,2 to delete,3 to display,4 to exit ");
		scanf("%d",&z);
		switch(z)
		{
			case 1:	printf("Insert value= ");
        	      		scanf("%d", &n);
        	       		push(n);           		
           	 		break;
          		case 2:	pop();
            	 		break;
          		case 3:	for(int i=head;i<tail;i++)
          				printf("  %d\n",a[i]);
          			break;
          		case 4:	return 0;
      		}
      	}     
}
/*Output:
Enter 1 to insert,2 to delete,3 to display,4 to exit 1
Insert value= 5
Enter 1 to insert,2 to delete,3 to display,4 to exit 1
Insert value= 10
Enter 1 to insert,2 to delete,3 to display,4 to exit 1
Insert value= 20
Enter 1 to insert,2 to delete,3 to display,4 to exit 3
  5
  10
  20
Enter 1 to insert,2 to delete,3 to display,4 to exit 2
Deleted element= 5.
Enter 1 to insert,2 to delete,3 to display,4 to exit 4
*/

//31. Implementation of stack using link list. 
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head=NULL,*top;
void push(int n)	//insert at head
{
	node *np=(node *)malloc(sizeof(node));
	np->data=n;
	np->link=NULL;
	if(head!=NULL)
		np->link=head;
	head=np;	
}
int pop()	//delete from head
{
	int n=head->data;
	node *temp=head;
	head=head->link;
	free(temp);
	return n;
}
void display(node *l)
{
	while(l!=NULL)
	{
		printf("  %d \n",l->data);
		l=l->link;
	}
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
			case 1:	printf("Enter the value to insert: ");
        	      		scanf("%d", &n);
        	       		push(n);
        	   		break;
          		case 2:	if (head == NULL)
              		 	printf("Stack Underflow\n\n");
           	 		else 
              				printf("Popped element= %d.\n",pop());
            	 		break;
          		case 3:	display(head);        		
          			break;
          		case 4:	return 0;
      		}
      	}
     
}
/*Output:
Enter 1 to push,2 to pop,3 to display,4 to exit: 1
Enter the value to insert: 5
Enter 1 to push,2 to pop,3 to display,4 to exit: 1
Enter the value to insert: 010
Enter 1 to push,2 to pop,3 to display,4 to exit: 1
Enter the value to insert: 20
Enter 1 to push,2 to pop,3 to display,4 to exit: 3
  20 
  10 
  5 
Enter 1 to push,2 to pop,3 to display,4 to exit: 2
Popped element= 20.
Enter 1 to push,2 to pop,3 to display,4 to exit: 4	
*/

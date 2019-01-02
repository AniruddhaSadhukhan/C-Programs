//37. Implementation Queue using Link List. 
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head=NULL,*last;
void push(int n)	//insert in end
{
	node *np=(node *)malloc(sizeof(node));
	np->data=n;
	np->link=NULL;
	if(head==NULL)
		head=np;
	else
		last->link=np;
	last=np;	
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
	while(1){
	printf("Enter 1 to push,2 to pop,3 to display,4 to exit ");
	scanf("%d",&z);
	switch(z)
	{
		case 1:	printf("Insert value= ");
              		scanf("%d", &n);
               		push(n);
           		break;
          	case 2:	if (head == NULL)
              		 	printf("Queue Underflow\n\n");
           	 	else 
              			printf("Element removed= %d.\n",pop());
            	 	break;
          	case 3:	display(head);
          		break;
          	case 4:return 0;;
      	}} 
}
/*Output:
	Enter 1 to push,2 to pop,3 to display,4 to exit 1
Insert value= 5
Enter 1 to push,2 to pop,3 to display,4 to exit 1
Insert value= 10
Enter 1 to push,2 to pop,3 to display,4 to exit 1
Insert value= 20
Enter 1 to push,2 to pop,3 to display,4 to exit 3
  5 
  10 
  20 
Enter 1 to push,2 to pop,3 to display,4 to exit 2
Element removed= 5.
Enter 1 to push,2 to pop,3 to display,4 to exit 4
*/

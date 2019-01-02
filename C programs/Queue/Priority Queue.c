//40. Implement Priority-Queue. (using link list). 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int priority;
	int data;
	struct node *link;
}node;
node *front=NULL;
void insert(int item,int item_priority)
{
	node *tmp,*p;
	tmp=(node *)malloc(sizeof(node));
	tmp->data=item;
	tmp->priority=item_priority;
	/*Queue is empty or item to be added has priority more than first element*/
	if(front == NULL || item_priority < front->priority )
	{
		tmp->link=front;
		front=tmp;
	}
	else
	{
		p = front;
		while( p->link!=NULL && p->link->priority<=item_priority )
		p=p->link;
		tmp->link=p->link;
		p->link=tmp;
	}
}/*End of insert()*/

int del()
{
	node *tmp;
	int item;
	if( front == NULL )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		tmp=front;
		item=tmp->data;
		front=front->link;
		free(tmp);
	}
	return item;
}
void display()
{
	node *ptr;
	ptr=front;
	if( front == NULL )
		printf("Queue is empty\n");
	else
	{
		printf("Queue is :\n");
		printf("Priority   Item\n");
		while(ptr!=NULL)
		{
			printf("%5d%9d\n",ptr->priority,ptr->data);
			ptr=ptr->link;
		}
	}
}/*End of display() */
int main()
{
	int choice,item,item_priority;
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Quit\n");
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Input the item to be added in the queue : ");
				scanf("%d",&item);
				printf("Enter its priority : ");
				scanf("%d",&item_priority);
				insert(item, item_priority);
				break;
			case 2:
				printf("Deleted item is %d\n",del());
				break;
			case 3:
				display();
				break;
			case 4:return 0;
		}
	}
}
/*Output
1.Insert
2.Delete
3.Display
4.Quit
Enter your choice : 1
Input the item to be added in the queue : 10
Enter its priority : 5
Enter your choice : 1
Input the item to be added in the queue : 20
Enter its priority : 2
Enter your choice : 1
Input the item to be added in the queue : 30
Enter its priority : 6
Enter your choice : 1
Input the item to be added in the queue : 60 
Enter its priority : 2
Enter your choice : 3
Queue is :
Priority   Item
    2   20
    2   60
    5   10
    6   30
Enter your choice : 4

*/


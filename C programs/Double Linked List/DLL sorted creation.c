#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev,*next;
}node;
node *head;
node *makeNode(int n) 
{
    node *np = (node *)malloc(sizeof(node));
    np->data = n;
    np->prev = NULL;
    np->next = NULL;
    return np;
} 
node *create(void)		//create sorted double circular linked list
{
	int n;
	node *np,*start,*l;
	start=NULL;
	printf("Enter node data(0 to terminate): ");
	scanf("%d",&n);
	while (n!=0)
	{
		np=makeNode(n);
		if(start==NULL)
			start=np;
		else if(n < start->data)
		{
			start->prev=np;
			np->next=start;
			start=np;
		}
		else 
		{
			l=start;
			while(1)
			{
				if(l->next==NULL)
					break;
				if(l->next->data < n)
					l=l->next;
				else break;
			}
			np->prev=l;
			np->next=l->next;
			if(l->next!=NULL)
				l->next->prev=np;
			l->next=np;	
		}
		scanf("%d",&n);
	}
	return start;
}
void display(node *l)
{
	while(l!=NULL)
	{
		printf("[%d | %d | %d]-->",l->prev,l->data,l->next);
		l=l->next;
	}
	printf("\b\b\b   \n");
}

int main()
{
	head=create();
	display(head);
}



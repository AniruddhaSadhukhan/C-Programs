#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int data;
	struct node* link;
}node;

node *head;

node* makeNode(int n)
{
	node* np=(node*)malloc(sizeof(node));
	np->data=n;
	np->link=NULL;
	return np;
}

node* create() 	//create sorted linked list
{
	node *start=NULL,*np,*l;
	int n;
	printf("Enter Numbers (0 to stop): ");
	scanf("%d",&n);
	while(n!=0)
	{
		np=makeNode(n);
		if(start==NULL)
			start=np;
		else if(n<start->data)
		{
			np->link=start;
			start=np;
		}
		else 
		{
			l=start;
			while(1)
				{
					if(l->link==NULL)
						break;
					if(l->link->data<n)
					 	l=l->link;
					else break;
				}
				
			np->link=l->link;
			l->link=np;
		}	
		scanf("%d",&n);
	}
	return start;
}

void display(node* l)
{
	while(l!=NULL)
	{
		printf("[%d | %d] -->",l->data,l->link);
		l=l->link;
	}	
	printf("\b\b\b   \n");
}


int main()
{
	head=create();
	display(head);
}
/*
Enter Numbers (0 to stop): 25 10 20 15 5 0
[5 | 34019408] -->[10 | 34019472] -->[15 | 34019440] -->[20 | 34019376] -->[25 | 0]    

*/

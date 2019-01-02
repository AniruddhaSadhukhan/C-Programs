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
node* create() 	
{
	node *start=NULL,*np,*last;
	int n;
	printf("Enter Numbers (0 to stop): ");
	scanf("%d",&n);
	while(n!=0)
	{
		np=makeNode(n);
		if(start==NULL)
			start=np;
		else
			last->link=np;
		last=np;		
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
void delx()	//delete values greater than given data
{
	int val;
	node *temp,*l=head;
	printf("Delete greater than value: ");scanf("%d",&val);
	while(head->data > val)
	{
		temp=head;
		head=head->link;free(temp);
	}
	while(l->link!=NULL)
	{
		if(l->link->data > val)
		{
			temp=l->link;
			l->link=l->link->link;
			free(temp);	
		}
		else l=l->link;
	}
	display(head);
}
int main()
{
	head=create();
	display(head);
	delx();
}

/*
Enter Numbers (0 to stop): 100 25 5 10 15 30 45 56 98 22 0
[100 | 19286096] -->[25 | 19286128] -->[5 | 19286160] -->[10 | 19286192] -->[15 | 19286224] -->[30 | 19286256] -->[45 | 19286288] -->[56 | 19286320] -->[98 | 19286352] -->[22 | 0]    
Delete greater than value: 50
[25 | 19286128] -->[5 | 19286160] -->[10 | 19286192] -->[15 | 19286224] -->[30 | 19286256] -->[45 | 19286352] -->[22 | 0] 
*/

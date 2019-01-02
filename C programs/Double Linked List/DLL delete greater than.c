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
node *create(void)	
{
	int n;
	node *np,*start,*last;
	start=NULL;
	printf("Enter node data(0 to terminate): ");
	scanf("%d",&n);
	while (n!=0)
	{
		np=makeNode(n);
		if(start==NULL)
			start=np;
		else 	
		{
			last->next=np;
			np->prev=last;
		}
		last=np;
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

void delx()
{
	int val;
	printf("Delete value greater than:");scanf("%d",&val);
	node* temp,*l;
	
	while (head->data > val)
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
	}
	l=head->next;
	while(l!=NULL)
	{
		if(l->data > val)
		{
			temp=l;
			l->prev->next=l->next;
			if(l->next!=NULL)
				l->next->prev=l->prev;
			l=l->next;
			free(temp);
		}
		else l=l->next;
	}
	display(head);
}
int main()
{
	head=create();
	display(head);
	delx();
}



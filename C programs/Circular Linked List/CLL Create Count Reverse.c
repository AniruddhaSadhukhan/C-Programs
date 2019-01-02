//23. To implement the operations like create,count,reverse and display in a circular link list
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}node;

node *head;
node *head2;

node *makeNode(int n) 
{
    node *np = (node *)malloc(sizeof(node));
    np->data = n;
    np->link = NULL;
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
			last->link=np;
		last=np;
		scanf("%d",&n);
	}
	last->link=start;
	return start;
}

void display(node *l)
{
	node *start=l;
	do
	{
		printf("[%d | %u]-->",l->data,l->link);
		l=l->link;
	}while(l!=start);
	printf("\b\b\b   \n");
}

int count(node *l)
{
	int c=0;
	do
	{
		c++;
		l=l->link;
	}while(l!=head);
	return c;
}
void rev()
{
	node *prev,*cur,*next;
	prev=NULL;
	cur=head;
	next=cur->link;
	while(next!=head)
	{
		prev=cur;
		cur=next;
		next=cur->link;
		cur->link=prev;
	}
	head->link=cur;
	head=cur;
	printf("\nAfter reverse:\n");
	display(head);
}
int main()
{
	int a;
	char ch,chr;
	head=create();
	display(head);
	printf("Count: %d",count(head));
	rev();
	return 0;
}

/*Output
Enter node data(0 to terminate): 5 10 20 30 0
[5 | 9926736]-->[10 | 9926768]-->[20 | 9926800]-->[30 | 9926704]   
Count: 4
After reverse:
[30 | 9926768]-->[20 | 9926736]-->[10 | 9926704]-->[5 | 9926800]   
*/

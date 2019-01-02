//17. To implement the operations like create , count , reverse and display in a single link list .
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head;
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
	return start;
}
void display(node *l)
{
	while(l!=NULL)
	{
		printf("[%d | %u]-->",l->data,l->link);
		l=l->link;
	}
	printf("NULL\n");
}
int count(node *l)
{
	int c=0;
	while(l!=NULL)
	{
		c++;
		l=l->link;
	}
	return c;
}
void rev()
{
	node *prev,*cur,*next;
	prev=NULL;
	cur=head;
	next=cur->link;
	cur->link=NULL;
	while(next!=NULL)
	{
		prev=cur;
		cur=next;
		next=cur->link;
		cur->link=prev;
	}
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
Enter node data(0 to terminate): 5 10 20 30 40 0
[5 | 38103120]-->[10 | 38103152]-->[20 | 38103184]-->[30 | 38103216]-->[40 | 0]-->NULL
Count: 5
After reverse:
[40 | 38103184]-->[30 | 38103152]-->[20 | 38103120]-->[10 | 38103088]-->[5 | 0]-->NULL
*/

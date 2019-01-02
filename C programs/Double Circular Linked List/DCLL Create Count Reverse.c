//26. To implement the operations like create, count , reverse and display in a double circular link list 
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
	start->prev=last;
	last->next=start;
	return start;
}
void display(node *l)
{
	node *start=l;
	do
	{
		printf("[%u | %d | %u]-->",l->prev,l->data,l->next);
		l=l->next;
	}while(l!=start);
	printf("\b\b\b   \n");
}
int count(node *l)
{
	int c=0;
	do
	{
		c++;
		l=l->next;
	}while(l!=head);
	return c;
}
void rev()
{
	node *cur= head,*temp;
	do
	{
		temp = cur->prev;   //swap the next and prev pointer
		cur->prev = cur->next;
		cur->next = temp;
		cur = cur->prev;
	}while(cur!=head);
	head->next=temp->prev;
	head=temp->prev;
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
[31295632 | 5 | 31295568]-->[31295536 | 10 | 31295600]-->[31295568 | 20 | 31295632]-->[31295600 | 30 | 31295536]   
Count: 4
After reverse:
[31295536 | 30 | 31295600]-->[31295632 | 20 | 31295568]-->[31295600 | 10 | 31295536]-->[31295568 | 5 | 31295632]   
*/

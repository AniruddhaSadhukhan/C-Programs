//20. To implement the operations like create , count , reverse and display in a double link list .
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
		else{
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
		printf("[%u | %d | %u]-->",l->prev,l->data,l->next);
		l=l->next;
	}
	printf("NULL\n");
}
int count(node *l)
{
	int c=0;
	while(l!=NULL)
	{
		c++;
		l=l->next;
	}
	return c;
}
void rev()
{
	node *cur= head,*temp;
	while(cur!=NULL)
	{
		temp = cur->prev;   //swap the next and prev pointer
		cur->prev = cur->next;
		cur->next = temp;
		cur = cur->prev;
	}
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
[0 | 5 | 29440080]-->[29440048 | 10 | 29440112]-->[29440080 | 20 | 29440144]-->[29440112 | 30 | 0]-->NULL
Count: 4
After reverse:
[0 | 30 | 29440112]-->[29440144 | 20 | 29440080]-->[29440112 | 10 | 29440048]-->[29440080 | 5 | 0]-->NULL
*/

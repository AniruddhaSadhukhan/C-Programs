//18. To implement create, insert at head, insert after,insert before, insert at end in single link list.
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
void insf(node *l)
{
	node *t;
	t=(node *)malloc(sizeof(node));
	printf("Enter node data: ");
	scanf("%d",t);
	t->link=head;
	head=t;
	display(head);
}
void insa(node *l)
{
	int val;
	printf("After which data,you want to insert: ");
	scanf("%d",&val);
	node *t;
	t=(node *)malloc(sizeof(node));
	printf("Enter node data: ");
	scanf("%d",t);
	while(l->data!=val)
		l=l->link;
	t->link=l->link;
	l->link=t;
	display(head);
}
void insb(node *l)
{
	int val;
	printf("Before which data,you want to insert: ");
	scanf("%d",&val);
	if (val==l->data)
		insf(head);
	else
	{
	node *t;
	t=(node *)malloc(sizeof(node));
	printf("Enter node data: ");
	scanf("%d",t);
	while(l->link->data!=val)
		l=l->link;
	t->link=l->link;
	l->link=t;
	display(head);
	}
}
void insl(node *l)
{
	while(l->link!=NULL)
		l=l->link;
	node *t;
	t=(node *)malloc(sizeof(node));
	printf("Enter node data: ");
	scanf("%d",t);
	t->link=NULL;
	l->link=t;
	display(head);
}
int main()
{
	int a;
	char ch,chr;
	head=create();
	display(head);
	printf("     Menu\n");
	printf("1  - insert after value\n");
	printf("2  - insert before value\n");
	printf("3  - insert before head\n");
	printf("4  - insert after last\n");
	do
	{
		printf("Enter Choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:insa(head);break;
			case 2:insb(head);break;
			case 3:insf(head);break;
			case 4:insl(head);break;
			default:printf("Wrong choice\n");
		}
		while(getchar()!='\n');
		printf("\nContinue? (y/n): ");
		scanf("%c",&chr);
	}while(chr=='y'||chr=='Y');	
	return 0;
}

/*Output:
Enter node data(0 to terminate): 5 15 20 0
[5 | 23517264]-->[15 | 23517296]-->[20 | 0]-->NULL
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
1
After which data,you want to insert: 5
Enter node data: 10
[5 | 23517328]-->[10 | 23517264]-->[15 | 23517296]-->[20 | 0]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
2
Before which data,you want to insert: 20
Enter node data: 50
[5 | 23517328]-->[10 | 23517264]-->[15 | 23517360]-->[50 | 23517296]-->[20 | 0]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
3
Enter node data: 25
[25 | 23517232]-->[5 | 23517328]-->[10 | 23517264]-->[15 | 23517360]-->[50 | 23517296]-->[20 | 0]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
4
Enter node data: 40
[25 | 23517232]-->[5 | 23517328]-->[10 | 23517264]-->[15 | 23517360]-->[50 | 23517296]-->[20 | 23517424]-->[40 | 0]-->NULL

Continue? (y/n): n
*/
	

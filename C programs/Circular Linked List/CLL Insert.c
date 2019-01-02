//24. To implement the operations like create insert at head, insert after, insert before, insert at end, in a circular link list.
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
void insf(node *l)
{
	node *np;
	int n;
	printf("Enter node data: ");
	scanf("%d",&n);
	np=makeNode(n);
	np->link=head;
	do
	{
		l=l->link;
	}while(l->link!=head);
	l->link=np;
	head=np;
	display(head);
}
void insa(node *l)
{
	int val;
	printf("After which data,you want to insert: ");
	scanf("%d",&val);
	int n;
	printf("Enter node data: ");
	scanf("%d",&n);
	node *np=makeNode(n);
	while(l->data!=val)
		l=l->link;
	np->link=l->link;
	l->link=np;
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
	int n;
	printf("Enter node data: ");
	scanf("%d",&n);
	node *np=makeNode(n);
	while(l->link->data!=val)
		l=l->link;
	np->link=l->link;
	l->link=np;
	display(head);
	}
}
void insl(node *l)
{
	do
	{
		l=l->link;
	}while(l->link!=head);
	int n;
	printf("Enter node data: ");
	scanf("%d",&n);
	node *np=makeNode(n);
	l->link=np;
	np->link=head;
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
		printf("Enter choice: ");
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
Enter node data(0 to terminate): 5 10 20 30 0
[5 | 12757072]-->[10 | 12757104]-->[20 | 12757136]-->[30 | 12757040]-->NULL
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
1
After which data,you want to insert: 5
Enter node data: 60
[5 | 12757168]-->[60 | 12757072]-->[10 | 12757104]-->[20 | 12757136]-->[30 | 12757040]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
2
Before which data,you want to insert: 20
Enter node data: 15
[5 | 12757168]-->[60 | 12757072]-->[10 | 12757200]-->[15 | 12757104]-->[20 | 12757136]-->[30 | 12757040]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
3
Enter node data: 50
[50 | 12757040]-->[5 | 12757168]-->[60 | 12757072]-->[10 | 12757200]-->[15 | 12757104]-->[20 | 12757136]-->[30 | 12757232]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
4
Enter node data: 40
[50 | 12757040]-->[5 | 12757168]-->[60 | 12757072]-->[10 | 12757200]-->[15 | 12757104]-->[20 | 12757136]-->[30 | 12757264]-->[40 | 12757232]-->NULL

Continue? (y/n): n

*/
	

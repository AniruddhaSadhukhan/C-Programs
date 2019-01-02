//21. To implement the operations like create insert at head, insert after,insert before, insert at end, in a double link list.
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
			last->next=np;
		
		np->prev=last;	
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
void insf(node *l)
{
	node *np;
	int n;
	printf("Enter node data: ");
	scanf("%d",&n);
	np=makeNode(n);
	np->next=head;
	head->prev=np;
	head=np;
	display(head);
}
void insa(node *l)
{
	int val,n;
	printf("After which data,you want to insert: ");
	scanf("%d",&val);
	node *np;
	printf("Enter node data: ");
	scanf("%d",&n);
	np=makeNode(n);
	while(l->data!=val)
		l=l->next;
	l->next->prev=np;
	np->next=l->next;
	np->prev=l;
	l->next=np;
	display(head);
}
void insb(node *l)
{
	int val,n;
	printf("Before which data,you want to insert: ");
	scanf("%d",&val);
	if (val==l->data)
		insf(head);
	else
	{
	node *np;
	printf("Enter node data: ");
	scanf("%d",&n);
	np=makeNode(n);
	while(l->data!=val)
		l=l->next;
	np->prev=l->prev;
	np->next=l;
	l->prev->next=np;
	l->prev=np;
	display(head);
	}
}
void insl(node *l)
{
	while(l->next!=NULL)
		l=l->next;
	node *np;
	int n;
	printf("Enter node data: ");
	scanf("%d",&n);
	np=makeNode(n);
	l->next=np;
	np->prev=l;
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
Enter node data(0 to terminate): 10 20 30 0
[4197629 | 10 | 20826192]-->[20826160 | 20 | 20826224]-->[20826192 | 30 | 0]-->NULL
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
1
After which data,you want to insert: 20
Enter node data: 25
[4197629 | 10 | 20826192]-->[20826160 | 20 | 20826256]-->[20826192 | 25 | 20826224]-->[20826256 | 30 | 0]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
2
Before which data,you want to insert: 20
Enter node data: 15
[4197629 | 10 | 20826288]-->[20826160 | 15 | 20826192]-->[20826288 | 20 | 20826256]-->[20826192 | 25 | 20826224]-->[20826256 | 30 | 0]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
3
Enter node data: 5
[0 | 5 | 20826160]-->[20826320 | 10 | 20826288]-->[20826160 | 15 | 20826192]-->[20826288 | 20 | 20826256]-->[20826192 | 25 | 20826224]-->[20826256 | 30 | 0]-->NULL

Continue? (y/n): y
     Menu
1  - insert after value
2  - insert before value
3  - insert before head
4  - insert after last
4
Enter node data: 35
[0 | 5 | 20826160]-->[20826320 | 10 | 20826288]-->[20826160 | 15 | 20826192]-->[20826288 | 20 | 20826256]-->[20826192 | 25 | 20826224]-->[20826256 | 30 | 20826352]-->[20826224 | 35 | 0]-->NULL

Continue? (y/n): n

*/
	

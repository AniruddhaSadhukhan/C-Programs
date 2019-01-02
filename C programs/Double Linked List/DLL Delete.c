//22. To implement the operations like create and delete at head, delete at end, delete with respect to position, delete with respect to value in a double link list.
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
void delhead()
{
	node *temp;
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
	display(head);
}

void delv(node *l)
{
	int val;
	node *temp;
	printf("Which value you want to delete: ");
	scanf("%d",&val);
	if (val==l->data)
		delhead();
	else
	{
	while(l->data!=val)
		l=l->next;
	temp=l;
	l->prev->next=l->next;
	l->next->prev=l->prev;
	free(temp);
	display(head);
	}
}

void dellast(node *l)
{
	node *temp;
	while(l->next!=NULL)
		l=l->next;
	temp=l;
	l->prev->next=NULL;
	free(temp);
	display(head);
}

void delp(node *l)
{
	int pos,i;
	node *temp;
	printf("From which position you want to delete: ");
	scanf("%d",&pos);
	if(pos>1 && pos<=count(head))
	{
		for(i=0;i<pos-1;i++)
			l=l->next;
		temp=l;
		l->prev->next=l->next;
		l->next->prev=l->prev;
		free(temp);
		display(head);
	}
	else if(pos==1)
	{
		delhead();
	}
	else
		printf("\nWrong position\n");
	
}
int main()
{
	int a;
	char ch,chr;
	head=create();
	display(head);
	printf("      Menu\n");
	printf("1  - delete by value\n");
	printf("2  - delete by position\n");
	printf("3  - delete at head\n");
	printf("4  - delete at last\n");
	do
	{
		printf("Enter choice: ");
		scanf("%d",&a);
		switch(a)
		{			
			case 1:delv(head);break;
			case 2:delp(head);break;
			case 3:delhead();break;
			case 4:dellast(head);break;
			default:printf("Wrong choice\n");
		}
		while(getchar()!='\n');
		printf("\nContinue? (y/n): ");
		scanf("%c",&chr);
	}while(chr=='y'||chr=='Y');	
	return 0;
}

/*Output
Enter node data(0 to terminate): 5 10 15 20 25 30 0
[4197565 | 5 | 11180112]-->[11180080 | 10 | 11180144]-->[11180112 | 15 | 11180176]-->[11180144 | 20 | 11180208]-->[11180176 | 25 | 11180240]-->[11180208 | 30 | 0]-->NULL
      Menu
1  - delete by value
2  - delete by position
3  - delete at head
4  - delete at last
1
Which value you want to delete: 25
[4197565 | 5 | 11180112]-->[11180080 | 10 | 11180144]-->[11180112 | 15 | 11180176]-->[11180144 | 20 | 11180240]-->[11180176 | 30 | 0]-->NULL

Continue? (y/n): y
      Menu
1  - delete by value
2  - delete by position
3  - delete at head
4  - delete at last
2
From which position you want to delete: 3
[4197565 | 5 | 11180112]-->[11180080 | 10 | 11180176]-->[11180112 | 20 | 11180240]-->[11180176 | 30 | 0]-->NULL

Continue? (y/n): y
      Menu
1  - delete by value
2  - delete by position
3  - delete at head
4  - delete at last
3
[0 | 10 | 11180176]-->[11180112 | 20 | 11180240]-->[11180176 | 30 | 0]-->NULL

Continue? (y/n): y
      Menu
1  - delete by value
2  - delete by position
3  - delete at head
4  - delete at last
4
[0 | 10 | 11180176]-->[11180112 | 20 | 0]-->NULL

Continue? (y/n): n

*/

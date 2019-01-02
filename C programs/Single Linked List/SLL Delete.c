//19. To implement create and delete at head, delete at end, delete with respect to position, delete with respect to value in a single link list.
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
void delhead()
{
	node *temp;
	temp=head;
	head=head->link;
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
	while(l->link->data!=val)
		l=l->link;
	temp=l->link;
	l->link=l->link->link;
	free(temp);
	display(head);
	}
}
void dellast(node *l)
{
	node *temp;
	while(l->link->link!=NULL)
		l=l->link;
	temp=l->link;
	l->link=NULL;
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
		for(i=0;i<pos-2;i++)
			l=l->link;
		temp=l->link;
		l->link=l->link->link;
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
		printf("Enter Choice: ");
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

/*Sample output
Enter node data(0 to terminate): 5 10 15 20 25 30 0
[5 | 34011216]-->[10 | 34011248]-->[15 | 34011280]-->[20 | 34011312]-->[25 | 34011344]-->[30 | 0]-->NULL
      Menu
1  - delete by value
2  - delete by position
3  - delete at head
4  - delete at last
1
Which value you want to delete: 25
[5 | 34011216]-->[10 | 34011248]-->[15 | 34011280]-->[20 | 34011344]-->[30 | 0]-->NULL

Continue? (y/n): y
      Menu
1  - delete by value
2  - delete by position
3  - delete at head
4  - delete at last
2
From which position you want to delete: 3
[5 | 34011216]-->[10 | 34011280]-->[20 | 34011344]-->[30 | 0]-->NULL

Continue? (y/n): y
      Menu
1  - delete by value
2  - delete by position
3  - delete at head
4  - delete at last
3
[10 | 34011280]-->[20 | 34011344]-->[30 | 0]-->NULL

Continue? (y/n): y
      Menu
1  - delete by value
2  - delete by position
3  - delete at head
4  - delete at last
4
[10 | 34011280]-->[20 | 0]-->NULL

Continue? (y/n): n

*/

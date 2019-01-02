//49. Implementation of collision resolution technique (separate chaining).
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head[10];
int hash(int n)
{
	return n%10;
}
void insert()
{
	int n,h;
	printf("Enter values to insert,0 to stop: \n");
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		h=hash(n);
		node *tmp,*p;
		tmp=(node *)malloc(sizeof(node));
		tmp->data=n;
		if(head[h] == NULL || n < head[h]->data )
		{
			tmp->link=head[h];
			head[h]=tmp;
		}
		else
		{
			p = head[h];
			while( p->link!=NULL && p->link->data < n )
				p=p->link;
			tmp->link=p->link;
			p->link=tmp;
		}
	}	
}
void display()
{
	int i;
	node*l;
	printf("Hash Table \n");
	printf("Index    Data \n");
	for(i=0;i<10;i++)
	{
		l=head[i];
		printf("%3d     ",i);
		while (l!=NULL)
		{
			printf("%3d ",l->data);l=l->link;
		}
		printf("\n");	
	}
}
void search()
{
	int val;
	node *l;
	printf("Enter value to search: \n");
	scanf("%d",&val);
	l=head[hash(val)];
	while(l!=NULL && l->data <= val)
	{
		if(val==l->data)
		{
			printf("Found \n");
			return;
		}
		l=l->link;
	}
		
	printf("Not Found \n");
}
int main()
{
	insert();
	display();
	search();
	return 0;
}
/*Output
Enter values to insert,0 to stop: 
71 25 14 53 29 47 39 23 34 33 0
Hash Table 
Index    Data 
  0     
  1      71 
  2     
  3      23  33  53 
  4      14  34 
  5      25 
  6     
  7      47 
  8     
  9      29  39 
Enter value to search: 
33
Found 
*/

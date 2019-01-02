//27. Polynomial representation using link list.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int exp;
    struct node *link;
}node;

node *head;

node *makeNode(int n,int e)
{
    node *np = (node *)malloc(sizeof(node));
    np->data = n;
    np->exp = e;
    np->link = NULL;
    return np;
}
node *insert(node *l,int n,int e)
{
    node *start=l,*np;
    if(l==NULL || e > l->exp)
    {         
        np=makeNode(n,e);
        np->link=start; 
        
        start=np;
    }

    else
    {
        while(l->exp > e && l->link!=NULL)
            l=l->link;
        
        if (l->exp == e)    //if same exp ,add coeff
            l->data =l->data + n;
        else if (l->link == NULL && l->exp > e)
        {
        	 np=makeNode(n,e);
        	 l->link=np; 
        	}
        else  //else add in sorted manner
        {
            np=makeNode(l->data,l->exp);
            l->data=n;
            l->exp=e;
            l->link=np;
        }

    }
    return start;
}

node *create(void)
{
    int n,e;
    char c='y';
    node *np,*start;
    start=NULL;
    while (c=='y'||c=='Y')
    {
        printf("Enter coefficient: ");
        scanf("%d",&n);
        printf("Enter exponent: ");
        scanf("%d",&e);
        start=insert(start,n,e);
        while(getchar()!='\n');
        printf("Continue?(y/n): ");
        scanf("%c",&c);
    }
    return start;
}


void display(node *l)
{
    while(l!=NULL)
    {
        if(l->exp > 1 ||l->exp < 0)
        	printf("[%d x^%d] + ",l->data,l->exp);
        else if(l->exp == 1) 
        	printf("[%d x] + ",l->data);
        else 
        	printf("[%d] + ",l->data);
        l=l->link;
    }
    printf("\b\b= 0\n");
}

int main()
{
    int a;
    char ch,chr;
    head=create();
    display(head);
    return 0;
}
/* Output:
Enter coefficient: 2
Enter exponent: 0
Continue?(y/n): y
Enter coefficient: 5
Enter exponent: 2
Continue?(y/n): y
Enter coefficient: 6
Enter exponent: 3
Continue?(y/n): y
Enter coefficient: 4
Enter exponent: 1
Continue?(y/n): n
[6 x^3] + [5 x^2] + [4 x] + [2] = 0
*/


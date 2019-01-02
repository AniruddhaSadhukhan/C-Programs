//61. Traverse a Binary Search Tree (Inorder, Poetorder, Preeorder) (NON RECURSIVE)  
#include <stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
node *head=NULL;
typedef struct stack
{
        int top;
        node *items[STACK_SIZE];
}stack;
 node *makeNode(int n)
{
	node *temp =(node *)malloc(sizeof(node));
	temp->data = n;
	temp->left = temp->right = NULL;
	return temp;
}
void push(stack *ms, node *item)
{
   if(ms->top < STACK_SIZE-1)   
       ms->items[++(ms->top)] = item; 
   else 
       printf("Stack is full\n");
}
node * pop (stack *ms)
{
   if(ms->top > -1 )
       return ms->items[(ms->top)--]; 
   else
       printf("Stack is empty\n");
}

int isEmpty(stack ms){
   if(ms.top < 0) return 1;
   else return 0;
}
void inorderTraversal(node *root)
{
	stack ms;
	ms.top = -1;
	node *currentnode  = root;
	while(!isEmpty(ms) || currentnode )
	{
		if(currentnode)
		{
			push(&ms, currentnode);
			currentnode = currentnode->left;
		}
		else 
		{
			currentnode = pop(&ms);
			printf("%d  ", currentnode->data);
			currentnode = currentnode->right;
		}
	}
}
void preorderTraversal(node *root)
{
	stack ms;
	ms.top = -1;
	node *currentNode = NULL;
	push(&ms,root);	// Start with root 
	while(!isEmpty(ms))
	{
		
		currentNode = pop(&ms);		
		printf("%d  ", currentNode->data);
		if(currentNode->right)
			push(&ms, currentNode->right);	// Push right child first 
		if(currentNode->left)
			push(&ms, currentNode->left);	// Push left child 
	}
}
node *peek(stack ms)
{
  if(ms.top < 0)
  {
      printf("Stack empty\n");
      return 0;
  }
   return ms.items[ms.top];
}
void postorderTraversal(node *root)
{
    stack ms;
    ms.top = -1;
    node *currentNode = NULL ;
    push(&ms,root);
    node *prev = NULL;
    while(!isEmpty(ms))
    {
        currentNode = peek(ms);
        /* case 1. We are moving down the tree. */
        if(prev == NULL || prev->left == currentNode || prev->right == currentNode)
        {
		if(currentNode->left)
			push(&ms,currentNode->left);
		else if(currentNode->right)
			push(&ms,currentNode->right);
		else 
		{
                	/* If node is leaf node */
               		 printf("%d  ", currentNode->data);
                	pop(&ms);
            	}
        }
         /* case 2. We are moving up the tree from left child */
        if(currentNode->left == prev)
        {
            if(currentNode->right)
                push(&ms,currentNode->right);
            else 
            {
                printf("%d  ", currentNode->data);
                pop(&ms);
            }
        }
        /* case 3. We are moving up the tree from right child */
         if(currentNode->right == prev)
         {
              printf("%d  ", currentNode->data);
              pop(&ms);
         }
         prev = currentNode;
      }
}
node* insert(node *p,int data)//insert a new node with given data in BST */
{
	if (p == NULL) return makeNode(data);
	if (data < p->data)
        	p->left  = insert(p->left,data);
    	else if (data > p->data)
        	p->right = insert(p->right,data);   
}
int main()
{
    /* Creating following BST
             50
           /    \
          30     70
        /   \   /   \
       20   40 60   80 */
    head = insert(head, 50);
    insert(head, 30);
    insert(head, 20);
    insert(head, 40);
    insert(head, 70);
    insert(head, 60);
    insert(head, 80); 
    printf("Inorder   : ");
    inorderTraversal(head);// print inoder traversal of the BST
    printf("\nPreorder  : ");
    preorderTraversal(head);// print preorder traversal of the BST
    printf("\nPostorder : ");
    postorderTraversal(head);// print postorder traversal of the BST
    printf("\n");
    return 0;
}
/*Output
Inorder   : 20   30   40   50   60   70   80   
Preorder  : 50   30   20   40   70   60   80   
Postorder : 20   40   30   60   80   70   50
*/

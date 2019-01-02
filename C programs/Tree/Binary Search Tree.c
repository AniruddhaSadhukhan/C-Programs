//59. Implement a Binary Search Tree. 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
}node;
node *head=NULL;
node *makeNode(int n)
{
	node *temp =(node *)malloc(sizeof(node));
	temp->data = n;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(node *root)	//display inorder traversal of BST
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d   ", root->data);
        inorder(root->right);
    }
}
node* insert(node *p,int data)//insert a new node with given key in BST */
{
	if (p == NULL) return makeNode(data);
	if (data < p->data)
        	p->left  = insert(p->left,data);
    	else if (data > p->data)
        	p->right = insert(p->right,data);   
    	//return p; //return the (unchanged) node pointer
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
    inorder(head);// print inoder traversal of the BST
    printf("\n");
    return 0;
}
/*Output
20   30   40   50   60   70   80   
*/

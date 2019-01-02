//63. Implement a AVL Tree.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
}node;
//function to get height of the tree
int height(node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
//function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}
node* newNode(int key)
{
	node* n = (node*)malloc(sizeof(node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	n->height = 1; // new node is initially added at leaf
	return(n);
}
//function to right rotate subtree rooted with y
node *rightRotate(node *y)
{
	node *x = y->left;
	node *T2 = x->right;
	// Perform rotation
	x->right = y;
	y->left = T2;
	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	// Return new root
	return x;
}
//function to left rotate subtree rooted with x
node *leftRotate(node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	// Perform rotation
	y->left = x;
	x->right = T2;
	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	// Return new root
	return y;
}
// Get Balance factor of node N
int getBalance(node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
node* insert(node* N, int key)
{
	/*Perform the normal BST insertion */
	if (N == NULL)
		return(newNode(key));

	if (key < N->key)
		N->left = insert(N->left, key);
	else if (key > N->key)
		N->right = insert(N->right, key);
	else // Equal keys are not allowed in BST
		return N;

	/*Update height of this ancestor node */
	N->height = 1 + max(height(N->left),height(N->right));

	/*Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(N);
	// If this node becomes unbalanced, then
	// there are 4 cases
	// Left Left Case
	if (balance > 1 && key < N->left->key)
		return rightRotate(N);
	// Right Right Case
	if (balance < -1 && key > N->right->key)
		return leftRotate(N);
	// Left Right Case
	if (balance > 1 && key > N->left->key)
	{
		N->left = leftRotate(N->left);
		return rightRotate(N);
	}
	// Right Left Case
	if (balance < -1 && key < N->right->key)
	{
		N->right = rightRotate(N->right);
		return leftRotate(N);
	}
	/* return the (unchanged) node pointer */
	return N;
}
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main()
{
	node *root = NULL;
	/* Constructing tree */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

/* The constructed AVL Tree would be
		 30
	       /   \
	      20    40
            /   \     \
          10    25     50
*/

	printf("Preorder traversal of the AVL tree is \n");
	preOrder(root);
	printf("\n");
	return 0;
}
/*Output:
Preorder traversal of the constructed AVL tree is 
30 20 10 25 40 50 
*/

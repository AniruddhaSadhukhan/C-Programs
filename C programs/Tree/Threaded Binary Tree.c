//62.Implement and traverse a Threaded Binary Tree. 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define false 0
#define true 1
#define NUM_NODES 50
typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
	int isRightThread;
}Node;
typedef struct Queue 
{
	int front;
	int rear;
	Node * items[NUM_NODES];
}Queue;
void initializeQueue( Queue **queue )
{
	Queue *q =(Queue *)malloc(sizeof(Queue));
	if(q)
	{
		q->front = 0;
		q->rear = 0;
	}
	*queue = q;
}
int isEmpty( Queue *q)
{
	if(q->front == q->rear )
		return true;
	return false;
}
void enqueue( Queue *q, Node * node)
{
	if(q)
		q->items[(q->rear)++] = node;	
}

Node * dequeue( Queue *q)
{
	if(!isEmpty(q))
		return q->items[(q->front)++];
	return NULL;
}
Node * front( Queue *q)
{
	if(!isEmpty(q))
		return q->items[(q->front)];
	return NULL;
}
void feedQueue( Node * root, Queue *q )
{
	if(!root) return;
	feedQueue(root->left, q);
	enqueue(q, root);
	feedQueue(root->right, q);
}
void createThreads( Node * root, Queue *q)
{
	if(!root) return;
	if(root->left) createThreads (root->left, q);
	dequeue(q);
	if(root->right) createThreads (root->right, q);
	else
	{
		root->right = front(q);
		root->isRightThread = true;
	}
}
void createThreadedTree(Node * root)
{
	Queue *q = NULL;
	initializeQueue(&q);
	feedQueue(root, q);
	createThreads(root, q);
}
Node * leftMostNode( Node * root )
{
	while( root && root->left ) root = root->left;
	return root;
}
void inoderTraversalUsingThreads(Node * root)
{
	Node * currentNode = leftMostNode(root);
	while(currentNode)
	{
		printf("%d ", currentNode->value);
		if(currentNode->isRightThread)
			currentNode = currentNode->right;
		else
			currentNode = leftMostNode(currentNode->right);
	}
}
Node *createNode(int value)
{
	Node * newNode =  (Node *)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;
	newNode->isRightThread = false;
	return newNode;
}
Node *addNode(Node *node, int value)
{
	if(!node)
		return createNode(value);
	if (node->value > value)
		node->left = addNode(node->left, value);
	else
		node->right = addNode(node->right, value );
		
	return node;
}
int main()
{
	Node *root = NULL;
	/* Creating following BST
             50
           /    \
          30     70
        /   \   /   \
       20   40 60   80 */
	root = addNode(root, 50);
	root = addNode(root, 30);
	root = addNode(root, 20);
	root = addNode(root, 40);
	root = addNode(root, 70);
	root = addNode(root, 60);
	root = addNode(root, 80);
	createThreadedTree(root);
	printf("Inorder traversal using threads:\n");
	inoderTraversalUsingThreads(root);
	printf("\n");
	return 0;
}
/*Output
Inorder traversal using threads:
20 30 40 50 60 70 80
*/


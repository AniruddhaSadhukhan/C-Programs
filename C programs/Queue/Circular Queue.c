//39. Implement Circular-Queue. 
#include<stdio.h>
#define SIZE 5
int q[SIZE],front=0,rear=0;
void insert()
{
    int x;
    if((rear+1)%SIZE==front)
        printf("Queue is overflow\n");
    else
    {
        printf("Enter element to be insert:");
        scanf("%d",&x);
	q[rear++]=x;
	rear=rear%SIZE;
    }
}
void  delete()
{ 
    if(front==rear)
    {
        printf("Queue is underflow\n");
      	return;
    }
    else
    {
    	int a;
    	a=q[front++];
    	front=front%SIZE;
    }
}
void display()
{
    int i;
    if(front == rear)
        printf("\nQueue is Empty!!!");
     else
     {
        printf("Circular-Queue:");
        for(i=(front); i%SIZE!=rear; i++)
           	printf(" %d ",q[i%SIZE]);     
     }
}
int main()
{
    int ch;
    printf("\nCircular Queue operations\n");
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: insert();display();
            break;
        case 2: delete();display();
            break;
        case 3:display();
            break;
        case 4:return 0;
        default:printf("Invalid option\n");
        }
    }
}
/*Output:
Circular Queue operations
1.insert
2.delete
3.display
4.exit

Enter your choice:1
Enter element to be insert:5
Circular-Queue: 5 
Enter your choice:1
Enter element to be insert:10
Circular-Queue: 5  10 
Enter your choice:1
Enter element to be insert:20
Circular-Queue: 5  10  20 
Enter your choice:1
Enter element to be insert:30
Circular-Queue: 5  10  20  30 
Enter your choice:1
Queue is overflow
Circular-Queue: 5  10  20  30 
Enter your choice:2
Circular-Queue: 10  20  30 
Enter your choice:2
Circular-Queue: 20  30 
Enter your choice:1
Enter element to be insert:40
Circular-Queue: 20  30  40 
Enter your choice:2
Circular-Queue: 30  40 
Enter your choice:4
*/



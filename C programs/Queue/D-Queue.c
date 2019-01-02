//38. Implement D-Queue. 
#include<stdio.h>
#define SIZE 100
int queue[SIZE];
int rear = SIZE/2, front = SIZE/2;
void enQueueRear(int value)
{   
     char ch;
     
      do
      {
      		if(front == SIZE)
      
      		{
            	printf("\nQueue is full!!! Insertion is not possible!!! ");
            	return;
      		}
            printf("Enter value:");
            scanf("%d",&value);
            queue[front++] = value;
            printf("Do you want to continue insertion Y/N ");
            while(getchar()!='\n');
            ch=getchar();
      }while(ch=='y');
}
void enQueueFront(int value)
{   
     char ch; 
      do
      {
      		if(rear==0)
      		{
            	printf("\nQueue is full!!! Insertion is not possible!!!");
            	return;
      		}
            printf("Enter value:");
            scanf("%d",&value);
            queue[--rear] = value;
            printf("Do you want to continue insertion Y/N ");
            while(getchar()!='\n');
            ch = getchar();
      }
      while(ch == 'y');
}
int deQueueRear()
{
     int deleted;
     if(front == rear)
     {
            printf("\nQueue is Empty!!!");
            return 0;
     } 
     return queue[--front];
}
int deQueueFront()
{
     if(front == rear)
     {
            printf("\nQueue is Empty!!!");
            return 0;
     }
     return queue[rear++];
}
void display()
{
     int i;
     if(front == rear)
        printf("\nQueue is Empty!!!");
     else{
        printf("\nD-Queue:");
        for(i=rear; i < front; i++)
        {
           printf(" %d ",queue[i]);
        }
     }
}
int main()
{
	char ch;
	int a, value;
	printf("\nSelect the Operation\n");
	printf("1.Insert at Rear\n2. Insert at Front\n3.Delete from Rear\n4.Delete from Front\n");
	do
	{
		printf("\nEnter your choice for the operation in C deque: ");
		scanf("%d",&a);
		switch(a)
		{   
			case 1: enQueueRear(value);
					display();
					break;
			case 2: enQueueFront(value);
					display();
					break;
			case 3: value = deQueueRear();
					printf("\nThe value deleted is %d",value);
					display();
					break;
			case 4: value=deQueueFront();
					printf("\nThe value deleted is %d",value);
					display();
					break;
			default:printf("Wrong choice");
		}
		printf("\nContinue?(Y/N): ");
		while(getchar()!='\n');
		ch=getchar();
	}while(ch=='y'||ch=='Y');
    return 0;
}                   
/*Output:
Select the Operation
1.Insert at Rear
2. Insert at Front
3.Delete from Rear
4.Delete from Front

Enter your choice for the operation in C deque: 1
Enter value:5
Do you want to continue insertion Y/N y
Enter value:10
Do you want to continue insertion Y/N n
D-Queue: 5  10 
Continue?(Y/N): y
Enter your choice for the operation in C deque: 2
Enter value:20
Do you want to continue insertion Y/N y
Enter value:30
Do you want to continue insertion Y/N n
D-Queue: 30  20  5  10 
Continue?(Y/N): y
Enter your choice for the operation in C deque: 3
The value deleted is 10
D-Queue: 30  20  5 
Continue?(Y/N): y
Enter your choice for the operation in C deque: 4
The value deleted is 30
D-Queue: 20  5 
Continue?(Y/N): n
*/

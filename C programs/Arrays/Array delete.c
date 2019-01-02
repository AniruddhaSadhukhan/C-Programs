//2. Create an array and delete an element from the array. 

#include <stdio.h> 
int main()
{
	int arr[100], pos,i,n;
  	printf("Enter size: ");
   	scanf("%d",&n);
   	printf("Enter %d elements: ",n);
   	for (i= 0;i<n;i++)
      		scanf("%d",&arr[i]);
 	printf("Enter the location to delete element: ");
   		scanf("%d", &pos);
 	for (i=pos-1;i<n-1;i++)
         	arr[i] = arr[i+1];
      	printf("Resultant array is: ");
 	for (i= 0;i<n-1;i++)
        printf("%d ",arr[i]);
        printf("\n");
  	return 0;
}
/*Output:
Enter size
5
Enter 5 elements
5 10 15 20 25
Enter the location to delete element
3
Resultant array is
5 10 20 25*/

//3. Creation of 1D array dynamically. 
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
	int *arr,i,n;
  	printf("Enter size: ");
   	scanf("%d",&n);
   	arr=(int*)malloc(sizeof(int)*n);
   	printf("Enter %d elements: ",n);
   	for (i= 0;i<n;i++)
      		scanf("%d",&arr[i]);
      	printf("Array is: ");
 	for (i= 0;i<n;i++)
        printf("%d ",arr[i]);
        printf("\n");
  	return 0;
}
/*Output:
Enter size
5
Enter 5 elements
5 10 20 30 57
Array is: 5 10 20 30 57*/

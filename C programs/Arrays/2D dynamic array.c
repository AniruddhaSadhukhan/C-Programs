//4. Creation of 2D array dynamically. 
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
	int **arr,i,j,r,c;
  	printf("Enter rows & columns\n");
   	scanf("%d%d",&r,&c);
   	arr=(int**)malloc(sizeof(int*)*r);
   	for (i=0;i<r;i++)
   		arr[i]=(int*)malloc(sizeof(int)*c);
   	for (i=0;i<r;i++)
   		for (j=0;j<c;j++)
   		{
   			printf("a[%d][%d]=",i,j);
      			scanf("%d",&arr[i][j]);
      		}
      	printf("Array is:\n");
 	for (i=0;i<r;i++)
 	{
 		for (j=0;j<c;j++)   	
   			printf("%d ",arr[i][j]); 
   		printf("\n");  
 	}
   		   			
  	return 0;
}
/*Output:
Enter rows & columns
2 3
a[0][0]=5
a[0][1]=32
a[0][2]=9
a[1][0]=6
a[1][1]=2
a[1][2]=96
Array is: 
5 32 9 
6 2 96 
*/

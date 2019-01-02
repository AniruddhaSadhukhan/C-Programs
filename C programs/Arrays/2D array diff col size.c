//5. Creation of 2D array (with different column size)dynamically  
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
	int **arr,i,j,r,*c;
  	printf("Enter rows: ");
   	scanf("%d",&r);
   	arr=(int**)malloc(sizeof(int*)*r);
   	c=(int*)malloc(sizeof(int)*r);
   	for (i=0;i<r;i++)
   	{
   		printf("Enter number of columns for %d row: ",i);
 		scanf("%d",&c[i]);
 		arr[i]=(int*)malloc(sizeof(int)*c[i]);
 		for (j=0;j<c[i];j++)
   		{
   			printf("a[%d][%d]=",i,j);
      			scanf("%d",&arr[i][j]);
      		}	
   	}
   		
      	printf("Array is:\n");
 	for (i=0;i<r;i++)
 	{
 		for (j=0;j<c[i];j++)   	
   			printf("%d ",arr[i][j]); 
   		printf("\n");  
 	}
   		   			
  	return 0;
}
/*Output:
Enter rows: 4
Enter number of columns for 0 row: 4
a[0][0]=5
a[0][1]=10
a[0][2]=20
a[0][3]=30
Enter number of columns for 1 row: 1
a[1][0]=50
Enter number of columns for 2 row: 5
a[2][0]=15
a[2][1]=25
a[2][2]=35
a[2][3]=45
a[2][4]=55
Enter number of columns for 3 row: 3
a[3][0]=40
a[3][1]=90
a[3][2]=60
Array is:
5 10 20 30 
50 
15 25 35 45 55 
40 90 60 
*/

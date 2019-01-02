//7. Creation of the shortcut form of sparse Matrix
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
	int **arr,**spr,i,j,r,c,nz=0,k=1;
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
      			if(arr[i][j]!=0)
      				nz++;
      		}
      	printf("Sparce matrix is:\n");
 	for (i=0;i<r;i++)
 	{
 		for (j=0;j<c;j++)   	
   			printf("%d ",arr[i][j]); 
   		printf("\n");  
 	}
   	
   	spr=(int**)malloc(sizeof(int*)*(nz+1));
   	for (i=0;i<nz+1;i++)
   		spr[i]=(int*)malloc(sizeof(int)*3);
   	printf("Shortcut of Sparce matrix is:\n");
   	spr[0][0]=r;spr[0][1]=c;spr[0][2]=nz;
   	for (i=0;i<r;i++)
   		for (j=0;j<c;j++)
   			if(arr[i][j]!=0)
   			{
   				spr[k][0]=i;
   				spr[k][1]=j;
   				spr[k][2]=arr[i][j];
   				k++;
   			}
      	for (i=0;i<nz+1;i++)
      	{
      		for (j=0;j<3;j++)
      			printf("%d ",spr[i][j]); 		
      		printf("\n");	
      	}		
  	return 0;
}
/*Output:Enter rows & columns
2 3
a[0][0]=0
a[0][1]=0
a[0][2]=1
a[1][0]=5
a[1][1]=0
a[1][2]=0
Sparce matrix is:
0 0 1 
5 0 0 
Shortcut of Sparce matrix is:
2 3 2 
0 2 1 
1 0 5 
*/

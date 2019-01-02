//9. Multiplication of two sparse matrix using shortcut representations  
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
	int **arr1,**arr2,**spr1,**spr2,**spr,i,j,r1,c1,r2,c2,nz1=0,nz2=0,k,flag;
  	printf("Enter row & column of 1st matrix\n");
   	scanf("%d%d",&r1,&c1);
   	/*1st matrix*/
   	arr1=(int**)malloc(sizeof(int*)*r1);
   	for (i=0;i<r1;i++)
   		arr1[i]=(int*)malloc(sizeof(int)*c1);
   	for (i=0;i<r1;i++)
   		for (j=0;j<c1;j++)
   		{
   			printf("a[%d][%d]=",i,j);
      			scanf("%d",&arr1[i][j]);
      			if(arr1[i][j]!=0)
      				nz1++;
      		}
      	printf("Sparce matrix is:\n");
 	for (i=0;i<r1;i++)
 	{
 		for (j=0;j<c1;j++)   	
   			printf("%d ",arr1[i][j]); 
   		printf("\n");  
 	}
   	/*creating shortcut matrix 1*/
   	spr1=(int**)malloc(sizeof(int*)*(nz1+1));
   	for (i=0;i<nz1+1;i++)
   		spr1[i]=(int*)malloc(sizeof(int)*3);
   	printf("Shortcut of Sparce matrix is:\n");
   	spr1[0][0]=r1;spr1[0][1]=c1;spr1[0][2]=nz1;
   	k=1;
   	for (i=0;i<r1;i++)
   		for (j=0;j<c1;j++)
   			if(arr1[i][j]!=0)
   			{
   				spr1[k][0]=i;
   				spr1[k][1]=j;
   				spr1[k][2]=arr1[i][j];
   				k++;
   			}
      	for (i=0;i<nz1+1;i++)
      	{
      		for (j=0;j<3;j++)
      			printf("%d ",spr1[i][j]); 		
      		printf("\n");	
      	}
      	
      	/*2nd matrix*/
      	printf("2nd matrix:Row=%d & column = ",c1);
      	r2=c1;
   	scanf("%d",&c2);
   	arr2=(int**)malloc(sizeof(int*)*r2);
   	for (i=0;i<r2;i++)
   		arr2[i]=(int*)malloc(sizeof(int)*c2);
   	for (i=0;i<r2;i++)
   		for (j=0;j<c2;j++)
   		{
   			printf("a[%d][%d]=",i,j);
      			scanf("%d",&arr2[i][j]);
      			if(arr2[i][j]!=0)
      				nz2++;
      		}
      	printf("Sparce matrix is:\n");
 	for (i=0;i<r2;i++)
 	{
 		for (j=0;j<c2;j++)   	
   			printf("%d ",arr2[i][j]); 
   		printf("\n");  
 	}
   	/*creating shortcut matrix 2*/
   	spr2=(int**)malloc(sizeof(int*)*(nz2+1));
   	for (i=0;i<nz2+1;i++)
   		spr2[i]=(int*)malloc(sizeof(int)*3);
   	printf("Shortcut of Sparce matrix is:\n");
   	spr2[0][0]=r2;spr2[0][1]=c2;spr2[0][2]=nz2;
   	k=1;
   	for (i=0;i<r2;i++)
   		for (j=0;j<c2;j++)
   			if(arr2[i][j]!=0)
   			{
   				spr2[k][0]=i;
   				spr2[k][1]=j;
   				spr2[k][2]=arr2[i][j];
   				k++;
   			}
      	for (i=0;i<nz2+1;i++)
      	{
      		for (j=0;j<3;j++)
      			printf("%d ",spr2[i][j]); 		
      		printf("\n");	
      	}
      	/*Multiplication*/
      	
      	spr=(int**)malloc(sizeof(int*)*(r1*c2+1));
   	for (i=0;i<r1*c2+1;i++)
   		spr[i]=(int*)malloc(sizeof(int)*3);
   	k=1;	
   	for(i=1;i<nz2+1;i++)
   	{
   		for(j=1;j<nz1+1;j++)
   		{
   			if(spr2[i][0]==spr1[j][1])
   			{
   				spr[k][2]=spr2[i][2]*spr1[j][2];
   				spr[k][1]=spr2[i][1];
   				spr[k][0]=spr1[j][0];
   				k++;
   			}
   		} 		
   	}	
   	printf("Shortcut of Resultant Sparce matrix is:\n");
   	spr[0][0]=r1;spr[0][1]=c2;spr[0][2]=k-1;
   	for (i=0;i<k;i++)
      	{
      		for (j=0;j<3;j++)
      			printf("%d ",spr[i][j]); 		
      		printf("\n");	
      	}		
  	return 0;
}
/*Output:
Enter row & column of 1st matrix
4 4
a[0][0]=0
a[0][1]=0
a[0][2]=0
a[0][3]=0
a[1][0]=0
a[1][1]=0
a[1][2]=2
a[1][3]=0
a[2][0]=00
a[2][1]=0
a[2][2]=1
a[2][3]=9
a[3][0]=0
a[3][1]=0
a[3][2]=0
a[3][3]=5
Sparce matrix is:
0 0 0 0 
0 0 2 0 
0 0 1 9 
0 0 0 5 
Shortcut of Sparce matrix is:
4 4 4 
1 2 2 
2 2 1 
2 3 9 
3 3 5 
2nd matrix:Row=4 & column = 4
a[0][0]=0
a[0][1]=1
a[0][2]=0
a[0][3]=0
a[1][0]=0
a[1][1]=0
a[1][2]=2
a[1][3]=0
a[2][0]=0
a[2][1]=1
a[2][2]=0
a[2][3]=1
a[3][0]=1
a[3][1]=0
a[3][2]=0
a[3][3]=0
Sparce matrix is:
0 1 0 0 
0 0 2 0 
0 1 0 1 
1 0 0 0 
Shortcut of Sparce matrix is:
4 4 5 
0 1 1 
1 2 2 
2 1 1 
2 3 1 
3 0 1 
Shortcut of Resultant Sparce matrix is:
4 4 6 
1 1 2 
2 1 1 
1 3 2 
2 3 1 
2 0 9 
3 0 5 

*/

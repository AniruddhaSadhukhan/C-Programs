//8. Addition of two sparse matrix using shortcut representations  
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
	int **arr1,**arr2,**spr1,**spr2,**spr,i,j,r,c,nz1=0,nz2=0,k,flag;
  	printf("Enter rows & columns\n");
   	scanf("%d%d",&r,&c);//addition works on matrix of same rows and columns
   	/*1st matrix*/
   	arr1=(int**)malloc(sizeof(int*)*r);
   	for (i=0;i<r;i++)
   		arr1[i]=(int*)malloc(sizeof(int)*c);
   	for (i=0;i<r;i++)
   		for (j=0;j<c;j++)
   		{
   			printf("a[%d][%d]=",i,j);
      			scanf("%d",&arr1[i][j]);
      			if(arr1[i][j]!=0)
      				nz1++;
      		}
      	printf("Sparce matrix is:\n");
 	for (i=0;i<r;i++)
 	{
 		for (j=0;j<c;j++)   	
   			printf("%d ",arr1[i][j]); 
   		printf("\n");  
 	}
   	/*creating shortcut matrix 1*/
   	spr1=(int**)malloc(sizeof(int*)*(nz1+1));
   	for (i=0;i<nz1+1;i++)
   		spr1[i]=(int*)malloc(sizeof(int)*3);
   	printf("Shortcut of Sparce matrix is:\n");
   	spr1[0][0]=r;spr1[0][1]=c;spr1[0][2]=nz1;
   	k=1;
   	for (i=0;i<r;i++)
   		for (j=0;j<c;j++)
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
   	arr2=(int**)malloc(sizeof(int*)*r);
   	for (i=0;i<r;i++)
   		arr2[i]=(int*)malloc(sizeof(int)*c);
   	for (i=0;i<r;i++)
   		for (j=0;j<c;j++)
   		{
   			printf("a[%d][%d]=",i,j);
      			scanf("%d",&arr2[i][j]);
      			if(arr2[i][j]!=0)
      				nz2++;
      		}
      	printf("Sparce matrix is:\n");
 	for (i=0;i<r;i++)
 	{
 		for (j=0;j<c;j++)   	
   			printf("%d ",arr2[i][j]); 
   		printf("\n");  
 	}
   	/*creating shortcut matrix 2*/
   	spr2=(int**)malloc(sizeof(int*)*(nz2+1));
   	for (i=0;i<nz2+1;i++)
   		spr2[i]=(int*)malloc(sizeof(int)*3);
   	printf("Shortcut of Sparce matrix is:\n");
   	spr2[0][0]=r;spr2[0][1]=c;spr2[0][2]=nz2;
   	k=1;
   	for (i=0;i<r;i++)
   		for (j=0;j<c;j++)
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
      	/*Addition*/
      	
      	spr=(int**)malloc(sizeof(int*)*(nz1+nz2+1));
   	for (i=0;i<nz1+nz2+1;i++)
   		spr[i]=(int*)malloc(sizeof(int)*3);
   	for(i=1;i<nz1+1;i++)//copy first one to result
   	{
   		spr[i][0]=spr1[i][0];
   		spr[i][1]=spr1[i][1];
   		spr[i][2]=spr1[i][2];
   	}
   	k=nz1+1;	
   	for(i=1;i<nz2+1;i++)
   	{
   		flag=0;
   		for(j=1;j<nz1+1;j++)//checking if already present
   		{
   			if(spr2[i][0]==spr[j][0]&&spr2[i][1]==spr[j][1])
   			{
   				spr[j][2]=spr[j][2]+spr2[i][2];
   				flag=1;
   				break;
   			}
   		}
   		if(flag==0)//not present,copy to result
   		{
   			spr[k][0]=spr2[i][0];
   			spr[k][1]=spr2[i][1];
   			spr[k][2]=spr2[i][2];
   			k++;
   		}
   	}	
   	printf("Shortcut of Resultant Sparce matrix is:\n");
   	spr[0][0]=r;spr[0][1]=c;spr[0][2]=k-1;
   	for (i=0;i<k;i++)
      	{
      		for (j=0;j<3;j++)
      			printf("%d ",spr[i][j]); 		
      		printf("\n");	
      	}		
  	return 0;
}
/*Output:
Enter rows & columns
4 4
a[0][0]=0
a[0][1]=0
a[0][2]=0
a[0][3]=0
a[1][0]=0
a[1][1]=0
a[1][2]=2
a[1][3]=0
a[2][0]=0
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
4 4 7 
1 2 4 
2 2 1 
2 3 10 
3 3 5 
0 1 1 
2 1 1 
3 0 1 

*/

//6. Dynamically allocate memory for 3D array.   
#include <stdio.h> 
#include <stdlib.h> 
#define MAXX 10
#define MAXY 10
#define MAXZ 10
int main()
{
  	int ***p,i,j;
	p=(int ***) malloc(MAXX * sizeof(int **));
	for(i=0;i<MAXX;i++)
    	{
        	p[i]=(int **)malloc(MAXY * sizeof(int *));
        	for(j=0;j<MAXY;j++)
            		p[i][j]=(int *)malloc(MAXZ * sizeof(int));
    	}
    	printf("Memory allocated!!!\n");
    	return 0;
}
/*Output:
Memory allocated!!!
*/   

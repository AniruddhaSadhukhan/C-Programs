//47. Implementations of mid square hash function. 
#include<stdio.h>
int hashtable[2<<7];//bucket size=2^8
int hash(int n)
{
	int mask=(2<<7)-1,sq=n*n,t;
	t=(mask<<4) & sq;
	t= (t>>4);
	return t;
}
void insert()
{
	int n;
	printf("Enter values to insert,0 to stop: \n");
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		hashtable[hash(n)]=n;
	}	
}
void display()
{
	int i;
	printf("Hash Table(only filled buckets) \n");
	printf("Index    Data \n");
	for(i=0;i<(2<<7);i++)
	{
		if(hashtable[i]!=0)
			printf("%4d%9d\n",i,hashtable[i]);
	}
}
void search()
{
	int val;
	printf("Enter value to search: \n");
	scanf("%d",&val);
	if(val==hashtable[hash(val)])
		printf("Found \n");
	else printf("Not Found \n");
}
int main()
{
	int x;
	insert();
	display();
	search();
	return 0;
}
/*Output
Enter values to insert,0 to stop: 
54 68 92 35 77 3 0
Hash Table(only filled buckets) 
Index    Data 
   0        3
  17       92
  33       68
  76       35
 114       77
 182       54
Enter value to search: 
35
Found 
*/


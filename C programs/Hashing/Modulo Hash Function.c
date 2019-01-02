//48. Implementation of modulo hash function.
#include<stdio.h>
int hashtable[10];
int hash(int n)
{
	return n%10;
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
	printf("Hash Table \n");
	printf("Index    Data \n");
	for(i=0;i<10;i++)
	{
		printf("%3d%6d\n",i,hashtable[i]);
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
	insert();
	display();
	search();
	return 0;
}
/*Output
Enter values to insert,0 to stop: 
54 68 92 35 77 3 0
Hash Table 
Index    Data 
  0     0
  1     0
  2    92
  3     3
  4    54
  5    35
  6     0
  7    77
  8    68
  9     0
Enter value to search: 
35
Found 
*/


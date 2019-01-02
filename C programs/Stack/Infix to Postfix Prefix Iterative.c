//32. Convert an infix expression to corresponding postfix and prefix expression.(iterative method)
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char stack[20],result[20],expr[20];
int top = -1;
void push(char x)
{
        stack[++top] = x;
}
 
char pop()
{
        if(top == -1)
                return -1;
        else
            return stack[top--];
}
 
int isp(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
}
int icp(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 4;
}
void reverse(char array[20])
{
	int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
}
void postfix()
{
	int temp=0;
	char *e, x;
        e = expr;
        while(*e != '\0')
        {
                if(isalnum(*e))
                        result[temp++]=*e;
                else if(*e == '(')
            		push(*e);
        	else if(*e == ')')
                {
                        while((x = pop()) != '(')
               	 		 result[temp++]= x;
                }
        	else
        	{
            		while(isp(stack[top]) >= icp(*e))
                		 result[temp++]=pop();
            		push(*e);
        	}
                e++;
        }
    	while(top != -1)
    	{
        	 result[temp++]=pop();
    	}	
}
void prefix(void)
{
	int i;
	reverse(expr);
	for(i=0;i<=strlen(expr);i++)
		{
			if(expr[i]=='(')	
				expr[i]=')';
			else if(expr[i]==')')
				expr[i]='(';
		}	
	postfix();
	reverse(result);
}
int main()
{
        printf("Enter the expression :: ");
        scanf("%s",expr);
        postfix();printf("Postfix expression :: %s\n",result);
        prefix();printf("Prefix expression :: %s\n",result);        
    	return 0;
}
/*Output:
Enter the expression :: (A+B)*C+D/(E+F*G)-H
Postfix expression :: AB+C*DEFG*+/+H-
Prefix expression :: +*+ABC-/D+E*FGH
*/

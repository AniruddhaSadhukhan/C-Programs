//35. Evaluate an Prefix expression 
#include<ctype.h>
#include<stdio.h>
#define MAX 20
#include<string.h>
void convert_infix(char x);
char stack[MAX][MAX];
void prefix_to_infix(char prefix[],char infix[]);
int top;
/* Array 'stack[][]' is being used as a stack of strings */
void convert_infix(char x)
{       
	char st1[30],st2[10];
    	st1[0]='(';
    	st1[1]='\0';
    	strcat(st1,stack[top]);
    	st2[0]=x;
   	st2[1]='\0';
  	strcat(st1,st2);
   	strcat(st1,stack[top-1]);
    	st2[0]=')';
    	st2[1]='\0';
    	strcat(st1,st2);
    	top=top-1;
    	strcpy(stack[top],st1);
}
void prefix_to_infix(char prefix[],char infix[])
{
       char x,st1[20];
       int i;
       top=-1;
       for(i=strlen(prefix)-1;i>=0;i--)//scan the prefix string
         {                             //from right to left
          x=prefix[i];
          if(isalnum(x))
            {
            /* convert token to string form */
            st1[0]=x;
            st1[1]='\0';
            // push the operand on the stack s2
            top=top+1;
            strcpy(stack[top],st1);
             }
        else  // if operator convert to infix

              convert_infix(x);

          }
    //Result is on top of the stack
    strcpy(infix,stack[top]);
}

int main()
{
    char postfix[30],infix[30],prefix[30];
    printf("Enter a prefix expression  : ");
    scanf("%s",prefix);
    prefix_to_infix(prefix,infix);
    printf("Equivalent Infix expression: %s\n",infix);
    return 0;
}
/*Output:
Enter a prefix expression  : +*+ABC-/D+E*FGH
Equivalent Infix expression: (((A+B)*C)+((D/(E+(F*G)))-H))
*/

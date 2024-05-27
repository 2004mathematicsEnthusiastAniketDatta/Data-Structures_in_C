#include<stdio.h>
#include<string.h>
#include<stdlib.h>

# define MAX 20

void main()
{
	char str[MAX],stack[MAX];
	int top=-1;
	
	int n,i,j=0; char c[20];
    char a,b,op;
    
    printf("Enter the prefix expression : ");
    scanf("%s", str);
    n=strlen(str);

    for(i=0;i<MAX;i++)
    stack[i]='\0';
    printf("Postfix expression is:\t");
    for(i=0;i<n;i++)
    {
       if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
       {
       	  stack[++top]=str[i];
       }
       else
       { c[j++]=str[i];
         while((top!=-1)&&(stack[top]=='@'))
         {
             a=stack[top--]; 
             c[j++]=stack[top--];
         }
         stack[++top]='@';
       }
    }
    c[j]='\0';
    printf("%s\n",c);
}


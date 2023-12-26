#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int top=-1;
char stack[20];
void push(char ch)
{
top++;
stack[top]=ch;
}
char pop()
{
char ch=stack[top];
top--;
return ch;
}
int priority(char ch)
{
if(ch=='(')
return 0;
else if(ch=='+'|| ch=='-')
return 1;
else if(ch=='*'||ch=='/'||ch=='%')
return 2;
}

void convertInfix(char *e)
{
char *p1,*p2,*p3,x;
int flag=0,count1,count2;
p1=p2=p3=e;
count1=count2=0;
char invalid[100]="Invalid symbols in infix expression. Only alphanumeric and { '+', '-','*', '%', '/' } are allowed.";
while(*p1 !='\0')
{
if(*p1=='(')
count1++;
if(*p1==')')
count2++;
p1++;
}
while(*p2!='\0')
{
char ch=*p2;
if(isalnum(ch)||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='('||ch==')')
{
p2++;
continue;
}
else
{
flag=1;
break;
}}
if(count1!=count2&&flag==0)
printf("Invalid infix expression : unbalanced parenthesis.\n");
if(count1!=count2&&flag==1)
printf("%s\n",invalid);
if(count1==count2&&flag==1)
printf("%s",invalid);
if(count1==count2&&flag==0)
{
printf("Postfix expression : ");
while(*e!='\0')
{
if(isalpha(*e))
printf("%c",*e);
else if(*e=='(')
push(*e);
else if(*e==')')
{
while((x=pop())!='(')
printf("%c",x);
}
else
{
if(top==-1)
push(*e);
else
{
while(priority(stack[top])>=priority(*e))
{
printf("%c",pop());
}
push(*e);
}
}
e++;
}
}
while(top!=-1)
printf("%c",pop());
printf("\n");
}

int main() {
char exp[20];
char *e, x;
printf("Enter the expression : ");
scanf("%s",exp);
e = exp;
convertInfix(e);
}

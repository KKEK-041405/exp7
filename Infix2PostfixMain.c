#include "Infix2PostfixOperation.c"
int main() {
char exp[20];
char *e, x;
printf("Enter the expression : ");
scanf("%s",exp);
e = exp;
convertInfix(e);
}

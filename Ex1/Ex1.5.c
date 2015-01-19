#include <stdio.h>
int main(){
int a,b;
int out;
char c;

printf("Enter two numbers:\n");
scanf("%d",&a);
scanf("%d",&b);
printf("Please enter an operator\n");
scanf(" %c",&c);

switch (c) {
	case '+':
	  out=a+b;
	  break;
	case  '-':
	  out=a-b;
	  break;
	case '*':
	  out=a*b;
	  break;
	case '/':
	 if (b==0)
		printf("Error\n");
	else  
	out=a/b;
	  break;
	case '%':
	  out=a%b;
	  break;
	default: 
	printf("Error");
	}
if (b!=0)
printf("%d",out);
return 0;
}

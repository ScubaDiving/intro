#include <stdio.h>
void printEnter(){
printf("\n");
}

void printRow(int x){
int i;
for(i=0;i<x;i++)        //prints a row of * in the size of a
        printf("*");

}

void printSpaces(int x){
int i;
for(i=0;i<x;i++)       //prints a bunch of spaces
        printf(" ");
}


int main(){
int a,b,c,i;
scanf("%d",&a);
scanf("%d",&b);

if(a<=0||b<=0||b>(a/2))
	return printf("Error\n");;      //input check & break

c=a-b*2-2;               //size of internal square



printRow(a);             //first row
printEnter();
for(i=0;i<b;i++){
	printf("*");
	printSpaces(a-2);// rows before internal square
	printf("*");
	printEnter();}

printf("*");
printSpaces(b);
printRow(c);            //first row of internal square
printSpaces(b);
printf("*");
printEnter();


for(i=0;i<c-2;i++){
printf("*");
printSpaces(b);         //internal rows of square
printf("*");
printSpaces(c-2);
printf("*");
printSpaces(b);
printf("*");
printEnter();}

printf("*");
printSpaces(b);
printRow(c);            //final row of internal square
printSpaces(b);
printf("*");
printEnter();

for(i=0;i<b;i++){
        printf("*");
        printSpaces(a-2);// rows after internal square
        printf("*");
	printEnter();}

printRow(a);           //last row
printEnter();

return 0;
}

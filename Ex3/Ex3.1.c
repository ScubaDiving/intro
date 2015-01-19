/*Ex3.1.c - Amir Melnikov - */


#include <stdio.h>
#define N 10
int main(){

double temp;
int input[N],i,j,flag;

for(i = 0; i < N; i++) 
	{
	scanf("%lf",&temp);    //SCAN
	if (temp-(int)temp)
		return printf("Error\n");  //INT CHECK
	input[i]=(int)temp;
	}

printf("%d ",input[0]); //First number is always diffrent

for(i=1;i<N;i++) //running on the intire input
{
	for(j=0;j<i;j++) //running on previusly scanned numbers
	{
		if(input[j]==input[i]){ //if input[i] is equal to any previous numbers, it will not be displayed (flag=0)
			flag=0;
			break;}    
		else{
			flag=1; 
			}
	}
if(flag)				//flag=1->number is new, print it
	printf("%d ",input[i]);	

}

printf("\n");
return 0;
}

#include <stdio.h>
#define N 10
int main(){

double temp;
int input[N],print[N],i,j,flag;

for(i = 0; i < N; i++) 
	{
	scanf("%lf",&temp);    //SCAN
	if (temp-(int)temp)
		return printf("Error\n");  //INT CHECK
	input[i]=(int)temp;
	}

printf("%d ",input[0]);

for(i=1;i<N;i++)
{
	for(j=0;j<i;j++)
	{
		if(input[j]==input[i]){
			flag=0;
			break;}
		else{
			flag=1;
			}
	}
if(flag)
	printf("%d ",input[i]);	

}

printf("\n");
return 0;
}

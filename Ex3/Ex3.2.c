#include <stdio.h>
#define N 15

int paly(int* input,int counter);


int main(){
	double temp;
	int i,input[N],counter,output_val=16,end;

	for(i = 0; i < N; i++) 
		{
		scanf("%lf",&temp);    //SCAN
		if (temp-(int)temp)
			return printf("Error\n");  //INT CHECK
		input[i]=(int)temp;
		}

	for(counter=2;counter<=N;counter++){ //checking all possible lengths of pali's
		if(paly(input,counter)!=16) 
			output_val=paly(input,counter); //beginning index of pali - will only set val if returning actual index (not 16)
			printf("output_val=%d,counter=%d\n",output_val,counter);	
			}
//Removed for debugging purpuses
/*if(output_val==16)
	puts("No Palindrome found");
else{
	printf("Palindrome Found:");

	for(i=0;i<counter;i++)
	printf("%d",input[output_val+i]);
	printf("\n");
	}*/
	printf("output_val=%d,counter=%d\n",output_val,counter);
	return 0;
}


int paly(int* input,int counter){ //PALINDROME CHECKING FUNCTION

	int i,flag,k;
/*k=starting index, i=ruuning parameter, counter=length of checked palindrome
should check all starting indexes before increasing counter
if flag=1 ----> palindrome found. program should run over pali's with smaller lengths*/

	for(k=0;k<N-counter-1;k++){ //running on beginning indexes
		for(i=0;i<counter/2;i++){ //running on the number itself
			if(input[k+i]==input[k+counter-i-1]){ //checking if first and last digits of current segment are equal
				flag=1; 			//TRUE - moving a step inside (i++)
				continue;
			}
			else
			{
				flag=0;		//FALSE - the suspicious segment is not a pali - stop cheaking and increase k (move a step forward)
				break;
			}
		}
		if(flag) 			//pali found - return beginning index
			return k;
	}
	if(!flag)
		return 16; //return 16 if no pali
}


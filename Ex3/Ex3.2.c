#include <stdio.h>

#define N 15

#define ErrorRtrn -1

int poly(int *input, int counter);

int main() {
    double temp;
    int i, input[N], counter, output_val = ErrorRtrn, maxCounter;

    for (i = 0; i < N; i++) {
        scanf("%lf", &temp);    //SCAN
        if (temp - (int) temp)
            return printf("Error\n");  //INT CHECK
        input[i] = (int) temp;
    }

    for (counter = 2; counter <= N; counter++) { //checking all possible lengths of pali's
        if (poly(input, counter) != ErrorRtrn) {
            output_val = poly(input, counter); //beginning index of pali - will only set val if returning actual index (not 16)
            maxCounter = counter;
        }

    }

    if(output_val==ErrorRtrn)
	    puts("Palindrome Not Found");
    else{
	    printf("Palindrome Found: ");
	    for(i=0;i<maxCounter;i++)
	        printf("%d",input[output_val+i]);
	    printf("\n");
	    }

    return 0;
}


int poly(int *input, int counter) { //PALINDROME CHECKING FUNCTION

    int i, flag, k;
/*k=starting index, i=running parameter, counter=length of checked palindrome
should check all starting indexes before increasing counter
if flag=1 ----> palindrome found. program should run over pali's with smaller lengths*/

    for (k = 0; k < N - counter - 1; k++) { //running on beginning indexes
        for (i = 0; i < counter / 2; i++) { //running on the number itself
            if (input[k + i] == input[k + counter - i - 1]) { //checking if first and last digits of current segment are equal
                flag = 1;            //TRUE - moving a step inside (i++)
                continue;
            }
            else {
                flag = 0;        //FALSE - the suspicious segment is not a pali - stop checking and increase k (move a step forward)
                break;
            }
        }
        if (flag)            //poly found - return beginning index
            return k;
    }
    if (!flag)
        return ErrorRtrn; //return -1 if no poly
}

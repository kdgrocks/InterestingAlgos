/*"The question is Starting from 1, assign an alphabet to each integer, for e.g. if input is 1
 then A should be the output), 2 = B ....... 26 = Z. Similarly, 27 = AA, 28 = AB..........52 = AZ.
 702 = ZZ, 703 = AAA and so on. The function takes only one integer argument . 
 for e.g ConvertToAphabet(int x). One additional consideration here is, the user is free to 
 provide any length of integer (bigint long int etc), no restriction there."*/
#include <stdio.h>
 using namespace std;
void ConvertToAphabet(int nNo){
	int quotient=nNo/26;
	int remainde=(nNo%26);
	
	if(nNo==0){
		return ;
	}
	if(remainde==0){
		quotient=quotient-1;
		remainde=26;
	}
	if(!quotient){
		printf("%c",'A'-1+remainde);
	}
	else{
		ConvertToAphabet(quotient);
		printf("%c",'A'-1+remainde);
	}
	
}

int main(){
	int nNo=703;
	ConvertToAphabet(nNo);
}

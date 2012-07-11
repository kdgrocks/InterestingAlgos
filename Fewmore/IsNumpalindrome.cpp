/*
Check whether the number is palindrome or not without using array?

*/

#include<iostream>
#include<math.h>
using namespace std;

int IsNumPalindrome(int nNum){
	int nLength=(int)log10(nNum);
	int nLeft,nRight;
	while(nNum>0){
	int nDecimal=(int)pow(10,nLength);
	nLeft=nNum/nDecimal;
	nRight=nNum%10;
	if(nLeft!=nRight)
		return 0;
	nNum=(nNum%nDecimal)/10;
	nLength-=2;
	}

return 1;


}


int main(){
int nNum;
cin>>nNum;
cout<<(int)IsNumPalindrome(nNum);
}

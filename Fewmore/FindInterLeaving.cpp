/*
Given two strings .Print all the interleavings of the two strings.
Interleaving means that the if B comes after A .It should also come after A in the interleaved string.
ex-
AB and CD
ABCD
ACBD
ACDB
CABD
CADB
CDAB
*/
#include <iostream>
#include <stdio.h>
using namespace std;

void FindInterleaving(char* cResult, int nResult, char *cSt1,char *cSt2){
	if(*cSt1=='\0' && *cSt2=='\0')
		return ;
	if(*cSt1=='\0'){
		while(*cSt2!='\0'){
			cResult[nResult++]=*cSt2;
			cSt2++;
		}
		cResult[nResult]='\0';
		printf("%s\n",cResult);		
		return ;

	}

	if(*cSt2=='\0'){
		while(*cSt1!='\0'){
			cResult[nResult++]=*cSt1;
			cSt1++;
		}
		cResult[nResult]='\0';
		printf("%s\n",cResult);		
		return ;

	}
	
	cResult[nResult++]=*cSt1;
	FindInterleaving(cResult,nResult,cSt1+1,cSt2);

	cResult[nResult-1]=*cSt2;
	FindInterleaving(cResult,nResult,cSt1,cSt2+1);


}


int main(){
char cSt1[3]="AB",cSt2[3]="CD";
char *cResult= new char[5];
int nResult=0;
FindInterleaving(cResult,nResult,cSt1,cSt2);


}

/*"Find the number of substrings of a string that are palindromes.
 print only palindromes of length greater than 2"*/
#include <iostream>

#define N 10

using namespace std;

void MyPrint(char aString[],int nLeft,int nRight){
	for (int i = nLeft; i < nRight+1; ++i)
	{
		cout<<aString[i];
	}
cout<<endl;

}


void Palindromeinit(char aString[],int nNO,int anArray[][N]){
	for (int i = 0; i <N; ++i){
		for(int j=0;j<N;j++)
		anArray[i][j]=-1;
	}
	for (int i = 0; i < N; ++i){
		anArray[i][i]=1;
	}
	for (int i = 0; i < N-1; ++i){
		if(aString[i]==aString[i+1]){
			anArray[i][i+1]=1;
		}
	}

}


void PalindromeSubstringNew(char aString[],int anArray[][N]){
	for(int len=2;len<N-2;len++){
		for (int i = 0,j=i+len; i < N-1-len; ++i,++j)
		{
			if (aString[i]==aString[j] && anArray[i+1][j-1]){
				anArray[i][j]=1;
				MyPrint(aString,i,j);
			}
			else{
				anArray[i][j]=0;
			}
		}

	}
}


int main(int argc, char const *argv[])
{
	char aString[N]="bananaba";
	int anArray[N][N];
	Palindromeinit(aString,N,anArray);
	PalindromeSubstringNew(aString,anArray);
	return 0;
}
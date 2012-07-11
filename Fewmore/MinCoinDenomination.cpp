#include <iostream>
#define MAX_INT 3000
#define minimum(a,b) ((a)>(b))?(b):(a)
int MinCoinDenomiation(int nSum,int anArray[],int nNo){
	int min=MAX_INT,nCount=0;
	if (0==nSum)
	{
		return 0;
	}
	if(nSum<0){
		return MAX_INT;
	}
	for (int i = 0; i < nNo; ++i)
	{

		min=minimum(min,MinCoinDenomiation(nSum-anArray[i],anArray,nNo)+1);
	}

	return min;
}

int main(int argc, char const *argv[])
{
	int anArray[]={1,3,10};
	printf("%d\n",MinCoinDenomiation(11,anArray,3));
	return 0;
}
#include<iostream>
using namespace std;
int FindSortedArrayRotationRecursive(int *array, int start, int end)
{
	if(start == (end-1))
		return start+1;
	if(array[start] <= array[end-1])
		return 0;
	int middle = (start + end)/2;
	if(array[start] > array[middle])
		return FindSortedArrayRotationRecursive(array, start, middle);
	else
		return FindSortedArrayRotationRecursive(array, middle, end);
}

int FindRotations(int anArray[],int nLeft, int nRight){
	int middle=(nLeft+nRight)/2;
	if(nLeft==nRight)
		return -1;
	
	if(anArray[nLeft]>anArray[middle] && anArray[middle-1]>anArray[middle])
		return middle-1;
	
	if(anArray[nRight]<anArray[middle] && anArray[middle+1]<anArray[middle])
		return middle;

	if(anArray[nLeft]>anArray[middle])
		return FindRotations(anArray,nLeft,middle-1);
	if(anArray[nRight]<anArray[middle])
		return FindRotations(anArray,middle+1,nRight);


}

int main(){
int anArray[]={18, 9, 10, 11, 12, 13, 14, 15, 16, 17};
cout<<FindSortedArrayRotationRecursive(anArray,0,10);
} 

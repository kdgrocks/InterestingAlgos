#include "stdio.h"
#include "stdlib.h"
int compare(const void *a,const void *b){
	return (*(int*)a-*(int*)b);
}
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Quicksort(int anArray[],int left,int right){
	int p;
	if(left<right){

		p=partition(anArray,left,right);
		Quicksort(anArray,left,p-1);
		Quicksort(anArray,p+1,right);
	}	
}

int partition(int anArray[],int left,int right){
	int j=left;
	int i=left-1;
	int key=anArray[left];
	while(j<=right){
		if(anArray[j]<=key){
			i=i+1;
			swap(&anArray[i],&anArray[j]);
		}
		j++;
	}
	swap(&anArray[i],&anArray[left]);
	return i;
}

void printPair(int anArray[],int n,int key){
	int left=1;
	int right=1;
	while(left<n && right<n){
		if(anArray[right]-anArray[left]==key){
			printf("%d---%d\n",anArray[left],anArray[right]);
			return ;
		}
	if(anArray[right]-anArray[left]>key){
			left++;
	}
	else{
		right++;
	}

	}
}

int main(int argc,char **argv){
	int i;
	int anArray[7]={2,3,5,80,90,50,60};
	//Quicksort(anArray,0,6);
	qsort(anArray,6,sizeof(int),compare);
	printf("Print Array\n");
	for (i = 0; i < 6; ++i)
	{
		printf("%d\n",anArray[i]);
	}
	printf("Print Pair\n");
	printPair(anArray,6,75);
	
}
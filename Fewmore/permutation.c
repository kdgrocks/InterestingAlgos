#include <stdio.h>

void swap(char * one ,char *two){
	char temp;
	temp=*one;
	*one=*two;
	*two=temp;

}


void permute(char * acArray,int no, int pos){
	int i;
	if(no==pos){
		printf("%s\n",acArray);
		return ;
	}
	for(i=pos;i<no;i++){
		swap(&acArray[pos],&acArray[i]);
		permute(acArray,no,pos+1);
		swap(&acArray[pos],&acArray[i]);
	}

}


int main(int argc, char ** argv){
	char acArray[]="mohak";
	int no=5;
	permute(acArray,no,0);


}
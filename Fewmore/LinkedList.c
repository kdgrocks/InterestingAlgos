
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int m_Data;
	struct Node *pNext;
}Node;

Node * sFirst=NULL;

Node * Insert(int nData){
	Node* sTemp=(Node *)malloc(sizeof(Node));
	sTemp->m_Data=nData;
	sTemp->pNext=NULL;
	//printf("%d\n",nData );
	if(sFirst==NULL)
		return sTemp;
	else {
		sTemp->pNext=sFirst;
		return sTemp;
	}


}

void Myprint(){
	Node * sTemp=sFirst;
	while(sTemp!=NULL){
		printf("%d\n",sTemp->m_Data);
		sTemp=sTemp->pNext;
	}
}

Node * Reverse(Node * sRoot){
	if(!sRoot)
		return NULL;
	if(sRoot->pNext!=NULL){
		Reverse(sRoot->pNext);
		sRoot->pNext->pNext=sRoot;
		return sRoot;
	}
	else{
		sFirst=sRoot;
		return NULL;
	}

}


int main(){
	int i;
	Node * sHead=sFirst;
	for (i = 0; i < 9; ++i)
	{
		sFirst=Insert(i);
	}
	printf("Before Reversing;\n");
	Myprint();
	printf("After Reversing;\n");
	sHead=Reverse(sFirst);
	if(sHead!=NULL)	
		sHead->pNext=NULL;
	Myprint();



}

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int m_Data;
	struct Node *pNext;
}Node;


Node * Insert(int nData,Node* sRoot){
	Node* sTemp=(Node *)malloc(sizeof(Node));
	sTemp->m_Data=nData;
	sTemp->pNext=NULL;
	//printf("%d\n",nData );
	if(sRoot==NULL)
		return sTemp;
	else {
		sTemp->pNext=sRoot;
		return sTemp;
	}


}

void Myprint(Node *sFirst){
	Node * sTemp=sFirst;
	while(sTemp!=NULL){
		printf("%d\n",sTemp->m_Data);
		sTemp=sTemp->pNext;
	}
}

Node * Reverse(Node *sRoot,Node * sPrev){
	Node* sTemp;
	if(!sRoot)
		return NULL;
	if(sRoot->pNext!=NULL){
		sTemp=Reverse(sRoot->pNext,sRoot);
		sRoot->pNext=sPrev;
		return sTemp;
	}
	else{
		sRoot->pNext=sPrev;
		return sRoot;
	}

}


int main(){
	int i;
	Node * sFirst=NULL;
	Node * sHead=sFirst;
	for (i = 0; i < 9; ++i)
	{
		sFirst=Insert(i,sFirst);
	}
	printf("Before Reversing;\n");
	Myprint(sFirst);
	printf("After Reversing;\n");
	sFirst=Reverse(sFirst,NULL);
	Myprint(sFirst);



}

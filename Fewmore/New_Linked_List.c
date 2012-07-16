#include <stdio.h>
#include <stdlib.h>

#define MEM_PROBLEM 0
#define EMPTY_LIST -1
typedef struct Node {
	struct Node * pNext;
	int nData;
}Node;

int insertNode(Node ** Root, int ndata){
	Node * temp=NULL;
	temp=malloc(sizeof(Node));
	if(temp==NULL)
		return MEM_PROBLEM;
	temp->nData=ndata;
	temp->pNext=*Root;
	*Root=temp;
	return 1;
}

int traverse(Node **Root){
	Node * temp=*Root;
	if (*Root==NULL)
		return EMPTY_LIST;
	while(temp){
		printf("%d\n",temp->nData);
		temp=temp->pNext;
	}
	return 1;
}

int deleteNode(Node **Root,int ndata){
	Node *Prev;
	Node *Curr=*Root;

	if(*Root==NULL)
		return EMPTY_LIST;

	if(Curr->nData==ndata){
		free(*Root);
		*Root=Curr->pNext;
		return 1;
	}

	while(Curr->pNext){
		if(Curr->pNext->nData==ndata){
			Prev=Curr->pNext;
			Curr->pNext=Prev->pNext;
			free(Prev);
			return 1;
		}
		Curr=Curr->pNext;
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	Node *First=NULL;
	int i=0;
	for (i = 0; i <9; ++i)
	{
		insertNode(&First,i);
	}
	printf("traverse\n");
	traverse(&First);
	deleteNode(&First,2);
	printf("Traverse -2 \n");
	traverse(&First);
	return 0;
}

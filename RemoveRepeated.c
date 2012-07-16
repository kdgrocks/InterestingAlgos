#include <stdio.h>
#include "Linked_List.h"

void Duplicate(Node **Root){
	Node *Prev=*Root;
	Node *Curr=*Root;
	Node *iter=NULL;
	int flag=0;
	if(*Root==NULL)
		return ;
	while(Curr->pNext){
		iter=Curr->pNext;
		while(Curr->nData==iter->nData){
			Curr->pNext=iter->pNext;
			free(iter);
			iter=Curr->pNext;
			flag=1;
		}
		if(flag){
			if(Curr==*Root){
				*Root=Curr->pNext;
				free(Curr);
				Curr=*Root;
			}
			else{
				Prev->pNext=Curr->pNext;
				free(Curr);
				Curr=Prev->pNext;
			}
		}
		else{
			Prev=Curr;
			Curr=Curr->pNext;
		}


	}

}

int main(){
	Node *First=NULL;
	int i=0;
	insertNode(&First,-1);
	for (i = 0; i < 4; ++i)
	{
		insertNode(&First,i);
		insertNode(&First,i);
	}
	for (i = 4; i < 9; ++i)
	{
		insertNode(&First,i);
		/* code */
	}
	printf("Traverse 1\n");
	Traverse(&First);
	Duplicate(&First);
	printf("Traverse -2\n");
	Traverse(&First);


}
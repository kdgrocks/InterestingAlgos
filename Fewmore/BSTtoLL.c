#include <stdio.h>
#include <stdlib.h>
typedef struct BST {
	int ndata;
	struct BST *pLeft;
	struct BST *pRight;
}BST;

BST * insertBst(BST * root,int elem){
	BST *temp;
	if(root==NULL){
		temp=(BST*)malloc(sizeof(BST));
		temp->ndata=elem;
		temp->pLeft=NULL;
		temp->pRight=NULL;
		return temp;
	}
	if(root->ndata<elem){
		root->pRight=insertBst(root->pRight,elem);

	}
	else {
		root->pLeft=insertBst(root->pLeft,elem);
	}
	return root;

}

void inorder (BST * root){
	if (root==NULL)
		return;
	inorder(root->pLeft);
	printf("%d\t",root->ndata);
	inorder(root->pRight);
}

BST * BSTtoDLL(BST *root,BST** head){
	static BST *prev=NULL;
	if(root==NULL)
		return NULL;
	BSTtoDLL(root->pLeft,head);
	if(prev!=NULL)
		prev->pRight=root;
	else{
		*head=root;
	}
	root->pLeft=prev;
	prev=root;
	BSTtoDLL(root->pRight,head);
	return root;
}

int main(int argc,char *argv[]){
int i=0;
BST *root=NULL,*head;
root=insertBst(root,6);
root=insertBst(root,5);
root=insertBst(root,7);
root=insertBst(root,3);
root=insertBst(root,8);
root=insertBst(root,16);
root=insertBst(root,1);
inorder(root);

BSTtoDLL(root,&head);
printf("\n%d\n",head->pRight->pRight->ndata);
}
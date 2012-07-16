#ifndef LINKED_LIST
#define LINKED_LIST
typedef struct Node {
	struct Node * pNext;
	int nData;
}Node;

int insertiNode(Node ** Root, int ndata);
int Traverse(Node **Root);
int deleteNode(Node **Root,int ndata);

#endif
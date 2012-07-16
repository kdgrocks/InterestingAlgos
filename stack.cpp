#include <iostream>
#include <stdlib.h>
#include <cassert>
using namespace std;

class stack
{
public:
	stack();
	~stack();
	void push(void * pdata);
	void * pop();
protected:
	typedef struct Node{
		struct Node *pNext;
		void *pdata;
	}Node;
	Node* Root;
};

stack::stack(){
	Root=NULL;
	return ;
}
stack::~stack(){
	return;
}

void stack::push(void *data){
	Node* temp;
	temp=(Node *)malloc(sizeof(Node));
	assert(temp!=NULL);
	temp->pdata=data;
	temp->pNext=Root;
	Root=temp;
	return ;
}

void *stack::pop(){
	Node *temp=NULL;
	void * element;
	if(Root==NULL)
		return NULL;
	temp=Root;
	Root=Root->pNext;
	element=temp->pdata;
	free(temp);
	return element;
}



int main(int argc, char const *argv[])
{
	stack mystack;
	int i=1,j=2,k=3,l=4,m=5;	
	mystack.push(&i);
	mystack.push(&k);
	mystack.push(&l);
	mystack.push(&m);
	for (int i = 0; i < 4; ++i)
	{
		cout<<*(int *)mystack.pop()<<endl;
	}
	return 0;
}
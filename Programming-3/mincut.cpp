#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#define N 200
using namespace std;

void insert_edge(unsigned int adjacent_matrix[][201], int i, int j){
	//printf("%d %d\n",i,j );
	adjacent_matrix[i][j]=1;
	adjacent_matrix[j][i]=1;
}
void read_file(unsigned int adjacent_matrix[][201]){
	FILE *fp;
	int x;
	char s[10000];
	char *p;
	fp=fopen("code.txt","r");
	while(fgets(s,400,fp)){
		p=strtok(s,"	");
		x=atoi(s);
		while(p!=NULL){
			insert_edge(adjacent_matrix,x,atoi(p));
			p=strtok(NULL,"	");	
		}
	}
	fclose(fp);
}

int random_generator(int min, int max){
	return ((rand() % (max+1-min))+min);
}

unsigned int min_cut(){
	vector<int> elements;
	unsigned int adjacent_matrix[201][201]={0};
	read_file(adjacent_matrix);
	int one,two;
	int item_one,item_two;
	
	for (int i = 1; i <=N; ++i){
		elements.push_back(i);
	}
	while(elements.size()>2){
		one=random_generator(0,(int)elements.size()-1);
		item_one=elements[one];		
		two=random_generator(0,(int)elements.size()-1);
		item_two=elements[two];
		if (item_one==item_two || adjacent_matrix[item_one][item_two]==0)
		{
			continue;
		}
		elements.erase(elements.begin()+one);
		
		for (int i = 1; i <=N; ++i)
		{
			adjacent_matrix[item_two][i]+=adjacent_matrix[item_one][i];
			if(i!=item_two)	
			adjacent_matrix[i][item_two]+=adjacent_matrix[i][item_one];
		}
	}
	elements.clear();
	return adjacent_matrix[elements[1]][elements[0]];
	
}


int main(int argc, char const *argv[])
{
	int i;
	unsigned int k,min=100000;	
	srand(time(0));
	for (int i = 1; i <= N*N; ++i)
	{
		k=min_cut();
	if (min>k)
	{
		min=k;
	}
	printf("%u--%d\n",min,i);	
	}
	return 0;
}

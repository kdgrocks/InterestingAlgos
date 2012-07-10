#include<stdio.h>
#include<stdlib.h>
int c=0;
void swap(int *t, int *b){
int p=*t;
*t=*b;
*b=p;
}
int choose_pivot(int i,int j){
return((i+((j-i)/2)));

}
void quicksort(int a[],int i,int j){
int p,m;
if(i>=j)
return ;
c=c+j-i;
m=choose_pivot(i,j);
swap(&a[i],&a[m]);
p=partition(a,i,j);
quicksort(a,i,p-1);
quicksort(a,p+1,j);
}

int partition(int a[],int i,int j) {
int key=a[i];
int l,r;
l=i+1;
r=i+1;
while(r<=j){
        if(a[r]<key){
        swap(&a[l],&a[r]);
        l++;
        }
        r++;
        }
swap(&a[i],&a[l-1]);
return (l-1);
}
int main(int argc,char * argv[]){
int a[100100];
int i=0,n=10000;
FILE *fp;
char s[10000];
fp=fopen(argv[1],"r");
while(fgets(s,10000,fp)!=NULL){
a[i++]=atoi(s);
}
quicksort(a,0,n-1);
printf("COUNT: %d\n",c);
/*for(i=0;i<9;i++){
printf("%d\n",a[i]);
}*/
fclose(fp);
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count=0;
void print();
void print_block();
void printcheck();
void suduko(int no,int i);
void call(int ,int);
int a[20][20];
char block[20][20];
char check[20][20];
char check2[20][20];
int n;
int N;//sq of n;
int main(){
	int i,j;
	int no;
	while(scanf("%d",&n)!=EOF){
		N=sqrt(n);

//		for(i=1;i<=n;i++) for(j=1;j<=n;j++) printf("%d ",(((i-1)/(N))*N+(j-1)/(N)+1));
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) block[i][j]='n';
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) a[i][j]=0;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) check[i][j]='n';
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) check2[i][j]='n';
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				block[((i-1)/(N))*N+((j-1)/(N))+1][a[i][j]]='y';
				check[i][a[i][j]]='y';
				check2[j][a[i][j]]='y';
			}
		}
		print();
	/*	printf("array:\n");
		print();
		printf("block:\n");
		print_block();
		printf("check:\n");
		printcheck();
		printf("\n");*/
		count=0;
		suduko(1,1);
		printf("solution=%d\n",count);
	}
	return 0;
}
void  suduko(int no,int i){
//	printf("sudoko start with no=%d i=%d \n",no,i);
	if(check[i][no]=='y'){
		call(i,no); 
		return ;
	}
	int j;
	for(j=1;j<=n;j++){
//		printf("for loop started with j=%d\n",j);
	//	print();
	//	printf("\n");
			if(block[((i-1)/(N))*N+((j-1)/(N))+1][no]=='y') continue;
			if(a[i][j]!=0) continue;
			if(check2[j][no]=='y') continue;
//			printf("yes\n");
			a[i][j]=no;
			check2[j][no]='y';
			check[i][no]='y';
			block[((i-1)/(N))*N+((j-1)/(N))+1][no]='y';
			call(i,no);
			a[i][j]=0;
			check[i][no]='n';
			check2[j][no]='n';
			block[((i-1)/(N))*N+((j-1)/(N))+1][no]='n';
	}
//	printf("sudoko end with no=%d i=%d \n",no,i);
	return ;
}
void call(int i,int no){
if(i==n){
	if(no==n){
		print();

		count++;
//		exit (1);
	}
	else{
		suduko(no+1,1);
	}
}
else{
	suduko(no,i+1);
}
}
void print(){
	int i;int j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]); 
		}
		printf("\n");
	}
		printf("\n");
}
void print_block(){
	int i;int j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++){
			printf("%c ",block[i][j]); 
		}
		printf("\n");
	}
}
void printcheck(){
	int i;int j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++){
			printf("%c ",check[i][j]); 
		}
		printf("\n");
	}
}

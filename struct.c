#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


/*
在C/C++中，常量指针是这样声明的：

1）const int *p;

2）int const *p;
常量指针的使用要注意，指针指向的对象不能通过这个指针来修改

在C/C++中，指针常量这样声明：

int a;

int *const b = &a; //const放在指针声明操作符的右侧

因为指针常量是一个常量，在声明的时候一定要给它赋初始值。一旦赋值，以后这个常量再也不能指向别的地址。

虽然指针常量的值不能变，可是它指向的对象是可变的，因为我们并没有限制它指向的对象是常量。
*/
#define INIT 3
#define BUFF_SIZE 256

char* str_in();
void strSort(const char**,int);
void strOutput(const char* const*,int);
void swap(const char**,const char** ); //

void freePointer(char**,int );
void main(){
	char** pS=NULL;
	char* pStr=NULL;
	char** pStemp=NULL;
	int pS_size=INIT;
	int pS_count=0;
	pS=calloc(pS_size,sizeof(char*));
	while(!(pStr=str_in())){
		if(pS_count==pS_size){
			pS_size+=INIT;
			if(!(pStemp=realloc(pS,pS_size*sizeof(char*)))){
				printf("relloc pS ERROR");
				return;
			}
			pS=pStemp;
		}
		pS[pS_count++]=pStr;
	}
	strSort(pS,pS_count);
	strOutput(pS,pS_count);
}

char* str_in(){
	char buff[BUFF_SIZE];
	char* pString=NULL;
	size_t buff_len=0;
	if(!(fgets(buff,BUFF_SIZE,stdin))){
		printf("ERROR reading\n");
		return NULL;
	}
	if(buff[0] == '\0'){
		printf("reading finished!\n");
	}
	buff_len=strlen(buff)+1;
	pString=malloc(buff_len);
	if(!pString){
		printf("ERROR to malloc");
		return NULL;
	}
	strcpy(pString,buff);
	return pString;
}

void strSort(const char** p,int n){
	bool sorted=false;
	while(sorted!=true){
		sorted=false;
		for(int i=0;i<n-1;i++){
			if(strcmp(p[i],p[i+1])>0){
				sorted=false;
				swap(&p[i],&p[i+1]);
			}
		}
	}
}

void swap(const char** p1,const char** p2){
	const char* pTemp=*p1;
	*p1=*p2;
	*p2=pTemp;
}

void strOutput(const char* const* p,int n){
	for(int i=0;i<n;i++){
		printf("%s\n",p[i]);
	}
}

void freePointer(char** p,int n){
	for(int i=0;i<n;i++){
		free(p[n]);
		p[n]=NULL;
	}
	free(p);
	p=NULL;
}
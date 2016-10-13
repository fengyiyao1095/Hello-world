#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

/*
int main1(){
	int number=15;
	int* pNumber=&number;
	int result=0;
	result+=*pNumber;
	printf("%d",result);
	return 0;
}
int main2(){
	int number=10;
	int* pNumber=NULL;
	printf("%p\n",&number);
	printf("%d\n",number);
	pNumber=&number;
	printf("%p\n",&pNumber);
	printf("%p\n",pNumber);
	printf("%d\n",*pNumber);
}

int main3(){
	int value1=5;
	int* pNumber=&value1;
	*pNumber+=5;
	printf("%p\n",pNumber);
	printf("%d\n",*pNumber);
	int value2=100;
	pNumber=&value2;
	*pNumber+=5;
	printf("%p\n",pNumber);
	printf("%d\n",*pNumber);
}

int main4(){
	int value;
	int* pNumber=&value;
	scanf("%d",pNumber);
	printf("%d",value);
}

int main5(){
	int value=100;
	const int* pNumber=&value;            //不允许使用指针去改变value变量的值，但是可以通过value来改变，唤作指向常量的指针
	value=200;
	int number=1000;
	pNumber=&number;                     //虽然不能通过指针来修改值，但是可以通过修改指针的地址来修改值
}

int main6(){
	int value=100;
    const int* pNumber=&value;        //声明一个无法修改地址的指针,同时也不能修改所指向的值，唤作常量指针
    //pNumber=200;
}
int main7(){
	char str[]="abcde";
	printf("%d\n",sizeof(str));
	printf("%d",strlen(str));
}

int main8(){
	char str[]="You are a good man";
	char *pStr=str;
	for(int i=0;i<strlen(str);i++){
		printf("str[%d]=%c,*(pStr+%d)=%c,&str[%d]=%p,pStr+%d=%p\n",i,str[i],i,*(pStr+i),i,&str[i],i,pStr+i);
	}
}

int main9(){

	int arr[]={1,2,3};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		printf("%d\n",*(arr+i));
	}
}

int main10(){
	char arr[3][3]={{'1','2','3'},{'1','2','3'},{'1','2','3'}};
	for(int i=0;i<sizeof(arr)/sizeof(arr[0][0]);i++){
		printf("%c\n",*(*arr+i));
	}
}

int main11(){
	char arr[3][3]={{'1','2','3'},{'1','2','3'},{'1','2','3'}};
	char *pArr=*arr;
	for(int i=0;i<9;i++){
		printf("%c\n",*(pArr+i));
	}

}

//求质数
/*
1.分析算法：除了2以外，都是奇数，且都不能被该质数前面的质数整除
2.分析用到的变量: 指针pNumber，用来接收分配的内存，存储数据；质数个数total;计数变量,count;
计算用到的变量number;bool变量，用来标志是否找到质数
*/
/*
int main12(){
	int* pPrimer=NULL;
	int total;
	bool found=true;
	printf("Please input the total number of primers: ");
	scanf("%d",&total);
	total=total>=4?total:4;
	pPrimer=(int*)malloc(total*sizeof(int));
	if(!pPrimer){
		return 0;
	}
	*pPrimer=2;
	*(pPrimer+1)=3;
	*(pPrimer+2)=5;
	int count=3;
	int number=5;
	while(count<total){
		number+=2;
		for(int i=0;i<count;i++){
			if(!(found=number % *(pPrimer+i))){
				break;
			}
		}
		if(found){
			*(pPrimer+count++)=number;
		}
	}
	for(int i=0;i<total;i++){
		printf("%d\t",*(pPrimer+i));
		if(!((i+1)%5)){
			printf("\n");
		}
	}
	free(pPrimer);
	pPrimer=NULL;
	return 0;
}

int main13(){
	char buffer[100];
	char* pSize=buffer;
	int index=0;
	for(;index<sizeof(buffer);index++){
		if((*(pSize+index)=getchar())=='\n'){
			*(pSize+index++)='\0';
			break;
		}
	}
	if((index==sizeof(buffer))&&((*(pSize+index-1))!='\0')){
			printf("memory is out of size");
			return 1;
	}
}

int main14(){
	const int buff_size=100;
	char buffer[buff_size];
	scanf("%s",buffer);
	size_t length=strlen(buffer)+1;
	char* pString=malloc(length);
	if(!pString){
		printf("Memory allocation failed~~~\n");
		return 1;
	}
	strcpy(pString,buffer);
	printf("%s",pString);
	free(pString);
	pString=NULL;
}

//#define STR_COUNT 10
int main15(){
	const size_t BUF_SIZE = 100;
	char buffer[BUF_SIZE];
	//char* pS[STR_COUNT]={NULL};
	size_t str_size=0;

	for(size_t i=0;i<STR_COUNT;++i){
		scanf("%s",buffer);
		size_t str_size=strlen(buffer)+1;
		pS[i]=malloc(str_size);
		if(!pS[i]){
			return 1;
		}
		strcpy(pS[i],buffer);
	}
	for(size_t i=0;i<STR_COUNT;i++){
		printf("%s\n",pS[i]);
		free(pS[i]);
		pS[i]=NULL;
	}
}

//#define BUF_LEN 100
//#define INIT_STR_EXT 50
//#define WORDS_INCR 5
int main16(){
	char delimiters[]="\n\".,;:!?)(";
//	char buf[BUF_LEN];
//	size_t str_size	= INIT_STR_EXT;
	char* pStr=malloc(str_size);
	if(!pStr){
		return 1;
	}
	*pStr='\0';

	printf("Enter some prose with up to %d characters per line.\n"
		"Terminate input by entering an empty line:\n",BUF_LEN);

	while(true){
		fgets(buf,BUF_LEN,stdin);             //每次输入\n，为这条语句结束时
		if(buf[0]=='\n'){
			break;
		}

		if(strlen(pStr)+strlen(buf)+1>str_size){
			str_size=strlen(pStr)+strlen(buf)+1;
			pStr=realloc(pStr,str_size);
		}

		if(strcat(pStr,buf)){
			printf("Somethind is wrong. String concatenation failed.\n");
			return 1;
		}
	}

	size_t maxWords=10;
	int word_count=0;
	size_t word_length=0;
	char** pWords=calloc(maxWords,sizeof(char*));
	int* pnWord=calloc(maxWords,sizeof(int));

	size_t str_len=strlen(pStr);
	char* ptr=NULL;
	//char* pWord=strtok(pStr,&str_len,delimiters,&ptr);

	if(!pWord){
		printf("No words found. Ending program.\n");
		return 1;
	}
	bool new_word=true;

}

*/

/*
#define BUF_LEN 100
#define COUNT 5
int main(void){
	char buf[BUF_LEN];            //字符串变量，用来存储输入的值
	size_t str_count=0;           //当前字符串个数
	size_t capacity=COUNT;		  //当前最大字符串个数
	char** pS=calloc(capacity,sizeof(char*)); //指针数组，用来存储字符串指针
	char** psTemp=NULL;           //临时指向字符串的指针的指针
	char* pTemp=NULL;			  //临时指针，指向字符串
	size_t str_len=0;			  //字符串长度
	bool sorted=false;			  //判断字串是否经过排序

	printf("Enter strings to be sorted,one per line. Press Enter to end:\n");

	char *ptr=NULL;

	while(true){
		ptr=fgets(buf,BUF_LEN,stdin);
		if(!ptr){
			printf("Error reading  string.\n");
			free(pS);
			pS=NULL;
			return 1;
		}

		if(*ptr=='\n'){
			break;
		}

		if(str_count == capacity){
			capacity += capacity/4;
			if(!(psTemp == realloc(psTemp,capacity))) return 1;
			pS=psTemp;
		}

		str_len=strlen(buf)+1;
		if(!(pS[str_count]=malloc(str_len))) return 2;
		strcpy(pS[str_count++],buf);
	}

	while(!sorted){
		sorted=true;
		for(size_t i=0;i<str_count-1;i++){
			if(strcmp(pS[i],pS[i+1])>0){
				sorted=false;
				pTemp=pS[i];
				pS[i]=pS[i+1];
				pS[i+1]=pTemp;
			}
		}
	}
	printf("Your input sorted in ascending sequence is:\n\n");
	for(size_t i=0;i<str_count;++i){
		printf("%s",pS[i]);
		free(pS[i]);
		pS[i]=NULL;
	}
	free(pS);
	pS=NULL;
	return 0;
}
*/


#define BUF_LEN 256
int main(void){
	char buf[BUF_LEN];
	char op=0;
	size_t index=0;
	size_t to=0;
	size_t buf_length=0;
	double result=0.0;
	double number=0.0;
	char* endptr=NULL;

	char* ptr=NULL;
	while(true){
		ptr=fgets(buf,BUF_LEN,stdin);
		if(!ptr){
			printf("Error reading input.\n");
			return 1;
		}

		if(strcmp(buf,"quit\n")== 0) break;

		buf_length=strlen(buf);
		buf[--buf_length]='\0';

		for(to=0,index=0;index<=buf_length;index++){
			if(*(buf+index)!=' '){
				*(buf+to++)=*(buf+index);
			}
		}

		buf_length=strlen(buf);

		index=0;

		if(buf[index]== '=')
			index++;
		else{
			result=strtod(buf+index,&endptr);
			index=endptr-buf;
		}

		while(index<buf_length){
			op=*(buf+index++);
			number=strtod(buf+index,&endptr);
			index=endptr-buf;

			switch(op){
				case '+':
					result +=number;
					break;
				case '-':
					result += number;
					break;
				case '*':
					result *= number;
					break;
				case '/':
					if(number ==0) printf("\n\n\a Division by zero error!\n");
					else
						result/=number;
					break;
				case '%':
					if((long long)number==0LL) printf("\n\n\aDivision by zero error!\n");
					else
						result =(double)((long long)result % (long long)number);
					break;
				case '^':
					result=pow(result,number);
					break;
				default:
					printf("\n\n\aIllegal operation!\n");
					break;
			}
		}
		printf("= %f\n",result);
	}
	return 0;
}
# include <stdio.h>
#include <stdlib.h>

#define SIZE 20
int find_substr (char *main_str,char * sub_str);

int main (){
	
	char s[SIZE][SIZE];
//	char *ret;
	int i=0;
	int cnt;
	char sub_str[20]="i";
	int ret;
	
	FILE *fin;
	fin=fopen("filename1.txt","r");
	
//	ret=(char *)malloc(sizeof(char)*SIZE);
	
	if(fin==NULL){
		printf("问价打开失败");
		return 0;
	}
	
	while (fscanf(fin,"%s",s[i])!=EOF){
		i++;
	}
	
	cnt=i;
	printf("%d\n",cnt);
//	for(i=0;i<cnt;i++){
//		printf("%s\n",s[i]);
//	}
	
	
	//查找子串
	for(i=0;i<cnt;i++){
		if((ret=find_substr(s[i],sub_str))!=-1){
			printf("第%d个字符串中的 %d位",i+1,ret+1);
		}
	} 
	return 0;
} 


int find_substr (char *main_str,char * sub_str){
	
//	int len_a,len_b;
	int i=0,j;
	
	while (main_str[i]!='\0'){
		
		if(main_str[i]==sub_str[0]){
			j=1;
			while(main_str[i+j]==sub_str[j]&&sub_str[j]!='\0'){
				j++;
			}
			
			if(sub_str[j]=='\0'){
				return i;
			}
		} 
		
		
		i++;
	}
	
	return -1;
}

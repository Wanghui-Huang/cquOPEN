#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define  M 50
int compare (const void *a,const void *b);

int main ()
{
	char s1 [M];
	char s2 [M];
	int len;
	
	FILE *fin1,*fin2,*fout;
	fin1=fopen("filename1.txt","r");
	fin2=fopen("filename2.txt","r");
	fout=fopen("fileout.txt","w");
	if(fin1==NULL||fin2==NULL||fout==NULL)
	{
		printf("打开文件失败");
		exit(0); 
	}
	fgets(s1,M,fin1);
	fgets(s2,M,fin2);
	
	
	strcat(s1,s2);
	len=strlen(s1);
	
	qsort(s1,len,sizeof(char),compare);
	printf("%s",s1);
	fputs(s1,fout);
	
	return 0;
}


int compare (const void *a,const void *b)
{
	char * p1=(char *)a;
	char * p2=(char *)b;
	return *p1 - *p2 ;
}
 

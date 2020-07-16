#include <stdio.h>
#include <string.h> 
//有两个磁盘文件 A和 B,各存放一行字母，
//要求把这两个文件中的信息合并（按字母顺序 排列），
//输出到一个新文件 C 中。
#define size 100
int compare (const void *a,const void *b);

int main ()
{
	char str1[size],str2[size];
	char str3[size];
	int len_1,len_2;
	int i=0,j=0,k=0; 
	FILE *fin1,*fin2,*fout;
	fin1=fopen("filename1.in","r");
	fin2=fopen("filename2.in","r");	
	fout=fopen("filename2.out","w");
	if(fin1==NULL||fin2==NULL||fout==NULL)
	{
		printf("文件打开失败");		
	}	
	
	fgets(str1,size,fin1);
	fgets(str2,size,fin2);
	len_1=strlen(str1);
	len_2=strlen(str2);
	qsort(str1,len_1,sizeof(char),compare);
	qsort(str2,len_2,sizeof(char),compare);

	while (str1[i]!='\0'&&str2[j]!='\0')
	{
		if(str1[i]<str2[j])
		{
			str3[k++]=str1[i++];
		}else
		{
			str3[k++]=str2[j++];
		}
		
	}
	
	if(str1[i]!='\0')
	{
		str3[k++]=str1[i++];
	}else
	{
		str3[k++]=str2[j++];
	}
	
	fputs(str3,fout);
	
	
	return 0;
} 

int compare (const void *a,const void *b)
{
	return *(char*)a-*(char *)b ;
}

//void merge (char *str1,char *str2)
//{
//	int i=0,j=0,k=0;
//	while (str1[i]!='\0'&&str2[j]!='\0')
//	{
//		if(str1[i]<str2[j])
//		{
//			str3[k++]=str1[i++];
//		}else
//		{
//			str3[k++]=str2[j++];
//		}
//		
//	}
//	
//	if(str1[i]!='\0')
//	{
//		str3[k++]=str1[i++];
//	}else
//	{
//		str3[k++]=str2[j++];
//	}
//}


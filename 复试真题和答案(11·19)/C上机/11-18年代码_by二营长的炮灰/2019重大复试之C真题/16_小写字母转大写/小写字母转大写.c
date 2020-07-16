#include<stdio.h>
#include<ctype.h>
#define MAX 100

int main()
{
	FILE* out;
	char s[MAX];
	int i ;
	gets(s);
	for(i = 0 ; s[i] != '\0';i++)
	{
		if(islower(s[i])) 	s[i] = toupper(s[i]);
	}
	out = fopen("E:\\test.txt","w"); //ATTENTION 0 :fopen参数没out!
	if(!out)   
		exit(1);	
	//2019.2.20 10:43 我是个傻zi，调试半小时原来是printf没f,fprintf！
	fprintf(out,"%s",s);
	fclose(out);  //易错 1 ：记得关文件流
	return 0;
}
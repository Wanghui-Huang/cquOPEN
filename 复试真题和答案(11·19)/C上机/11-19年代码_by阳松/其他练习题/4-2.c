#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//将 字 符 串 中 的 空 格 替 换 成 "%020" ， 例 如 "hello world how "
////->"hello%020%020%020world%020%020%020how%020%020%020%020"

void transform (char *str,char *after);

int main (){
	
	char str[300];
	char after[600];
	after[0]='\0';
	gets(str);
	transform (str,after);
	printf("%s",after);
	return 0;
}

void transform (char *str,char *after)
{
	int i=0,j=0;
	char ins[5]="%020";
	while (str[i]!='\0')
	{
		if(str[i]==' ')
		{
			strcat(after,ins);
			j=strlen(after);
		}else
		{
			after[j++]=str[i];
			after[j]='\0';					//不然strcat 用不了 
		}
		i++;
	}
}

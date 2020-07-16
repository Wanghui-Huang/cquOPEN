#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//1.将包含字符数字的字符串分开,使得分开后的字符串前一部分是数字后一部分是字母。例
//如"h1ell2o3" ->"123hello"


//思路： 用两个字符串数组，一个存储字母，一个存储数字 
int main (){
	
	char num [20] ;
	char str [20];
	char s[40];
	char temp;
	int i=0,j=0,k=0;
	
	gets(s);
	
	while(s[i]!='\0') 
	{
		temp=s[i];
		if(isupper(temp)||islower(temp))
		{
			str[j++]=temp;
		}else if(temp>='0'&&temp<='9')
		{
			num[k++]=temp;
		}
		i++;
	}
	str[j]='\0';
	num[k]='\0';
	printf("%s%s",num,str);
	return 0;
}

#include <stdio.h>
#include <string.h>
//字符串循环加密，和一个正整数，将其中的英文字符加密并输出加密后的英文字符串，
//其中A-Z 循环加密 a+偏移k,非英文字符不变 
#define size 101
int main ()
{
	char str[size];
	int k;
	int i,len;
	
	scanf("%s%d",str,&k);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(isupper(str[i]))		//是大写字母 
		{
			str[i]=(str[i]-'A'+k )%26 +'A'; 
		}
		if(islower(str[i]))
		{
			str[i]=(str[i]-'a'+k )%26 +'a'; 
		}	
	}	
	
	printf("%s",str);
	return 0;
}

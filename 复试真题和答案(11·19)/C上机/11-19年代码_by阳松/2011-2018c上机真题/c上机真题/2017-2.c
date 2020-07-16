#include <stdio.h>
#include <string.h>
//字符串循环加密，该字符串循环向后移 i+5 个位置 
#define size 101
int main ()
{
	char str[size];
	int k;		// k 为1代表加密，k为0 代表解密 
	int i,len;
	
	scanf("%s%d",str,&k);
	len=strlen(str);
	switch (k)
	{
		case 1:
			for(i=0;i<len;i++)
			{
				str[i]=(str[i]+i+5 )%256 ; 
			}
		break;
		case 0:
			for(i=0;i<len;i++)
			{
				str[i]=(str[i]-i-5+256)%256 ; 
			}
		break;
		default:
			printf("erro") ;
	 } 

	printf("%s",str);
	return 0;
}

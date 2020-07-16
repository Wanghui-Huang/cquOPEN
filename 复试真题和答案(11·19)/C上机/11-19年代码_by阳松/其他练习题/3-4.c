#include <stdio.h>
#include <string.h>

//输入一行字符串，把字符串翻转 。
//Input: I____am__a__student
//Output: student__a__am____I
void inverse (char *str,int m,int n);
void divide_word (char * str);
 
int main (){
	int m=0;
	int n;
	char str[20];
	gets(str);
	n=strlen(str);
	//先将字符数组 整个逆置
	inverse (str,m,n); 
//	printf("%s",str); 	
	//再将每个单词逆置 
	divide_word (str); 
	printf("转置后的数组\n"); 
	printf("%s",str); 
	
	return 0;
}

void inverse (char *str,int m,int n)			//inverse 的两个参数是字符数组的 头  和尾 
{
	
	int i,j;
	char temp;
	i=m;
	j=n-1;
	while (i<j)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
	return ;
}


void divide_word (char * str)
{
	int i;
	int index=-1;
	int flag=0;
	int len;
	len=strlen(str);
	
	for(i=0;i<len;i++)
	{
		if(isupper(str[i])||islower(str[i]))
		{
			if(flag==0)			//单词开始 
			{
				flag=1;
				index=i;
			}
		}else
		{
			if(flag==1)			//单词结束 
			{
				flag=0;
				inverse(str,index,i); 
				index=-1;
			}
		}
		
	}
	
	if(index!=-1)			//特殊情况，最后一个单词后面没得其他符号，直接结束 
	{
		inverse(str,index,i); 
	}
} 


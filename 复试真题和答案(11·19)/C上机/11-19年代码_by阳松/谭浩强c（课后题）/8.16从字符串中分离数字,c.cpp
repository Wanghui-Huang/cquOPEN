#include<stdio.h> 
#include <string.h>
//8.16  输入一个字符串，将其中的 连续的数字作为一个数，依次存放在int数组中 
 
#define M 100
int divide_number (char *str,int *ret);

int main ()
{
	char str[M];
	int ret[M];
	gets(str); 
	int i,cnt;
	cnt=divide_number (str,ret);
	for(i=0;i<cnt;i++)
	{
		printf("%d\n",ret[i]);
	}
	return 0;
}

int divide_number (char *str,int *ret)
{
	int len=strlen(str);
	int i;
	int cnt=0;	//cnt 代表数字的个数 
	int flag=0;		//flag==0 代表数字没开始，flag==1代表数字开始 
	int sum=0;//sum代表数字的值 
	
	for(i=0;i<len;i++)
	{
		if(str[i]>='0'&&str[i]<='9') 
		{
			if(flag==0)		//数字开始 
			{
				flag=1;
				sum=str[i]-'0';
				
			}else if(flag==1)
			{
				sum=sum*10+str[i]-'0';
			} 
		}else 
		{
			if(flag==1)		//数字结束 
			{
				ret[cnt]=sum;
				sum=0; 
				cnt++;
				flag=0; 
			}
		}
	}
	if(flag==1)		//flag==1，代表当前最后一个数字还没记录 
	{
		ret[cnt]=sum;
		cnt++;
		
	}
	return cnt;
}

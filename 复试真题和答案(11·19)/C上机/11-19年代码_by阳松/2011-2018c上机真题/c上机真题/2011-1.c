#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//水仙花数。读入文件 number.in 数字每行一个，
//以 0 输入结束。
//判断是否是水仙花 数，
//并输入到 number.out 文件中。
int is_shuixianhua (int x);

int main ()
{
	int temp;
	FILE *fin,*fout;
	fin=fopen("number.in","r");
	fout=fopen("number.out","w");
	
	if(fin==NULL||fout==NULL)
	{
		printf("文件打开失败");
		exit(1); 
	}
	
	fscanf(fin,"%d",&temp);
	while (temp!=0)
	{
		if(is_shuixianhua (temp))
		{
			fprintf(fout,"%c\n",'T');
		}else
		{
			fprintf(fout,"%c\n",'F');
		}
		
		fscanf(fin,"%d",&temp);
	}

	fclose(fin);
	fclose(fout);
	
	
	return 0;
} 



int is_shuixianhua (int x)
{
	int n;
	int sum=0;
	int len=0;
	int temp;
	
	n=x;
	while (n>0)
	{
		len++;
		n/=10;
	}
	
	n=x;
	while (n>0)
	{
		temp=n%10;
		n/=10;
		sum=sum+pow(temp,len);
	}
	
	if(len>=3&&sum==x)
	{
		return 1;	
	}else
	{
		return 0;	
	} 
}
 

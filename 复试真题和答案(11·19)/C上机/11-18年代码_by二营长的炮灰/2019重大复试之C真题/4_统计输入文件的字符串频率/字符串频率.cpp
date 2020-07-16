#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int* strFrequency(char s[]);

int main()
{
	FILE *in,*out;
	char s[MAX];
	int* nums,i; //记录字符频率
    in = fopen("string.in","r");
	out = fopen("string.out","w");
	if(!in || !out)
	{
		printf("打开文件失败！");
		exit(1);
	}
    fscanf(in,"%s",s);
	nums = strFrequency(s);
	for(i = 0 ; i < 256;i++)//写入文件out
	{
		if(nums[i]) //如果字符i（i是其ASCII码值）频率不为0就执行
			fprintf(out,"%c:%d\n",(char)i,nums[i]); 
	}
    fclose(in);
	fclose(out);
	return 0;
}

//[背]统计字符串频率:利用ASCII码0~256
//返回char*类型，不能用printf不好写，返回数组int* 
int* strFrequency(char s[] )
{ 
	int* nums = (int*)malloc(sizeof(int) * 256 );
	int i ;
	int len = strlen(s); // 玄：下面不能直接用strlen(s)
	memset(nums,0,sizeof(int) * 256 );//易错1：初始化指针前n字节为0，而不是len字节
	for(i = 0 ;i < len ; i++)
		nums[(int)s[i]] ++; //如：A的ASCII码对十进制64，num[64] = 1;
	return nums;
}
#include<stdio.h>
#include<string.h>

int mystrcmp(char* s1,char* s2);
int main()
{
   char s1[100],s2[100];
   printf("请输入两个字符串，中间逗号隔开：\n");
   scanf("%s %s",&s1,&s2);
   printf("结果：%d",mystrcmp(s1,s2));
   return 0;
}

//实现strcmp
int mystrcmp(char* s1,char* s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int lm = len1 < len2 ? len1:len2;
	int i;
	for(i = 0 ; i < lm ; i++)
	{
		if(s1[i] - s2[i] > 0)
			return 1;
		else if(s1[i] - s2[i] < 0)
			return -1;
		else //相等
			continue;
	}
	//执行到着还没分出来
	if(len1 == len2) return 0;
	return len1 > len2 ? 1:0; //长度大的大
}
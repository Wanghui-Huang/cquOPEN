
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int mystrcmp(char* s1,char* s2);
int isSym(char* s);
int main()
{ 
  char* s[10] ; //错误理解，无需malloc这里表示10个字符指针
  char* temp; 
  int N =0 ; //记录字符串个数
  int i,j,k=0;
  printf("请输入多个字符串，输入null结束:\n");
  //ATTENTION 1 ：用户不知道输入多少个字符串
  while(1) //由于{}里面还要分配内存，不能while里赋值
  {
	  s[N] = (char*)malloc(sizeof(char)*MAX);//易错1：分配内存s[i]
	  scanf("%s",s[N]);
	  if(strcmp(s[N],"null") == 0)
		  break;//易错2 ：不能 s[i++] == "null"！
	  N++;	  
  }
  //剔除非对称的字符串
  for(i = 0 ; i < N ; i++)
  {
	  if(isSym(s[i]))
		  s[k++] = s[i]; 
  }
  N = k;  //是回文串的字符串长度
  //[背]冒泡排序模板
  printf("排序后输出结果为：\n");
  for(i = 0 ; i < N ; i++) //不写N-1，为了输出s[N-1]
  {
	  for(j = N-1 ;j > i;j--) //每一轮把交换左右把最小放前面
	  {
		  if(mystrcmp(s[j],s[j-1]) < 0)
		  {
             temp = s[j];
			 s[j] = s[j+1];
			 s[j+1] = temp;
		  }
	  }
	  printf("%s\n",s[i]); //输出
  }
  return 0;
}

//比较字符串大小
//ATTENTION 2 :字符数组指针可以获取长度，int不行！
int mystrcmp(char* s1,char* s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1 > len2) return 1;
	if(len1 < len2) return -1;
	if(len1 == len2) return strcmp(s1,s2);
}

//[背]判断是否回文：反转字符模板
int isSym(char* s)
{
  int len = strlen(s);
  int i = 0 ,j = len-1;
  while(i < j)
  {
	  if(s[i++] != s[j--])
		  return 0;
  }
  return 1;
}
*/

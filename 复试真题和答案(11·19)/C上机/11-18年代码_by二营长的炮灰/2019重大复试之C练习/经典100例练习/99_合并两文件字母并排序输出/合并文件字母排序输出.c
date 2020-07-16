#include<stdio.h>

void mysort(char* s); //排序传指针方便
int main()
{
  FILE* in1,*in2,*out;
  char s1[100],s2[100];
  in1 = fopen("txt1.in","r");
  in2 = fopen("txt2.in","r");
  out = fopen("txt3.out","w");
  if(!in1 || !in2 || !out)
	  exit(0); // 崩溃1:调试半小时是写成了exist(0)
  fscanf(in1,"%s",s1);
  fscanf(in2,"%s",s2);
  strcat(s1,s2);   //ATTENTION 1 :strcat()连接字符串
  mysort(s1);
  fprintf(out,"%s",s1);
  fclose(in1);
  fclose(in2);
  fclose(out);
  return 0;
}

//字符冒泡排序升序：按ASCII码
void mysort(char* s)
{
	int len = strlen(s);
	int i , j;
	char temp;
	for(i = 0 ; i < len-1;i++)
	{
		//从前往后把最大放后面：j=0开始，每次前>后就交换
		for(j = 0 ; j < len-1-i;j++) //ATTENTION 2:不是len-1
		{
			if(s[j]-s[j+1] > 0)//易错1:比较字符直接比,别用strcmp()!
			{
              temp = s[j];
			  s[j] = s[j+1];
			  s[j+1] = temp;
			}
		}
	}
}
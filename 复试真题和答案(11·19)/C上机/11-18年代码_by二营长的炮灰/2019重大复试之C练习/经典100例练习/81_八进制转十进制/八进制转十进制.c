#include<stdio.h>
#include<math.h>
#define MAX 100

int octToDec(int oct);
int main()
{
	int oct;
	printf("请输入一个八进制数：");
	scanf("%d",&oct);
	printf("对应的八进制数是：%d",octToDec(oct));
	return 0;
}

/*
  八进制转十进制：用[循环获取低位数字并操作]模板
   special: 这里计算是从高位开始求十进制，每次循环前面结果权重*8
*/
int octToDec(int oct)
{
	int sum = 0 ,temp = oct;
	int i;
	for(i = 0 ; temp != 0 ; i++)
	{
		sum += (temp%10) * pow(8,i);
		temp = temp/10;
	}
    return sum;
}







/*
#include<stdio.h>
#include<string.h>

int _8to10(char* s);
int main()
{
	char s[100];   //易错 1：直接定义指针不初始化
	scanf("%s",s); //注：获高位%s，且循环获取低位操作模板最好%d(有%、/等操作)
    printf("%d",_8to10(s));
	return 0;
}

/*
  八进制转十进制：01234567（从高位开始操作）
      1.从最高位开始，初始：sum = 0
	  2.每一位： sum = sum*8 + s[i] -'0';
    (相当于每循环增加一低位，前面数字权重*8)

int _8to10(char* s)
{
    int sum = 0; //
	int i;
	for(i = 0 ; i < strlen(s);i++)
	{
       sum = sum * 8 + s[i] -'0';
	}
    return sum;
}
*/
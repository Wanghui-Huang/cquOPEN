#include <stdio.h>
#include <string.h>

//从键盘输入一个字符串，并将其中的小写字母全部转换为大写字母，
//并将结果保存在 E:\test.txt 文件中。如：
#define size 100
int main ()
{
	int i=0;
	FILE *fout=fopen("E:\\test.txt","w");
	char str[size];
	gets(str);
	
	while (str[i]!='\0')
	{
		if(islower(str[i]))
		{
			str[i]-=32;
		}
		i++;	
	}
	
	printf("%s",str);//对字符数组输出%d,输出%d时应该是输出数组的第一个元素的地址，即str[0]地址
	fprintf(fout,"%s",str);
	return 0;
}

#include<stdio.h>
#include<string.h>
 
int main(int argc,char* argv[]) //二维字符数组
{
  int i , j , flag ;
  char* temp;
  for(i = 1 ; i < argc - 1 ; i++) //冒泡n-1轮，这里第0次不排
  {
	flag = 0 ; //哨兵
    for(j = argc-1; j - i > 0 ; j--)//执行argc-1-i次
	{
      if(strcmp(argv[j-1],argv[j])>0)//错误0：>0,-1也会执行
	  {
        temp = argv[j];
		argv[j] = argv[j-1];
		argv[j-1] = temp;  //错误1:写成 argv[j-1] = argv[j];
        flag = 1; //哨兵，发生交换
	  }
	}
	if(flag == 0) 		break; 
  }
 //输出
  for(j = 0 ; j < argc ; j++)
	  printf("%s\n",argv[j]);
  return 0;
}

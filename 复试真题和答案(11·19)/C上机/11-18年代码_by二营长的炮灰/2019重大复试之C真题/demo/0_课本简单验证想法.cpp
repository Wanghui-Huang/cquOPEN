#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct student
{
	int name;
	int ID;
};
int isNarcissisticNumber(int num);
int main()
{

	/*
	    //1.float有效位只有6-7位，double类型15位
	float  a = 123456789.123;
    double b = 123456789.123;
	printf("f = %f",a);
    printf("d = %f",b);//输出都是%f，表示输出浮点数？
	   //2.结构体的调用
    struct	student s; // 等价 struct student s ；
	s.ID = 1; 
	printf("%d",s.ID);
		//3.水仙花数调试
	int a = isNarcissisticNumber(153);
	if(a == 1)
	{
		printf("是水仙花数！");
	}
	else
	{
        printf("不是水仙花数！");
	}
	*/
	/*
        //4.测试if(2),if(3)..执行与否
	if(0)
	{
		printf("0\n");  //除了if(0)不执行，其余无论正负都执行
	}
	if(-1)
	{
		printf("-1\n");
	}
    if(1)
	{
		printf("1\n");
	}
	if(2)
	{
		printf("2\n");
	}
	if(800)
	{
		printf("800\n");
	}
	*/
	/*
	  //5.测试char类型一些性质
	//char c2;
	 char c = '0';         //ATTENTION 1 :用单引号存数字0
	 printf("%c\n",c);  //输出0
	 printf("%d\n",c);  //输出0 ASCII码值48
	 char c1 = 48;         //ATTENTION 2 :也可以直接存储0 ASCII值
	 printf("%c\n",c1); //输出0
	 printf("%d\n",c1); //输出ASCII码值48
	 char  c2 = c + 40;    //ATTENTION 3 :char类型可以直接和数字相加 = 其加后的ASCII码值
	 printf("%c\n",c2); //输出 X
	 printf("%d\n",c2); //输出 88(X对应的ASCII值)
	 char  c3 = c + 257;    //ATTENTION 4 :如果越界超出ASCII码值256会自动循环
	 printf("%c\n",c3); //输出 1
	 printf("%d\n",c3); //输出 49
	*/
	 //6.测试字符指针数组一些性质
	  int len;
	  /*
	  char *p ;
	  p = "hello"; //如果p是数组不能赋值，因为此时p常量
	  len = strlen(p); //此时长度等于5
      
	  char *p = (char*)malloc(sizeof(char)*100);
      p = "1"; 
	  len = strlen(p); //此时长度等于1
	  p[0] = 0;
	  */
	  int A[256] = {0};
	  char c = '0';
	  A[c] = 1;
	  return 0;
}

//n位水仙花数：该数 = 个位数^n + 十位数^n + 百位数^n + ...
int isNarcissisticNumber(int num)
{
  int count = 0;//判断是几位数
  int sum   = 0;//计和
  int temp  = num; //用来计算count临时变量
  while(temp != 0)
  {
	  temp = temp / 10; //每次都去掉最低位，直至为0:153 - 15  15- 1 1-0
	  count++;
  }
  temp = num;      //易错①：再次存储num值，而不是用num进行计算，否则最后num=0，不能和sum比较
  while(temp != 0)
  {
	  sum += pow(temp % 10 ,count); //获取最低位的n次方
	  temp = temp/10;//去掉最低位，由n位-->n-1位数字
  }
  if(sum == num){ return 1; }
  else          { return 0; }
}
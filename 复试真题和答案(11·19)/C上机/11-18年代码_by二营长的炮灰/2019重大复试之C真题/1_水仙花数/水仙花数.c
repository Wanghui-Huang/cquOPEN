#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isNarci(int num);
int main()
{
	int num;
	FILE* in,*out;
	in  = fopen("number.in","r");
	out = fopen("number.out","w");
	if(!in || !out)
	{
		printf("failture to open file!");
		exit(1);
	}
	//循环读写文件+判断
	while(1)
	{
		fscanf(in,"%d",&num);
		if(num == 0)  //如果无0判断结束，也可while(!feof(in)) 
			break;
		if(isNarci(num))
			fprintf(out,"%s","T\n"); //再错0:\n用%s而不是%c
		else
			fprintf(out,"%s","F\n");	    
	}
	fclose(in);  //再错1：不关闭文件流，输出文件不会显示
	fclose(out);
    return 0;
}

//n位水仙花数（n＞=3）：该数 = 个位数^n + 十位数^n + 百位数^n + ...
int isNarci(int num)
{
	int n = 0;  //判断几位数，使用前要置0！
	int temp = num;
	int sum = 0; //计算水仙花数
	while(temp != 0) //背：判断几位数不熟练
	{
		n++;
		temp = temp / 10;
	}
	if(n <3 )
		return 0;  //易忘
	temp = num;     //再错2：下面改变num，上面temp也不再是num，重新赋值
	while(temp != 0)
	{
		//temp = temp % 10; //再错3:temp只会改变去低位！temp/10！
		sum += pow(temp%10,n);
		temp = temp / 10;
	}
	return num == sum;
}










/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void readFile(FILE* in);             //易错0：不能返回数组
void outPutFile(FILE* out);          //易错1：int[] num错误；FILE需大写
int isNarcissisticNumber(int num);
#define MAXSIZE 100
int nums[MAXSIZE];       //返回值不能是数组，定义返回指针不方便干脆全局数组

void main()
{
	FILE* in,* out;                 //易错2：只能在开头定义文件FILE类型指针，不能分别定义
	//打开文件number.in，注意“r”
    in = fopen("number.in","r"); 
	if(!in)
	{
		printf("Failturn to open file!");
	}
	//int nums[] = readFile(in);       //易错3：数组名是指针常量，定义全局数组
    readFile(in);
	fclose(in);

	//打开文件number.out，注意“w”
	out = fopen("number.out","w"); 
	if(!out)
	{
		printf("Failturn to open file!");
	}
    outPutFile(out);
	fclose(out);
}


//n位水仙花数（n＞=3）：该数 = 个位数^n + 十位数^n + 百位数^n + ...
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
  if(count < 3) //水仙花数位数必须≥3
  {
	  return 0;
  }
  temp = num;      //易错4：再次存储num值，而不是用num进行计算，否则最后num=0，不能和sum比较
  while(temp != 0)
  {
	  sum += pow(temp % 10 ,count); //获取最低位的n次方
	  temp = temp/10;//去掉最低位，由n位-->n-1位数字
  }
  if(sum == num){ return 1; }
  else          { return 0; }
}


//操作文件number.in:将文件数据写入数组
void readFile(FILE* in)
{
	int i = 0; 
	while(!feof(in))   //易错5:别用for循环
	{
      fscanf(in,"%d",nums+i); //易错6: %s -->%d
	  i++;
	}

}

//操作文件number.out:判断是否是水仙花数并写入
void outPutFile(FILE* out)
{
	int i ;
	for(i = 0; nums[i] != 0;i++)       //易错7：c语言for循环不能在里面定义 int i=0
	{
		if(isNarcissisticNumber(nums[i]))//是水仙花数
		{
         fprintf(out,"%s","T\n");
		}
		else
		{
         fprintf(out,"%s","F\n");
		}
	}
}
*/
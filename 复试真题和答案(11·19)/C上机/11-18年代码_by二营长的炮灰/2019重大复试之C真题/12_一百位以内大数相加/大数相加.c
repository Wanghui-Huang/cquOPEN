#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char* bigNumAdd(char* a,char* b);
int main()
{
	char a[MAX], b[MAX] ,*result;
	printf("请输入大数a b，空格隔开：");
	scanf("%s %s",&a,&b);
	result = bigNumAdd(a,b);
	//result = bigNumAdd("112233445566778899","998877665544332211");
	printf("结果为：%s",result);//结果第一位可能为0
	return 0;
}
/*
  大数相加：，
  1.[背1]如何将字符串a右移（已知右移后长度lm）
     (1) 设置 i = la-1,k = lm-1分别指向移动前/后末尾
	 (2) 当i大于等于0时：a[k] = a[i] //再错1：注意=号
	     当i大于等于0时：//其他操作如填0
  2.[背2]尾数起加，每次存1，其余进位
*/

char* bigNumAdd(char* a,char* b)
{
	char* result = (char*)malloc(sizeof(char)*(MAX+1));
	int la,lb,lm; //长度
	int i,j,k;    //位移控制
	int ta,tb,t,carry = 0;  //低位相加临时保存
	la = strlen(a);
	lb = strlen(b);
	lm = la > lb ? la : lb;
	lm = lm+1;   //再忘1：此时lm表示化为标准后的长度
	for(i=la-1,j=lb-1,k=lm-1; k>=0 ;i--,j--,k--) //不是k<0 
	{
		if( i >= 0)	a[k] = a[i];
		else        a[k] = '0'; //再错1：字符串添0 加''
		if( j >= 0)	b[k] = b[j];
		else        b[k] = '0';
	}
	//已化标准，开始相加，只保存计算的数字最低一位，其余进位
	for(i = lm-1 ; i >=0  ; i--)
	{
		ta = a[i]-'0';
		tb = b[i]-'0';
		t = ta + tb + carry;
		result[i] = t % 10 + '0'; //只保存最低一位
		carry = t / 10;   //其余进位   
	}
	a[lm] = b[lm] = result[lm] = '\0'; //再错2：字符串一定设置末尾
    return result;
}

















/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
char* bigNumAdd(char num1[],char num2[]);
int main()
{
 char* result;
 int i = 0;
 //result = bigNumAdd("112233445566778899","998877665544332211");
 //result = bigNumAdd("123456","34567");
 result = bigNumAdd("987654321","56789");
 //输出结果
 if(result[0] == '0')//第一位为0不输出
 { 
		i = 1;
 }
 for( ; i < strlen(result);i++)
 {
      printf("%c",result[i]);
 }
 return 0;
}

//大数相加：利用字符数组模拟进位相加
char* bigNumAdd(char num1[],char num2[])
{
  //先处理字符串：99+8 = 099 + 008
    //ATTENTION 1 :strlen()返回长度18，而不是sizeof()数组总长度100
	int l1,l2,lm,i,j,flag = 0 ,x,y,z;
    char* n1 ,*n2 , *result,c1,c2; //存储处理后的字符串和结果
	l1 = strlen(num1);
	l2 = strlen(num2);
	lm = l1 > l2 ? l1:l2;//获取最大长度
	n1 = (char*)malloc(sizeof(int) * (lm+2));//ATTENTION 3: +2！
	n2 = (char*)malloc(sizeof(int) * (lm+2));
	result = (char*)malloc(sizeof(int) * (lm+2));
	//错误1：都是lm+1不是lm
	//错误2：char型数组末尾不添\0疯狂报错
	//错误3：n1[i] = num1[i]; 应该是num[j++]
	       //而且最好分开处理！否则两个j++出错
	n1[lm + 1] = n2[lm + 1] = result[lm + 1] = '\0'; 
    for(i = 0 ,j = 0; i < lm + 1; i ++)//数组高位补0
	{
        if(lm + 1 - i > l1) 
			n1[i] = '0';   
		else           
			n1[i] = num1[j++]; 
	}
	for(i = 0 ,j = 0; i < lm + 1; i ++)//数组高位补0
	{
        if(lm + 1 - i > l2) 
			n2[i] = '0';   
		else           
			n2[i] = num2[j++]; 
	}

  //开始模拟进位运算
	//易错4：指针初始在末尾是lm，不是lm-1，前面已添0
	for(i = lm  ; i >= 0 ; i--) 
	{
	// ATTENTION 2:-'0' ：表示char转int；+'0':表示 int 转 char
	  //易错5【char和int互转】:(int)n1[i]获取的是ASCII码，出错
	   x = n1[i] - '0';
	   y = n2[i] - '0';
	   z = x + y + flag;
	   if( z >= 10) //有进位
	   {
         flag = 1 ; //标识进位，两个数相加最多进1
		 z = z % 10 ;
	   }
	   else
	   {
		   flag = 0 ; //错误6：无进位时要标识0！否则一直1
	   }
	   result[i] = z + '0'; //第一位可能为0
	}
	return result;
}
*/
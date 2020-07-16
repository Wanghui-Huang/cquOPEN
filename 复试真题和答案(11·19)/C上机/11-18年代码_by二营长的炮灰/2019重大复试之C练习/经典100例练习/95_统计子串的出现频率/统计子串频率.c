#include<stdio.h>
#include<string.h>
#define MAX 100

int match(char* mainstr,char* substr);
int main()
{
	char mainstr[MAX],substr[MAX];
	int times;
	printf("请分别输入主串和子串，空格隔开：\n");
	scanf("%s %s",mainstr,substr);
	times = match(mainstr,substr);
	//times = match("ABCCDFEFCDCDFFCD","CDF");
	printf("子串在主串出现的频率是：%d",times);
	return 0;
}
/*
  计算子串在主串中匹配成功的次数：一次遍主，但不到尾。i赋变k，减一复j
    1.一次遍主，但不到尾。
    2.i赋变k。每次i进来一次都要用k=i，遍历子串是否匹配。
    3.减一复j。判断j==len，匹配成功i位移slen-1，j复原到0（易错）
*/
int match(char* m,char* s)
{
	int mlen = strlen(m),slen = strlen(s);
	//int flag = 1; //标识是否完全匹配成功子串[可以j==len判断，同时免去循环break]
	int i,j,k,first = 0;
	int times = 0; //再错0：注意初始化
	for(i = 0 ; i <= mlen-slen ; i++)//再错1：一次遍主，但不到尾
    {
		if(m[i] == s[0])//和子串首匹配
		{
           first = i;   
		   for(k = i+1,j = 1; m[k]==s[j] && j < slen;k++,j++);//kj后移判断
		}
		if(j == slen)
		{
			times++;
		    i += slen-1; //ATTENTION 0:这里还会i++，故减1
			j = 0; //再错1：防止下次匹配失败循环错误判断j==len
		}
	}
	return times;
}













/*
#include<stdio.h>
#define MAX 100

int count(char* mainstr,char* substr);
int betterCount(char* m,char* s);
int main()
{
  int n;      //统计子串出现次数
  /*
  char mainstr[MAX],substr[MAX];
  gets(mainstr);  //获取主串ABCCDFEFCDCDFFCD
  gets(substr);  //获取子串CDF
  n = count(mainstr,substr);
  
  n = betterCount("ABCCDFEFCDCDFFCD","CDF");
  printf("子串出现频率：%d",n);
  return 0;
}

//统计子串出现次数
int count(char* mainstr,char* substr)
{
  int mlen = strlen(mainstr);
  int slen = strlen(substr);
  int count =0 , i ,j ,first; //错误1：一定要初始化！！否则后面count++出错！！
  for(i = 0 ; i < mlen ; i++)//一次遍历母串
	  if(mainstr[i] == substr[0]) //出现了第一次匹配子串
	  {
		  first = i++; //存储i刚进来的位置 AND i+1 ，j+1(下面)
          for(j = 1 ; j < slen && i < mlen; j++) //ATTENTION 1：别让i超限
		  {
             if(mainstr[i++] != substr[j]) //匹配失败，i重置最开始进来
			 {
               i = first; //匹配失败复原i进来的位置然后++；成功i指针+子串长度。
			   break; //退出循环
			 }
		  }	
	      if(j == slen) count++; //错误2：要加if(j == slen)，否则j<slen匹配成功会+1！
	  }
	  return count;
}

/*
  更好的代码：统计子串出现次数
    ①i <= mlen - slen，减少匹配次数，同时for循环条件不用担心k>=melen
	②k=i,不用存i初始值，i值不会被改变。下次循环一定执行下一个
	   但是匹配成功时：也要指向下一个，不会i+子串长度减少匹配(已优化)
	③ 同时s[j] == m[k]写在for里，起到不满足就break效果，减少代码
  
int betterCount(char* m,char* s)
{
  int mlen = strlen(m);
  int slen = strlen(s);
  int count =0 , i ,j ,k;
  for(i = 0 ; i <= mlen - slen ; i++)  //小于子串长度就不匹配，注意=
  {
      for(j = 0 , k = i ; j < slen && s[j] == m[k] ; j++,k++);
	  if(j == slen)
	  {
        count++; 
		i = i + slen-1; //匹配成功,i直接后移slen-1.注意-1，因为i还会进入循环i++
	  }
  }
	  return count;
}
*/
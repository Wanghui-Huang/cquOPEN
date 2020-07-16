#include<stdio.h>

char* dectohex(int num);
int main()
{
	char* hex;
	int num;
	printf("请输入一个十进制数：");
	scanf("%d",&num);
	hex = dectohex(num);
    printf("%s",hex);
	return 0;
}

char* dectohex(int num)
{
	char* hex = (char*)malloc(sizeof(char)*100);
	char temp;
	int q; //商
	int r; //余数
	int i = 0 , j = 0;
	while(q != 0)
	{
		q = num / 16;
		r = num % 16;
		if(r >= 10) hex[i++] = r - 10 + 'A'; //巧：大于10 char类型也存不了，刚好存A..F
        else        hex[i++] = r;
		num = q;
	}
	hex[i] = '\0';   //易错！
    //交换使得hex逆向，从而正序 
	for(i = i-1,j =0 ;j < i;i--,j++)//为方便i指向最后一个字符，而非'\0'
	{
      temp = hex[i];
	  hex[i] = hex[j];
	  hex[j] = temp;
	}
    return hex;
}

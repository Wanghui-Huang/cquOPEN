#include <stdio.h>
//非负16进制数相加 
int main ()
{
	__int64 add1,add2,sum;
	scanf("%I64x %I64x",&add1,&add2);
	sum=add1+add2;
	printf("%I64x",sum);
	
	return 0;
}

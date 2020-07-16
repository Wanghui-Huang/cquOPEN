#include <stdio.h>
#include <time.h> 
//∫∫≈µÀ˛Œ Ã‚ 
void hanota (int n,char source,char mid,char destination);
void move (char source,char destination);

int main ()
{
	int n;
	scanf("%d",&n);
	clock_t start=0;
	clock_t end=0;
	start=clock();
	hanota(n,'A','B','C');
	end=clock();
	printf("%lf",(double)(end-start) / CLOCKS_PER_SEC);
	return 0;
}

void hanota (int n,char source,char mid,char destination)
{
	if(n==1)
	{
		move(source,destination);
	}else
	{
		hanota(n-1,source,destination,mid);
		move(source,destination);
		hanota(n-1,mid,source,destination);
	 } 
	

}

void move (char source,char destination)
{
	printf("%c--%c\n",source,destination);
}

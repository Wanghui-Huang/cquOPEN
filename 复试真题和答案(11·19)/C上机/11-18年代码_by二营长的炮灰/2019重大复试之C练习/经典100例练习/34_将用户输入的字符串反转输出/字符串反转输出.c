#include<stdio.h>
#include<string.h>

void reverse(char s[]);
int main()
{
	char s[100] = "2019-CQU-The cannon fodder of the second battalion commander";
	int i = 0;
	//while( s[i++] != '\0' ); //i指向末尾'\0'处
    reverse(s);
	while( i < strlen(s) ) 
		printf("%c",s[i++]); 
	return 0;
}

//反转
void reverse(char s[])
{
  int len = strlen(s);
  int i , j ;
  char temp;
  //ATTENTION 1：i<j 不是 i<=j 
  for(i = 0 , j = len-1 ; i < j ; i++,j--)
  {
    temp = s[i];
	s[i] = s[j];
	s[j] = temp;
  }
}

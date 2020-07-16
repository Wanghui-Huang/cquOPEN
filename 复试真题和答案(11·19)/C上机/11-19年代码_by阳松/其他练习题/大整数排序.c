#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWP(a,b) {char *t;t=a;a=b;b=t;}

int compare (const void *a,const void *b);

int mycmp (char *str1,char *str2);


int main ()
{
    int n;
    char *str[105];
    char *temp;
    int i,j;
    while (scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            
			temp=(char *)calloc(1001,sizeof(char));
            scanf("%s",temp);
            str[i]=temp;
        }
        
//        qsort(str,n,sizeof(char *),compare);
        
        for(i=n-1;i>0;i--)
        {
            for(j=0;j<i;j++)
            {
            	if(mycmp(str[j],str[j+1]) >0 )
				{
            		SWP(str[j],str[j+1]);
				}
			}
        }
        
        for(i=0;i<n;i++)
        {
            puts(str[i]);
        }
	
	}
    
    
    
    return 0;
}

int mycmp (char *str1,char *str2)
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len1>len2)
    {
        return 1;
    }else if(len1<len2)
    {
        return -1;
    }else
    {
        return strcmp(str1,str2);
    }
}

int compare (const void *a,const void *b)
{
    char * str1,*str2;
    str1=(char *)a;
    str2=(char *)b;
    return mycmp(str1,str2);
}

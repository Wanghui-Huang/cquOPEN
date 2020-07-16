#include <stdio.h>

//Æ¹ÅÒÇò±ÈÈü  

int main ()
{
	int i,j,k;
	char x,y,z;
	for(i='x';i<='z';i++)
	{
		for(j='x';j<='z';j++)
		{
			if(i!=j)
			{
				for(k='x';k<='z';k++)
				{
					if(i!=k&&j!=k)
					{
						if(i!='x'&&k!='x'&&k!='z')
						{
							printf("A--%c\nB--%c\nC--%c",i,j,k);
						}
					}
				}
			}
		}
	}
	
	return 0;
} 

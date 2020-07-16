#include <stdio.h> 


//ººÅµËþÎÊÌâ 
void hanota (int n,char A,char B,char C);

int main (){
	int n;
	scanf("%d",&n);
	
	hanota(n,'A','B','C');
	
	
	return 0;
}


void swap (char A,char B){
	
	printf("%c -->%c\n",A,B);
	
}

void hanota (int n,char A,char B,char C){
	if (n==1){
		swap(A,C);
	}else{
		hanota(n-1,A,C,B);
		swap(A,C);
		hanota(n-1,B,A,C);	
	}
	
}

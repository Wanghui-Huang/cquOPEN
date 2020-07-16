#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//附加题：大整数加法。 实现任意范围的两个整数的加法（ 整数的范围用 int 型的/变量无法表
#define  N 100

int * bignum_add(char *str1,char *str2); 
int main (){
    
    int *ret;
    int i;
    int cnt=0;
    char str1 [N],str2[N];
    scanf("%s%s",str1,str2);
    
    ret=bignum_add(str1,str2);

    for(i=N-1;i>=0;i--){
        if(ret[i]>0){
            cnt=i;
            break;
        }
    }
    
    printf("输出结果");
    for(i=cnt;i>=0;i--){
        printf("%d",ret[i]);
    }
    return 0;
}


int * bignum_add(char *str1,char *str2){
    
    int *ret;
    int num1[N]={0},num2[N]={0};
    int len_1,len_2;
    int max;
    int i,j;
    
    len_1=strlen(str1);
    len_2=strlen(str2);
    max= len_1<len_2? len_2:len_1 ;
    ret=(int *)calloc(N,sizeof(int));
    
    for(i=0,j=len_1-1;j>=0;j--,i++){
        
        num1[i]=str1[j]-'0';
    }
    
    for(i=0,j=len_2-1;j>=0;j--,i++){
        
        num2[i]=str2[j]-'0';
    }
    
    for(i=0,j=0;i<max;i++){
        
        ret[j]+=(num1[i]+num2[i]);
        if(ret[j]>=10){
            ret[j+1]+=ret[j]/10;
            ret[j]=ret[j]%10;
        }
    	j++;
	}
    
    return ret;
    
    
    
    
    
}


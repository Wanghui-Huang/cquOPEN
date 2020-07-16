#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
//求一个字符串数组的最大值和次大值  void big(char *arr[],int size ,char** big1,char** big2)

#define N 100
void char_sort (char * s[N],int n);


int main(){

    int i=0;
    int cnt=0;
    char * s[N];
    char temp [N];
    
    while (scanf("%s",temp)!=EOF){
        s[i]=(char *)malloc(sizeof(char)*N);
        strcpy(s[i],temp);
        i++;
    }
    
    cnt=i;
    char_sort (s,cnt);
    
    printf("%s\t%s",s[cnt-1],s[cnt-2]);
    
    
    return 0;
    
}

void char_sort (char * s[N],int n){
    
    char *temp;
    int i,j;
    
    for(i=n-1;i<0;i--){
        for(j=0;j<i;j++){
            if(strcmp(s[j],s[j+1])==1){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=s[j];
            }
        }
    }

    
    return;
}


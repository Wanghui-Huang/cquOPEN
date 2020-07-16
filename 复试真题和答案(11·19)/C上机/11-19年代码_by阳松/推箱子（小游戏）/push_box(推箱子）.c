# include <stdio.h>
#include <conio.h>
#include <windows.h>

typedef struct {	
	char name [20];				//用户名 
	char password[20];			//密码 
	int gate;					//关数记录 
}user;

void Register ();
int  Login ();
void play ();
void ReadMap(char map[14][16], int n);
void get_person(int *x,int *y,char map[14][16]);
void presskey(char map[14][16],int *end); 
void chose_gate (int key,int *ret);
void save_counts();
void open_counts(); 

void printmap(char map[14][16]);


user players[20];			//结构体数组，存储用户数据 
int cnt;					//代表用户数 

int main (){
	
	char judge;
	int key;
	open_counts();
	
	printf("欢迎进入推箱子游戏"); 
	while(1){
		printf("\n****************\n"); 
		printf("1. 注册新用户\n");
		printf("2. 登录\n");
		printf("3. 作者信息\n");
		printf("4. 退出程序\n");
		
		judge=getch();
		switch(judge){
			case '1' :
				Register();				//注册新用户模块 
				break;
				
			case '2' :
				key=Login ();				//登录并游玩游戏 
//				开始选关并游玩 
				play (key);
				break;
				
			case '3' :
				printf("\n****************\n"); 
				printf("作者\n");
				printf("\n");
				printf("@孙笑川");
				printf("\n****************\n"); 
				break;
				
			case '4' :
				save_counts();
				return 0;
				
			default :
				printf("输入有误，请重新输入"); 
				break;			
		}
		
		
	} 
	
}



void Register (){

	char temp [20],confirmpassword[20];
	user nuser; 				//新用户 
	
	int i,flag=1;				//flag =1  代表用户输入的用户名没有重复，否则用户名重复 

	
	
	
	while (1){
		flag=1;//默认用户名不重复，flag==1, 
		printf("请输入用户名");
		scanf("%s",temp);
		 
		for(i=0;i<cnt;i++){
			if(strcmp(players[i].name,temp)==0 ){
				printf("用户名已存在\n");
				flag=0; 
				break;
			}
		}
		
		if(flag==1){
			strcpy(nuser.name,temp);
			break;
		}
		
	}
	
	while (1){
		printf("请输入密码:");
		scanf("%s",temp);
		printf("确认输入的密码:");
		scanf("%s",confirmpassword);
		
		if(strcmp(temp,confirmpassword)==0) {
			strcpy(nuser.password ,temp);
			nuser.gate =1;		//默认新建用户的当前游玩关卡为 1，即没有开始游玩 , 
			players[cnt++]=nuser;					//将新建的用户，加入存储用户数据的数组中 
			break; 
		}
		printf("两次输入的密码不匹配\n");
	}
	

} 

void open_counts()
{
	FILE *fin;
	cnt=0;		//用户数最开始为 0； 
	fin=fopen("user.txt","r");
	
	if(fin==NULL){
		printf("读取用户数据失败");
		exit(1); 
	}
	
	while (!feof(fin)){	
		if(fread(&players[cnt],sizeof(user),1,fin)==1)
		{
			cnt++;		//统计账号个数; 
		}
	}
	fclose(fin);
}

void save_counts()		//将用户账户存入 user .txt 
{
	FILE *fout;
		//将用户数据数组写回 user.txt   中
	 
	fout=fopen("user.txt","w");
	if(fout==NULL){
		printf("写回用户数据失败");
		exit(1); 
	}
	fwrite(players,sizeof(user),cnt,fout);
	fclose(fout);
}


int  Login ()
{
	char temp [20],password[20];
	int i,key=-1;				//key  代表用户数据在用户数组中的下标 
	
//	user players[20];			//结构体数组，存储用户数据 

//	int cnt=0;					//代表用户数 
	
//	FILE *fin; 
//	fin=fopen("user.txt","r");
//	
//	if(fin==NULL){
//		printf("读取用户数据失败");
//		exit(1); 
//	}
	
//	while (!feof(fin)){
//		if(fread(&players[cnt],sizeof(user),1,fin)==1) 
//		{
//			cnt++;
//		}	
//	}
//	fclose(fin);
//	
	while (1){
		printf("请输入用户名：");
		scanf("%s",temp);
		 
		for(i=0;i<cnt;i++){
			if(strcmp(players[i].name,temp)==0 ){
				//找到目标用户 
				key=i; 
				goto breakHere;
			}
		}
		
		printf("您输入的用户名不存在\n");
		
	}
	
breakHere :
	
	while (1){
		printf("请输入密码：");
		scanf("%s",password);
		
		if(strcmp(players[key].password,password)==0 ){
				//找到目标用户 
				printf("登录成功\n");
				return key;			//返回登录成功的账号 key 为player 的下标 
			}else{
				printf("密码输入错误\n");
			}
	}
	
	
}

void chose_gate (int key,int *ret)
{
	int n;
	printf("\n1.接上次玩的关卡开始\n");
	printf("\n2.重新选择关卡\n");
	scanf("%d",&n);
	switch (n){
		case 1:
			n= players[key].gate ;
			break;
		case 2:
			while (1){
				printf("\n请选择关卡\n");
				scanf("%d",&n);
				if(n>=1&&n<=43){
					break;
				}else{
					printf("关卡范围为1-43\n");
				}
			}
	}

	*ret=n;
}


void play (int key){
	int n;
	int end =0;		//end ==1 是代表用户主动结束游戏 
	chose_gate (key,&n);
	char map[14][16];
	ReadMap(map,n);
	
	//开始 play 
	while (1){
		system("cls");
		printmap(map);			//打印地图 
		presskey(map,&end);
		if(end==1)
		{
			//结束游戏 
			system("cls");
			printf("\n****************\n"); 
			printf("\n结束游戏 ,欢迎下次在玩\n");
			printf("\n按任意键回到主菜单\n");
			players[key].gate =n;
			system("pause");
			break; 
		}else
		{
			if(countbox(map)==0){
				system("cls");
				printmap(map);	
				printf("恭喜通关，即将进入下一关\n");
				n++;
				
				if(n<=43){
					ReadMap(map,n);
				} else{
					printf("全部关卡都被你玩坏了\n");
				}
			}			
		}
	}
	
	
	
	
} 



void ReadMap(char map[14][16], int n)  //读地图
{
	FILE *fp;
	int i, j;
	int step;

	fp = fopen("map.txt", "r");

	if (fp == NULL) {
		printf("打开地图文件错误!\n");
		exit(1);
	}

	if (n < 10)
		step = 257 * (n - 1) + 5;
	else
		step = 257 * 9 + 258 * (n - 10) + 6;

	fseek(fp, step, 0);	//重定位文件内部位置指针，0为起点，step为偏移量 
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 16; j++) {
			map[i][j] = fgetc(fp);
		}
		fgetc(fp);				//换行符不读取 
	}
	fclose(fp);
}

void printmap(char map[14][16]){
/*0:		//空地
1:		//墙
2:		//内部空地
3:		//目的地
4:		//箱子
5:		//箱子推到目的地后显示
6:		//小人
7:      //人在目的地
*/
	int i, j;
	char t;
	
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 16; j++) {
			t=map[i][j];
			switch(t){
				case '0':
					printf("  ");
					break;
				case '1':
					printf("■");
					break;
				case '2':
					printf("  ");
					break;
				case '3':
					printf("×");
					break;
				case '4':
					printf("◎");
					break;
				case '5':
					printf("☆");
					break;
				case '6':
				case '7':
					printf("♀");
					break;
	
			}
			
			
			
		}
		
		printf("\n");
	}
	
	
	
}

void presskey(char map[14][16],int *end){
	int x,y;
	get_person(&x,&y,map);
	char opt;
	opt=getch();
	switch(opt){
		case 'w': 
		case 'W':
		case 38:
			if(map[x-1][y]=='2'){			//人前面是空地 
				if (map[x][y] == '7')//人在目的地
					{
						map[x][y] = '3';//目的地 
						map[x - 1][y] = '6';//人 
					}
					else //人在空地
					{
						map[x - 1][y] = '6';//人 
						map[x][y] = '2';//内部空地 
					}
			}else if(map[x-1][y]=='3'){		// 人前面是目的地 
				if(map[x][y]=='6'){//人当前所处的是空地 
					map[x][y]='2';
					map[x-1][y]='7'; 
				}else if(map[x][y]=='7'){//人当前所处的是目的地 
					map[x][y]='3';
					map[x-1][y]='7'; 
				}
			}else if(map[x-1][y]=='4'){		//人前面是箱子 
				if(map[x-2][y]=='2'){		//箱子前面是空地 
					if(map[x][y]=='6'){//人当前所处的是空地 
					
						map[x][y]='2';
						map[x-1][y]='6';
						map[x-2][y]='4';
						 
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x-1][y]='6';
						map[x-2][y]='4';
					}
				}else if(map[x-2][y]=='3'){		//箱子前面是目的地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x-1][y]='6';
						map[x-2][y]='5';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x-1][y]='6';
						map[x-2][y]='5';
					}
				}
			}else if(map[x-1][y]=='5'){		//人前面是箱子在目的地 
				if(map[x-2][y]=='2'){		//箱子前面是空地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x-1][y]='7';
						map[x-2][y]='4';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x-1][y]='7';
						map[x-2][y]='4';
					}
				}else if(map[x-2][y]=='3'){		//箱子前面是目的地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x-1][y]='7';
						map[x-2][y]='5';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x-1][y]='7';
						map[x-2][y]='5';
					}
				}
			}
		break;
		
		case 'a':
		case 'A':
		case 37:
			if(map[x][y-1]=='2'){			//人前面是空地 
				if(map[x][y]=='6'){//人当前所处的是空地 
					
					map[x][y]='2';
					map[x][y-1]='6'; 
					
				}else if(map[x][y]=='7'){//人当前所处的是目的地 
					
					map[x][y]='3';
					map[x][y-1]='6'; 
				}	
			}else if(map[x][y-1]=='3'){		// 人前面是目的地 
				if(map[x][y]=='6'){//人当前所处的是空地 
				
					map[x][y]='2';
					map[x][y-1]='7'; 
					
				}else if(map[x][y]=='7'){//人当前所处的是目的地 
				
					map[x][y]='3';
					map[x][y-1]='7'; 
				}
			}else if(map[x][y-1]=='4'){		//人前面是箱子 
				if(map[x][y-2]=='2'){		//箱子前面是空地 
					if(map[x][y]=='6'){//人当前所处的是空地 
					
						map[x][y]='2';
						map[x][y-1]='6';
						map[x][y-2]='4';
						 
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x][y-1]='6';
						map[x][y-2]='4';
					}
				}else if(map[x][y-2]=='3'){		//箱子前面是目的地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x][y-1]='6';
						map[x][y-2]='5';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x][y-1]='6';
						map[x][y-2]='5';
					}
				}
			}else if(map[x][y-1]=='5'){		//人前面是箱子在目的地 
				if(map[x][y-2]=='2'){		//箱子前面是空地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x][y-1]='7';
						map[x][y-2]='4';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x][y-1]='7';
						map[x][y-2]='4';
					}
				}else if(map[x][y-2]=='3'){		//箱子前面是目的地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x][y-1]='7';
						map[x][y-2]='5';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x][y-1]='7';
						map[x][y-2]='5';
					}
				}
			}
		break;
		
		case 'd':
		case 'D':
		case 39:
			if(map[x][y+1]=='2'){			//人前面是空地 
				if(map[x][y]=='6'){//人当前所处的是空地 
					
					map[x][y]='2';
					map[x][y+1]='6'; 
					
				}else if(map[x][y]=='7'){//人当前所处的是目的地 
					
					map[x][y]='3';
					map[x][y+1]='6'; 
				}	
			}else if(map[x][y+1]=='3'){		// 人前面是目的地 
				if(map[x][y]=='6'){//人当前所处的是空地 
				
					map[x][y]='2';
					map[x][y+1]='7'; 
					
				}else if(map[x][y]=='7'){//人当前所处的是目的地 
				
					map[x][y]='3';
					map[x][y+1]='7'; 
				}
			}else if(map[x][y+1]=='4'){		//人前面是箱子 
				if(map[x][y+2]=='2'){		//箱子前面是空地 
					if(map[x][y]=='6'){//人当前所处的是空地 
					
						map[x][y]='2';
						map[x][y+1]='6';
						map[x][y+2]='4';
						 
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x][y+1]='6';
						map[x][y+2]='4';
					}
				}else if(map[x][y+2]=='3'){		//箱子前面是目的地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x][y+1]='6';
						map[x][y+2]='5';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x][y+1]='6';
						map[x][y+2]='5';
					}
				}
			}else if(map[x][y+1]=='5'){		//人前面是箱子在目的地 
				if(map[x][y+2]=='2'){		//箱子前面是空地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x][y+1]='7';
						map[x][y+2]='4';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x][y+1]='7';
						map[x][y+2]='4';
					}
				}else if(map[x][y+2]=='3'){		//箱子前面是目的地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x][y+1]='7';
						map[x][y+2]='5';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x][y+1]='7';
						map[x][y+2]='5';
					}
				}
			}	
		break;
		
		case 's':
		case 'S':
		case 40:
			if(map[x+1][y]=='2'){			//人前面是空地 
				if(map[x][y]=='6'){//人当前所处的是空地 
					map[x][y]='2';
					map[x+1][y]='6'; 
				}else if(map[x][y]=='7'){//人当前所处的是目的地 
					map[x][y]='3';
					map[x+1][y]='6'; 
				}	
			}else if(map[x+1][y]=='3'){		// 人前面是目的地 
				if(map[x][y]=='6'){//人当前所处的是空地 
					map[x][y]='2';
					map[x+1][y]='7'; 
				}else if(map[x][y]=='7'){//人当前所处的是目的地 
					map[x][y]='3';
					map[x+1][y]='7'; 
				}
			}else if(map[x+1][y]=='4'){		//人前面是箱子 
				if(map[x+2][y]=='2'){		//箱子前面是空地 
					if(map[x][y]=='6'){//人当前所处的是空地 
					
						map[x][y]='2';
						map[x+1][y]='6';
						map[x+2][y]='4';
						 
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x+1][y]='6';
						map[x+2][y]='4';
					}
				}else if(map[x+2][y]=='3'){		//箱子前面是目的地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x+1][y]='6';
						map[x+2][y]='5';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x+1][y]='6';
						map[x+2][y]='5';
					}
				}
			}else if(map[x+1][y]=='5'){		//人前面是箱子在目的地 
				if(map[x+2][y]=='2'){		//箱子前面是空地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x+1][y]='7';
						map[x+2][y]='4';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x+1][y]='7';
						map[x+2][y]='4';
					}
				}else if(map[x+2][y]=='3'){		//箱子前面是目的地 
					if(map[x][y]=='6'){//人当前所处的是空地 
						
						map[x][y]='2';
						map[x+1][y]='7';
						map[x+2][y]='5';
						
					}else if(map[x][y]=='7'){//人当前所处的是目的地 
						
						map[x][y]='3';
						map[x+1][y]='7';
						map[x+2][y]='5';
					}
				}
			}
		break;
		case 'e': 
		case 'E':
			*end=1;		//代表结束游戏； 
		break;	
	}
	
} 

void get_person(int *x,int *y,char map[14][16]){
	int i, j;
	
	
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 16; j++){
			if(map[i][j]=='6'||map[i][j]=='7'){
				*x=i;
				*y=j;
			}
		}
	}
}

int countbox(char map[14][16]){
	int i, j;
	char t;
	int cnt_box=0;
	
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 16; j++){
			if(map[i][j]=='4'){
				cnt_box++;
			}
		}
	}
	
	return cnt_box;	
}


 


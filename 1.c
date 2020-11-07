#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
#define MAX_USER 50 //最大用户数

//把要储存的信息定义为结构体
typedef struct _USERINFO
{
 char szName[100]; //名字
}USER, *PUSER;

char szFileName[] = {"user_information.dat"};
PUSER user[MAX_USER]; //存储用户信息的指针数组
int user_num; //用户数量

void get_info()
{
 if(user_num == 0)
 {
 return;
 }
 user_num = 0;
 FILE *fp;
 fp = fopen(szFileName, "rb");
 while(!feof(fp))
 {
 user[user_num] = (PUSER)malloc(sizeof(USER));
 fread(user[user_num], sizeof(USER), 1, fp);
 user_num++;
 }
 fclose(fp);
}

void show_info(char *szName)
{
 int i;
 for(i=0; i<user_num && strcmp(user[i]->szName, szName); i++)
 ;
 if(i == user_num)
 {
 printf("\n\n未找到该用户信息!");
 }
 else
 {
 printf("\n\n姓名: %s", user[i]->szName);
 }
}

void insert_info( )
{
 USER user;
 printf("\n\n请输入您的姓名：\n\n");
 scanf("%s", user.szName);
 FILE *fp = fopen(szFileName, "a+");
 fwrite(&user, sizeof(USER), 1, fp);
 fclose(fp);
 printf("\n\n信息已存储到文件 %s", szFileName);
}

//初始化
void init()
{
 FILE *fp;
 fp = fopen(szFileName, "rb");
 if(!fp)
 {
 user_num = 0;
 }
 else
 {
 user_num = -1;
 fclose(fp);
 }

}

void release()
{
 int i;
 for(i=0; i<user_num; i++)
 {
 free(user[i]);
 }
}

void menu()
{
 system("cls");
 printf("\n\n\n");
 printf("\t\t1. 查询信息\n\n");
 printf("\t\t3. 退出\n\n");
}

int main()
{
 char cmd = '0';
 char szName[20];
 while(cmd != '3')
 {
 menu();
 cmd = getch();
 switch(cmd)
 {
 case '1':
 printf("\n\n请输入要查询的姓名; ");
 scanf("%s", szName);
 init();
 get_info();
 show_info(szName);
 break;
 case '2':
 insert_info();
 break;
 case '3':
 break;
 
 }
 printf("\n\n按任意键继续... ");
 getch();
 }
 return 0;
}

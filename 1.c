#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
#define MAX_USER 50 //����û���

//��Ҫ�������Ϣ����Ϊ�ṹ��
typedef struct _USERINFO
{
 char szName[100]; //����
}USER, *PUSER;

char szFileName[] = {"user_information.dat"};
PUSER user[MAX_USER]; //�洢�û���Ϣ��ָ������
int user_num; //�û�����

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
 printf("\n\nδ�ҵ����û���Ϣ!");
 }
 else
 {
 printf("\n\n����: %s", user[i]->szName);
 }
}

void insert_info( )
{
 USER user;
 printf("\n\n����������������\n\n");
 scanf("%s", user.szName);
 FILE *fp = fopen(szFileName, "a+");
 fwrite(&user, sizeof(USER), 1, fp);
 fclose(fp);
 printf("\n\n��Ϣ�Ѵ洢���ļ� %s", szFileName);
}

//��ʼ��
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
 printf("\t\t1. ��ѯ��Ϣ\n\n");
 printf("\t\t3. �˳�\n\n");
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
 printf("\n\n������Ҫ��ѯ������; ");
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
 printf("\n\n�����������... ");
 getch();
 }
 return 0;
}

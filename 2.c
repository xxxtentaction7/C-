#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "mainmenu.c"

int main()
{ 	extern int result[10];
	int i=0,n,N;
	int flag=0;	     
    char szTest[1000] = {0};
    int userRes[500];
    FILE *mp = fopen("hphx.txt", "r");
	FILE *lp = fopen("result.txt", "w");    
    if(NULL == mp||NULL==lp)     
    {          
        printf("failed to open dos.txt\n");          
        return 1;         
    }    
    while(!feof(mp))  
    {                            
        memset(szTest,0, sizeof(szTest)); 
		fgets(szTest,sizeof(szTest) - 1, mp); // 包含了换行符
		printf("错题：%s",szTest);
		printf("请输入您的答案：");     
		scanf("%d",&userRes[i]);       
        if(result[i]==userRes[i])
        {
    	printf("恭喜您答对了，真棒！"); 
    	
        }
        else
        {
    	printf("很遗憾您答错了，继续努力哦！\n"); 
    	
    }
    fclose(mp);
    fclose(lp);
    
    remove("hphx.txt");
  	rename("result.txt","hphx.txt");
    printf("\n");        
    return 0;
}
}


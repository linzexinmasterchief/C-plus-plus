#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
int main()
{
    int a[20][20]={{0},{0}};   
    int i,j;
	int m=0;
	int bird=8;                         //鸟
	int yc;                          //烟囱      
	for(i=0;i<20;i++){          //上下边框
	    a[0][i]=1;
		a[19][i]=2;
	}
	printf("  flappy bird\n");
	printf("           ----c语言版\n");
	printf("游戏说明:1-按上箭头使鸟起飞\n");
	printf("         2-等级越高，难度越大！\n");
	printf("         3-按任意键开始游戏。\n");
	printf("备注:初学c新人无聊练手渣渣作品。大神轻喷。\n");
	getch();
    while(1){
		a[bird][4]=0;
		while(!kbhit()){                          //鸟自动向下
			bird=bird+2;
			goto mark;
		}
		while(kbhit()){                        //控制鸟向上
			switch(_getch()){
			case 72:bird=bird-1;break;
			}				
		}
mark:
		fflush(stdin);                                //清除键盘缓冲区
		if(m%14==0){                                   //画烟囱
			srand((unsigned)time(NULL));          //随机烟囱位置
			yc=rand()%10+5;
            for(i=1;i<yc-1;i++)                //确定烟囱
			    a[i][18]=3;
			a[i-1][19]=3;
			a[i-1][17]=3;
			a[i+3][19]=3;
			a[i+3][17]=3;
			for(i=yc+2;i<19;i++)
				a[i][18]=3;
		}
		m++;
		if(m%2==0){									//移动烟囱
			for(i=0;i<20;i++)                   
				for(j=0;j<20;j++){
					if(a[i][j]==3){
						a[i][j]=0;
						a[i][j-1]=3;
					}
					if(a[i][-1]==3)                 //清除烟囱
						a[i][-1]=0;
				}
		}
		if(a[bird][4]==1||a[bird][4]==2||a[bird][4]==3){              //判断是否撞上边界或烟囱,代码比较亢余
			a[bird][4]=4;
            system("cls");
			for(i=0;i<20;i++){
			for(j=0;j<20;j++){
			    if(a[i][j]==1)                //上边界
					printf("═");
                else if(a[i][j]==2)                //上边界
					printf("┳");
                else if(a[i][j]==3)                 //烟囱
					printf("■");
				else if(a[i][j]==4)                 //鸟
					printf("Ю");
				else
					printf("  ");                    //空白
			}
			printf("\n");
		}
		    break;
		}
		else
			a[bird][4]=4;
		system("cls");
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
			    if(a[i][j]==1)                //上边界
					printf("═");
                else if(a[i][j]==2)                //上边界
					printf("┳");
                else if(a[i][j]==3)                 //烟囱
					printf("■");
				else if(a[i][j]==4)                 //鸟
					printf("Ю");
				else
					printf("  ");                    //空白
			}
			printf("\n");
		}
	Sleep(500-m/2);
	}
	printf("嘛~此次得分为%d\n",(m-18)/14);
    return 0;
}
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
int main()
{
    int a[20][20]={{0},{0}};   
    int i,j;
	int m=0;
	int bird=8;                         //��
	int yc;                          //�̴�      
	for(i=0;i<20;i++){          //���±߿�
	    a[0][i]=1;
		a[19][i]=2;
	}
	printf("  flappy bird\n");
	printf("           ----c���԰�\n");
	printf("��Ϸ˵��:1-���ϼ�ͷʹ�����\n");
	printf("         2-�ȼ�Խ�ߣ��Ѷ�Խ��\n");
	printf("         3-���������ʼ��Ϸ��\n");
	printf("��ע:��ѧc������������������Ʒ���������硣\n");
	getch();
    while(1){
		a[bird][4]=0;
		while(!kbhit()){                          //���Զ�����
			bird=bird+2;
			goto mark;
		}
		while(kbhit()){                        //����������
			switch(_getch()){
			case 72:bird=bird-1;break;
			}				
		}
mark:
		fflush(stdin);                                //������̻�����
		if(m%14==0){                                   //���̴�
			srand((unsigned)time(NULL));          //����̴�λ��
			yc=rand()%10+5;
            for(i=1;i<yc-1;i++)                //ȷ���̴�
			    a[i][18]=3;
			a[i-1][19]=3;
			a[i-1][17]=3;
			a[i+3][19]=3;
			a[i+3][17]=3;
			for(i=yc+2;i<19;i++)
				a[i][18]=3;
		}
		m++;
		if(m%2==0){									//�ƶ��̴�
			for(i=0;i<20;i++)                   
				for(j=0;j<20;j++){
					if(a[i][j]==3){
						a[i][j]=0;
						a[i][j-1]=3;
					}
					if(a[i][-1]==3)                 //����̴�
						a[i][-1]=0;
				}
		}
		if(a[bird][4]==1||a[bird][4]==2||a[bird][4]==3){              //�ж��Ƿ�ײ�ϱ߽���̴�,����ȽϿ���
			a[bird][4]=4;
            system("cls");
			for(i=0;i<20;i++){
			for(j=0;j<20;j++){
			    if(a[i][j]==1)                //�ϱ߽�
					printf("�T");
                else if(a[i][j]==2)                //�ϱ߽�
					printf("��");
                else if(a[i][j]==3)                 //�̴�
					printf("��");
				else if(a[i][j]==4)                 //��
					printf("��");
				else
					printf("  ");                    //�հ�
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
			    if(a[i][j]==1)                //�ϱ߽�
					printf("�T");
                else if(a[i][j]==2)                //�ϱ߽�
					printf("��");
                else if(a[i][j]==3)                 //�̴�
					printf("��");
				else if(a[i][j]==4)                 //��
					printf("��");
				else
					printf("  ");                    //�հ�
			}
			printf("\n");
		}
	Sleep(500-m/2);
	}
	printf("��~�˴ε÷�Ϊ%d\n",(m-18)/14);
    return 0;
}
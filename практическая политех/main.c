//� ����������� ����� M x N ������ ��������:
//
//1) ��������� ������� ���������� �������� ������;
//
//2) ��������� ���� �������� ������, ������������ �� ���������� ��������.
//
//3) ������������ �� ���������� ��������, �� ����������� �� ������ ������, � �� ��������� ��������, �� ����������� �� �������� ������.
//
//�������� �������� � ������������� ������� ������� �� ���������� ���� ������ ��. ������� ����������� ���� ��� ��������� ���� � �� ����.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

//#define N 4 //������
//#define M 4 //�������
int N;
int M;
int i;
int j;

float *ar;
void generation();
void output();
float multiply();//�������� M � N ���������� �� �����, ��� ��� ��� ������� ��� ���������� ����������
float summ();
void change();
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int kod;
    while(1)
    {
    puts("���� 䳿");
    puts("1 - ������� ���� ������ �����");
    puts("2 - ��������� ����� ������");
    puts("3 - ���������� ������� ���������� ��-�� ������");
    puts("4 - ���������� ���� �������� ������,����������� �� ��������� ��������");
    puts("5 - ������������� �� ���������� ��������, �� ����������� �� ������ ������,\n� �� ��������� ��������, �� ����������� �� �������� ������");
    puts("0 - �����");

    puts("������ ��� ������ 䳿");
    scanf("%d", &kod);
    printf("������� ��� %d \n", kod);

 switch(kod)
 {
 case 1:generation();break;
 case 2:output();break;
 case 3:printf("%.1f\n",multiply());break;
 case 4:printf("%.1f\n",summ());break;
 case 5:change();break;
 case 0:exit(1);break;
 default: printf("�� ����� �������� ��, ���� �����, ��������!");
 }

 }
return EXIT_SUCCESS; // EXIT_SUCCESS - ���������, �� ������ ������ ��������� ��������}
}

void generation()
{
    printf("������ ���-�� ����� �� �����\n");
    scanf("%d",&N);
    scanf("%d",&M);
    int razm=N*M;
    ar = (float*)malloc(razm * sizeof(float));//��������� �� ������ �������
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        scanf("%f",&ar[i*M+j]);
        //������� ������ [] i*M+j ��������� �������� ������ � ������ �������� ������� ��� ��� � ������ �������� ������� ������������� ���������������
        //j ����� ������ i ����� ������
    }
}

void output()
{
    for(i=0;i<N;i++)
    {
        printf("\n");
        for(j=0;j<M;j++)
        printf("%.1f\t",ar[i*M+j]);
    }
    printf("\n\n");
}
float multiply()
{
    float mult =1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        if(ar[i*M+j]>0)
        mult*=ar[i*M+j];

    }
    printf("\n��������� �������: ");
    return mult;

}

float summ()
{
    float min=ar[0];
    float msumm=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        if(ar[i*M+j]<min)
        {
        min=ar[i*M+j];
        }
    }


        for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
        if(ar[i*M+j]!=min)
        {
        msumm+=ar[i*M+j];
        }
        else
        break;
        }
        if(ar[i*M+j]==min)
        break;
    }
    return msumm;

}
void change()
{
    int tmp;
    //int i1,j1;




    for(i=M-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        if(ar[i*M+j] < ar[i*M+j+1])
        {
                tmp=ar[i*M+j];
                ar[i*M+j] = ar[i*M+j+1];
                ar[i*M+j+1] = tmp;

        }

    }
//
//    for(int i1=0;i<N;i1++)
//    {
//
//        for (int k=M-1; k>=0; k--)
//    {
//           for (int l = 0; l < k; l++)
//        {
//
//            if ((i1+1)%2==0 && (ar[k*M+l] > ar[k*M+l+1]))
//            {
//                tmp =ar[k*M+l];
//                ar[k*M+l] = ar[k*M+l+1];
//                ar[k*M+l+1] = tmp;
//            }
//            else if ((i1+1)%2==1 && (ar[k*M+l] < ar[k*M+l+1]))
//            {
//                tmp =ar[k*M+l];
//                ar[k*M+l] = ar[k*M+l+1];
//                ar[k*M+l+1] = tmp;
//            }
//      }
//
//    }
//
//}
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>


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
    printf("������ �����\n");
    ar = (float*)malloc(razm * sizeof(float));//��������� �� ������ �������
    for(i=0;i<N;i++)
    {
        printf("\n");
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
void change()//������ ����������� ���������� �� ���������� ������� ��������,
//�� ��� ��� � ��� ���������� ��������� ������, �� �������� ���������� � ��������� ��������
{
 for(i=1,j=0;i<=N;i++,j=j+M)
   for(int a=j;a<i*M-1;a++)
       for(int b=i*M-1;b>a;b--)
        {
         if(ar[b-1]<ar[b]&&i%2==1)
         {
             int temp = ar[b-1];
             ar[b-1] = ar[b];
             ar[b] = temp;
         }
         if(ar[b-1]>ar[b]&&i%2==0)
         {
             int temp = ar[b-1];
             ar[b-1] = ar[b];
             ar[b] = temp;
         }
        }


  output();
}

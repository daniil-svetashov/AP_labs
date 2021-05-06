//В двовимірному масиві M x N дійсних елементів:
//
//1) Обчислити добуток позитивних елементів масиву;
//
//2) Обчислити суму елементів масиву, розташованих до мінімального елемента.
//
//3) Впорядкувати за зростанням елементи, що розташовано на парних рядках, і за спаданням елементи, що розташовано на непарних рядках.
//
//Завдання виконати з використанням власних функцій та реалізацією меню вибору дій. Приклад програмного коду для реалізації меню є на сайті.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

//#define N 4 //строки
//#define M 4 //столбцы
int N;
int M;
int i;
int j;

float *ar;
void generation();
void output();
float multiply();//значения M и N передавать не будем, так как они указаны как глобальные переменные
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
    puts("Вибір дії");
    puts("1 - Швидкий ввод списку рядків");
    puts("2 - Виведення рядків масиву");
    puts("3 - Обчислення добутку позитивних ел-тів масиву");
    puts("4 - Обчислення суми елементів масиву,розашованих до мінімалього елемента");
    puts("5 - Впорядкування за зростанням елементів, що розташовано на парних рядках,\nі за спаданням елементи, що розташовано на непарних рядках");
    puts("0 - Вихід");

    puts("Введіть код бажаної дії");
    scanf("%d", &kod);
    printf("Обраний код %d \n", kod);

 switch(kod)
 {
 case 1:generation();break;
 case 2:output();break;
 case 3:printf("%.1f\n",multiply());break;
 case 4:printf("%.1f\n",summ());break;
 case 5:change();break;
 case 0:exit(1);break;
 default: printf("Ви ввели неіснуючу дію, будь ласка, повторіть!");
 }

 }
return EXIT_SUCCESS; // EXIT_SUCCESS - константа, що означає успішне виконання програми}
}

void generation()
{
    printf("Введіть кол-во строк та рядків\n");
    scanf("%d",&N);
    scanf("%d",&M);
    int razm=N*M;
    ar = (float*)malloc(razm * sizeof(float));//указатель на начало массива
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        scanf("%f",&ar[i*M+j]);
        //формула внутри [] i*M+j позволяет получить доступ к любому элементу массива так как в памяти элементы массива распологаются последовательно
        //j номер столба i номер строки
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
    printf("\nРезультат добутку: ");
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

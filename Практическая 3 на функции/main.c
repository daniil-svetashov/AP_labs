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
float multiply();//значения M и N передавать не будем, так как они указаны как глобальные переменные
float summ();
void change();
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
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
    printf("Введіть рядки\n");
    ar = (float*)malloc(razm * sizeof(float));//указатель на начало массива
    for(i=0;i<N;i++)
    {
        printf("\n");
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
void change()//данная конструкция базируется на сортировке методом пузырька,
//но так как у нас фактически двумерный массив, то пришлось прибегнуть к некоторой хитрости
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

#include <windows.h>
SetConsoleCP(1251);
SetConsoleOutputCP(1251);









//Функция на создание файла и запись в него массива
void filecreate(double *ar,int N,FILE *fp)
{

    fp=fopen("result.txt","w");
    if(fp==NULL)
    {
        printf("Создать файл не получилось,ошибка");
        exit(1);
    }

    for(int i=0;i<N;i++)
    {
        fprintf(fp,"%.2f ",ar[i]);
    }
    fclose(fp);

}




//Функция заполнения массива случайными числами из дипазона  0 - 10

#include <time.h>
srand(time(NULL));
void generation(double *ar ,int N)
{
    const int y=0,x=10;
    for(int i=0;i<N;i++)
    {
     ar[i]=y+rand()%(x+1-y);
    }
}



//Функция сортировки по убыванию

void sort(double *ar,int N)
{
  for(int i=0;i<N-1;i++)
    for(int j=N-1;j>i;j--)
  {
      if(ar[j-1]<ar[j])//если текущий больше прошлого
      {
          int temp=ar[j-1];
          ar[j-1]=ar[j];
          ar[j]=temp;
      }
  }
}


//Функция вывода массива
void output(double *ar,int N)
{
    printf("\n");
    for(int i=0;i<N;i++)
    {
     printf("%.2f ",ar[i]);
    }
}





//задание 23 stud files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void generation(double *ar,int N);
void sort(double *ar,int N);//сортировка по убыванию
void output(double *ar,int N);//функция вывода массива
void fromtail(double *ar,int N);
void filecreate(double *ar,int N,FILE *fp);
FILE *fp;

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;

    printf("Введите натуральное число N: ");
    scanf("%d",&N);
    double ar[N];
//    double ar[10]={9,1,2,3,0,4,6,5,8,7};
    generation(ar,N);//передаем указатель на массив и кол-во элементов
    printf("Созданный массив");
    output(ar,N);
    sort(ar,N);
    printf("\nПромежутоный результат:");
    output(ar,N);
    fromtail(ar,N);
    printf("\nРезультат роботы программы");
    output(ar,N);
    filecreate(ar,N,fp);

    return 0;
}



//генерация чисел из диапазона [0;10]
void generation(double *ar ,int N)
{
    const int y=0,x=10;
    for(int i=0;i<N;i++)
    {
     ar[i]=y+rand()%(x+1-y);
    }
}


//сортировка по убывнаию
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

//функция вывода массива
void output(double *ar,int N)
{
    printf("\n");
    for(int i=0;i<N;i++)
    {
     printf("%.2f ",ar[i]);
    }
}

void fromtail(double *ar,int N)
{

    double ar2[N];
    for(int i=0;i<N;i++)
    {
    ar2[i]=ar[i];
    }

    int count=0;
    for(int a=0,i=0,j=N-1;a<N;a++)
    {
        if(count==0)
        {
            ar[i]=ar2[a];
            i++;
            ++count;
        }
        else
        {
            ar[j]=ar2[a];
            --j;
            --count;
        }
    }
}

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

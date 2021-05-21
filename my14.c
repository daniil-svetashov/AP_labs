#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct tovar
{
    char name[20];
    float price;
    int tmax;//найбільша температура температур
    int tmin;//найменша температура температур
    int amount;//кол-во измеряемых велечин;
}t1;

struct value
{
char valuename[20];
int valuetop;//верхня границя величини
int valuedown;//нижня границя величини
float pogr;
}t2;

// прототипи функцій
void input(FILE *);
void output (FILE *);
void add (FILE *);
void search(FILE *);
void answer(FILE *);

FILE *fp;
FILE *fp2;


int main()
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);

char c;
while(1)
{
puts("\n1 - Новий файл");
puts("2 - Перегляд файлу");
puts("3 - Додати до файлу прилад");
puts("4 - Пошук (вибірка)");
puts("5 - Відповідь");
puts("0 - Exit");

c = getch();

  switch (c)
  {
case '1':input(fp);break;
case '2':output(fp);break;
case '3':add(fp);break;
case '4':search(fp);break;
case '5':answer(fp2);break;
case '0': return 0;break;
default: puts("Будь ласка виберіть одну з дій");
   }
 }
}

void input (FILE *fp)// ввод значень в файл
{
    fp=fopen("1.dat","wb");
    char c;
    do
    {
      printf("\nНазва приладу:");
      scanf("%s",t1.name);

      printf("\nВартість приладу:");
      scanf("%f",&t1.price);

      printf("\nВерхній діапазон температури:");
      scanf("%d",&t1.tmax);
      printf("\nНижній діапазон температури:");
      scanf("%d",&t1.tmin);

      printf("\nВведіть кол-во велечин що вимірює прилад:");
      scanf("%d",&t1.amount);
      fwrite(&t1,sizeof(t1),1,fp);
      for(int i=0;i<t1.amount;i++)
      {
          printf("\nНазва величини:");
          scanf("%s",t2.valuename);
          printf("\nВерхня границя:");
          scanf("%d",&t2.valuetop);
          printf("\nНижня границя:");
          scanf("%d",&t2.valuedown);
          printf("\nПохибка:");
          scanf("%f",&t2.pogr);
          fwrite(&t2,sizeof(t2),1,fp);
      }

      printf("Продовжити? y/n:");
      c=getch();
    }while(c=='y');
    fclose(fp);
  }

  void output (FILE *fp)
  {
      fp=fopen("1.dat","rb");
      for(int i=0;i<100;i++)
      printf("*");
      fread(&t1,sizeof(t1),1,fp);
      while(!feof(fp))
      {
      printf("\nПристрій:%s Ціна:%.2f Верхній діапазон t:%d Ніжній:%d Кількість вимірюємих велечин:%d\n",t1.name,t1.price,t1.tmax,t1.tmin,t1.amount);

      for(int i=0;i<t1.amount;i++)
      {
          fread(&t2,sizeof(t2),1,fp);
          printf("\nВеличина,що вимірюється:%s",t2.valuename);
          printf("\nВерхня границя:%d",t2.valuetop);
          printf("\nНижня границя:%d",t2.valuedown);
          printf("\nПохибка:%.2f\n",t2.pogr);

      }
      fread(&t1,sizeof(t1),1,fp);
      for(int i=0;i<100;i++)
      printf("*");
      }
      fclose(fp);

  }

 void add(FILE *fp)
 {

     char c;
     int count;
     fp=fopen("1.dat","ab");
     do
    {
      printf("\nНазва прибору:");
      scanf("%s",t1.name);

      printf("\nВартість прибору:");
      scanf("%f",&t1.price);

      printf("\nВерхній діапазон температури:");
      scanf("%d",&t1.tmax);
      printf("\nНижній діапазон температури:");
      scanf("%d",&t1.tmin);

      printf("\nВведіть кол-во велечин що вимірює пристрій:");
      scanf("%d",&t1.amount);
      count=t1.amount;
      fwrite(&t1,sizeof(t1),1,fp);
      for(int i=0;i<count;i++)
      {
          printf("\nНазва величини:");
          scanf("%s",t2.valuename);
          printf("\nВерхня границя:");
          scanf("%d",&t2.valuetop);
          printf("\nНижня границя:1000");
          scanf("%d",&t2.valuedown);
          printf("\nПохибка");
          scanf("%f",&t2.pogr);
          fwrite(&t2,sizeof(t2),1,fp);
      }
      printf("Продовжити? y/n:");
      c=getch();
    }while(c=='y');
    fclose(fp);
  }



  void search(FILE *fp)
  {

      char uservalue[20];
      int usertop;
      int userdown;
      float userpogr;
      printf("\nВведіть назву величини, що потрбібно виміряти:");
      scanf("%s",uservalue);
      printf("\nВведіть верхню границю:");
      scanf("%d",&usertop);
      printf("\nВведіть нижню границю:");
      scanf("%d",&userdown);
      printf("\nВведіть похибку");
      scanf("%f",&userpogr);


      fp=fopen("1.dat","rb");
      fp2=fopen("2.dat","wb");

       fread(&t1,sizeof(t1),1,fp);
       while(!feof(fp))
      {

      for(int i=0;i<t1.amount;i++)
      {
          fread(&t2,sizeof(t2),1,fp);
          if(!strcmp(uservalue,t2.valuename)&&usertop>userdown&&usertop<=t2.valuetop&&userdown>=t2.valuedown&&userpogr<=t2.pogr)
             {
              fwrite(&t1.name,sizeof(t1.name),1,fp2);
             }
        }
        fread(&t1,sizeof(t1),1,fp);
     }
  fclose(fp);
  fclose(fp2);
  }

  void answer(FILE *fp2)
  {
      fp2=fopen("2.dat","rb");
      fread(&t1.name,sizeof(t1.name),1,fp2);
      printf("\nВам подходит:\n");
      while(!feof(fp2))
      {
          printf("%s\n",t1.name);
          fread(&t1.name,sizeof(t1.name),1,fp2);
      }
      fclose(fp2);
  }

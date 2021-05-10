#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void input(FILE *f1);//ввод содержимого первого файла
void comas(FILE *f1,FILE *f2);//замена запятый на пробелы и ввод во второй файл
void output(FILE *f2);//вывод 2го файла
void numbers(FILE *f1,FILE *f2);
char ch;
FILE *f1,*f2;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    input(f1);
    comas(f1,f2);
    printf("Текст во втором файле с запятыми вместо пробелов:\n");
    output(f2);
    numbers(f1,f2);
    puts("\n\nТекст во втором файле с добавленым текстом без цифр первого файла:");
    output(f2);

    return 0;
}


void input(FILE *f1)
{
    char text[150];
    int kod;
    puts("Пожалуйста сделайте выбор:");
    puts("0 - Воспользоваться шаблоном текста, удовлетворяющим условию задания");
    puts("1 - Ввести свой текст по желанию");

    do
    {
        scanf("%d",&kod);
        switch(kod)
      {
        case 0: strcpy(text,"some sort ::: of text,with 2 comas,and 3 question marks???");break;
        case 1: puts("Введите ваш текст:");while(getchar() != '\n');gets(text);break;
        default:printf("Вы ввели число, которое не принадлежит списку предложенных:");
                printf("\nПовторите ввод\n");
      }
    }
    while(kod!=0&&kod!=1);


      if((f1=fopen("1.txt","w"))==NULL)
      {
          printf("Открыть файл 1.txt для записи не получилось, ошибка!");
          exit(EXIT_FAILURE);
      }

      fputs(text,f1);
      fclose(f1);
}


void comas(FILE *f1,FILE *f2)
{
     if((f1=fopen("1.txt","r"))==NULL)
         {
          printf("Открыть файл 1.txt для чтения не получилось, ошибка!");
          exit(EXIT_FAILURE);
         }
     if((f2=fopen("2.txt","w"))==NULL)
         {
          printf("Открыть файл 2.txt для записи не получилось, ошибка!");
          exit(EXIT_FAILURE);
         }

      while((ch=fgetc(f1))!=EOF)
      {
        if(ch==' ')
        {
         ch=',';
         putc(ch,f2);
        }
         else
         putc(ch,f2);
      }
      fclose(f1);
      fclose(f2);
      rewind(f1);
}


void output(FILE *f2)
{
    if((f2=fopen("2.txt","r"))==NULL)
      {
          printf("Открыть файл 2.txt для чтения не получилось, ошибка!");
          exit(EXIT_FAILURE);
      }

      while((ch=fgetc(f2))!=EOF)
      {
          putchar(ch);
      }
      fclose(f2);
      rewind(f2);
}
void numbers(FILE *f1,FILE *f2)
{
    if((f1=fopen("1.txt","r"))==NULL)
         {
          printf("Открыть файл 1.txt для чтения не получилось, ошибка!");
          exit(EXIT_FAILURE);
         }

    if((f2=fopen("2.txt","a"))==NULL)//открываем для записи символов отличных от цифр в конец файла
         {
          printf("Открыть файл 2.txt для добавления текста в конец не получилось, ошибка!");
          exit(EXIT_FAILURE);
         }
        while((ch=fgetc(f1))!=EOF)
      {
        if(ch<=47 || ch>=58)
        {
         putc(ch,f2);
        }
      }
      fclose(f1);
      fclose(f2);
      rewind(f1);
}

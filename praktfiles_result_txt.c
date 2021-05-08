#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL,"rus");
    FILE *f1,*f2;

    char text[100];
    char ch;
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
          return 1;
      }



      fputs(text,f1);
      fclose(f1);

      if((f2=fopen("2.txt","w"))==NULL)
         {
          printf("Открыть файл 2.txt для записи не получилось, ошибка!");
          return 2;
         }
     if((f1=fopen("1.txt","r"))==NULL)
         {
          printf("Открыть файл 1.txt для чтения не получилось, ошибка!");
          return 3;
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

      if((f2=fopen("2.txt","r"))==NULL)
      {
          printf("Открыть файл 1.txt для чтения не получилось, ошибка!");
          return 4;
      }

      while((ch=fgetc(f2))!=EOF)
      {
          putchar(ch);
      }
      fclose(f2);
      rewind(f2);

     //Дописываем  символы отлоичыне от цифр



     if((f2=fopen("2.txt","a"))==NULL)//открываем для записи символов отличных от цифр
         {
          printf("Открыть файл 2.txt для записи не получилось, ошибка!");
          return 2;
         }

     if((f1=fopen("1.txt","r"))==NULL)
         {
          printf("Открыть файл 1.txt для чтения не получилось, ошибка!");
          return 3;
         }

      while((ch=fgetc(f1))!=EOF)
      {
        if(ch>47&&ch<58)
        {

        }
         else
         putc(ch,f2);
      }

      while((ch=fgetc(f2))!=EOF)
      {
          putchar(ch);
      }
      fclose(f1);
      fclose(f2);


    return 0;
}

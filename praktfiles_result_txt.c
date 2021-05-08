#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *f1,*f2;

    char text[150],ch;
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


     if((f1=fopen("1.txt","r"))==NULL)
         {
          printf("Открыть файл 1.txt для чтения не получилось, ошибка!");
          return 1;
         }
     if((f2=fopen("2.txt","w"))==NULL)
         {
          printf("Открыть файл 2.txt для записи не получилось, ошибка!");
          return 2;
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
      fclose(f2);//закрываем, чтобы открыть для чтения,f1 оставляем открытым.
      rewind(f1);

      if((f2=fopen("2.txt","r"))==NULL)
      {
          printf("Открыть файл 2.txt для чтения не получилось, ошибка!");
          return 2;
      }

      //Вывод второго файла на экран.
      puts("Текст во втором файле с запятыми вместо пробелов");
      while((ch=fgetc(f2))!=EOF)
      {
          putchar(ch);
      }
      fclose(f2);
      rewind(f2);



     /////////////////////////////////////////////////////
     //Дописываем  символы во второй файл,отличные от цифр

     if((f2=fopen("2.txt","a"))==NULL)//открываем для записи символов отличных от цифр в конец файла
         {
          printf("Открыть файл 2.txt для добавления текста в конец не получилось, ошибка!");
          return 2;
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


       printf("\n\n\n");
       if((f2=fopen("2.txt","r"))==NULL)//открываем для записи символов отличных от цифр
         {
          printf("Открыть файл 2.txt для записи не получилось, ошибка!");
          return 2;
         }

      puts("Текст во втором файле с добавленым текстом без цифр первого файла:");
      while((ch=fgetc(f2))!=EOF)
      {
          putchar(ch);
      }
      fclose(f2);
      rewind(f2);


    return 0;
}

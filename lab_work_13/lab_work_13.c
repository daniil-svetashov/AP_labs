//В С записати всі прописні літери латинського алфавіту з А.
//Доповнити А цифрами з В.
//Використовувати тип даних char


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main ()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *fA,*fB,*fC;
    char ch,text[100];
    puts("Введіть дані для файлу A.txt");
    gets(text);
    fA=fopen("A.txt","w");
    fprintf(fA,"%s",text);
    fclose(fA);

    puts("Введіть дані для файлу B.txt");
    gets(text);
    fB=fopen("B.txt","w");
    fprintf(fB,"%s",text);
    fclose(fB);





///////////////////////////////////////////////////////////////////////
//В С записати всі прописні літери латинського алфавіту з А.
     if((fC=fopen("C.txt","w"))==NULL)
      {
          printf("Создать файл C.txt для ЗАПИСИ не получилось, ошибка!");
          return 3;
      }
     if((fA=fopen("A.txt","r"))==NULL)
      {
          printf("Открыть файл А.txt для ЧТЕНИЯ не получилось, ошибка!");
          return 1;
      }


      while((ch=fgetc(fA))!=EOF)
      {
        if(ch>64 && ch<91)
        {
         putc(ch,fC);
        }
      }
      fclose(fA);
      rewind(fA);
      fclose(fC);
///////////////////////////////////////////////////////////////////////
//Доповнити А цифрами з В.
     if((fA=fopen("A.txt","a"))==NULL)
      {
          printf("Открыть файл A.txt для ДОПОЛНЕНИЯ В КОНЕЦ не получилось, ошибка!");
          return 1;
      }

       if((fB=fopen("B.txt","r"))==NULL)
      {
          printf("Открыть файл B.txt для ДОПОЛНЕНИЯ В КОНЕЦ не получилось, ошибка!");
          return 2;
      }

      while((ch=fgetc(fB))!=EOF)
      {
        if(ch>47 && ch<58)
        {
         putc(ch,fA);
        }
      }
      fclose(fB);
      fclose(fA);
      rewind(fB);

    /////////////////////////////////////////////////////////////////////
    //Для удобства решил добавить вывод текста из файлов на экран

      printf("Text in file A: ");
      fA=fopen("A.txt","r");
      while((ch=fgetc(fA))!=EOF)
      {
          putchar(ch);
      }

       printf("\nText in file B: ");
      fB=fopen("B.txt","r");
      while((ch=fgetc(fB))!=EOF)
      {
          putchar(ch);
      }

      printf("\nText in file C: ");
      fC=fopen("C.txt","r");
      while((ch=fgetc(fC))!=EOF)
      {
          putchar(ch);
      }

      exit(EXIT_SUCCESS);// функция exit как альтернатива fcloseall().

}

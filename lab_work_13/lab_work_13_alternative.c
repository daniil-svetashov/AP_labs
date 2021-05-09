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
    char text[100];
    //char ch;
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


      fgets(text,99,fA);
      for(int i=0;text[i]!='\0';i++)
      {
          if(text[i]>64 && text[i]<91)
        {
         putc(text[i],fC);
        }
      }
      fclose(fA);
      fclose(fC);


//      while((ch=fgetc(fA))!=EOF)
//      {
//        if(ch>64 && ch<91)
//        {
//         putc(ch,fC);
//        }
//      }
//      fclose(fA);
//      rewind(fA);
//      fclose(fC);
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

        fgets(text,99,fB);
         for(int i=0;text[i]!='\0';i++)
      {
          if(text[i]>47 && text[i]<58)
        {
         putc(text[i],fA);
        }
      }
        fclose(fB);
        fclose(fA);
//      while((ch=fgetc(fB))!=EOF)
//      {
//        if(ch>47 && ch<58)
//        {
//         putc(ch,fA);
//        }
//      }
//      fclose(fB);
//      fclose(fA);
//      rewind(fB);

    /////////////////////////////////////////////////////////////////////
    //Для удобства решил добавить вывод текста из файлов на экран

      printf("Text in file A: ");
      fA=fopen("A.txt","r");
      fgets(text,99,fA);
      puts(text);
//      while((ch=fgetc(fA))!=EOF)
//      {
//          putchar(ch);
//      }

       printf("\nText in file B: ");
      fB=fopen("B.txt","r");
      fgets(text,99,fB);
      puts(text);
//      while((ch=fgetc(fB))!=EOF)
//      {
//          putchar(ch);
//      }

      printf("\nText in file C: ");
      fC=fopen("C.txt","r");
      fgets(text,99,fC);
      puts(text);
//      while((ch=fgetc(fC))!=EOF)
//      {
//          putchar(ch);
//      }

      exit(EXIT_SUCCESS);// функция exit как альтернатива fcloseall().

}

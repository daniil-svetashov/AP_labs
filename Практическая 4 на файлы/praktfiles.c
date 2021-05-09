//#include <stdio.h>
//#include <conio.h>
//#include <string.h>
//
//
//int main()
//{
// FILE *f;
// char name[20];
// int year;
// float price;
// int i,n;
// if((f=fopen("first.txt","w"))==NULL)
// {
//     printf("\n There is a mistake");
//     return 1;
// }
// printf("Tovar");
// scanf("%d",&n);
//
// for(i=1;i<=n;i++)
// {
//     printf("\n Nazva");
//     scanf("%s",name);
//     printf("\n Year");
//     scanf("%d",&year);
//     printf("\n Price");
//     scanf("%f",&price);
//     fprintf(f,"\n%20s %4d %9.2lf",name,year,price);
// }
// fclose(f);
// return(0);
//
// }



//Вывести все данные про товары выпущенные после 2001го года

#include <stdio.h>
int main()
{
    FILE *d;
    char name[20];
    int year;
    float price;

    if((d=fopen("first.txt","r"))==NULL)
 {
     printf("\n There is a mistake");
     return 1;
 }

    while((fgetchar()!=EOF)&&(fscanf(d,"%s %d %f",name,&year,&price)))
          if(year>2001)
            printf("\n%s %d %f",name,year,price);

 fclose(d);
 return 0;
}

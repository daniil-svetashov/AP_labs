//Створити бінарний файл та внести в нього наступні дані:
//назва видання, газети або журналу, вартість одного примірника, кількість примірників на рік.
//Вивести всю вихідну інформацію. Вивести на друк інформацію про найдешевше видання.
//Завдання виконати з використанням власних функцій.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>//used to work with strings
#include <conio.h> //used for getch()
#include <windows.h>

struct tov
{
    char name[15];
    float cost;
    int kol;
}t1;

char c;//для перехоплювання натисненої клавіши
// прототипи функцій
//int counter;
void input(FILE *);//функція створення файлу
void print(FILE *);//функція перегляду файлу
void find(FILE *);//функція пошуку
FILE *tf;
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    while(1)
    {
         system("cls");
        puts("1 - новий файл");
        puts("2 - перегляд файлу");
        puts("3 - знайти найдешевше видання");
        puts("0 - вихід");
        c=getch();

        switch(c)
        {
        case '1':input(tf);break;
        case '2':print(tf);break;
        case '3':find(tf);break;
        case '0':return 0;
        default : puts("Невірний режим");
        }
    }
    return 0;
}


void input(FILE *tf)
{

    //counter=1;
    tf=fopen("file1.dat","wb");
    system("cls");
    printf("\nВведення інформації про різні видання:\n");
    do
    {
    printf("\nназва видання:");
    scanf("%s",t1.name);
    printf("\nціна:");
    scanf("%f",&t1.cost);
    printf("\nкількість:");
    scanf("%d",&t1.kol);
    fwrite(&t1,sizeof(t1),1,tf);
    //&t1 - адрес структури,  sizeof(t1) - розмір структури в байтах ,1 -кількість структур,tf покажчик на відкритий файл
    printf("\n Закінчити? y/n \n");
    c=getch();
    }while(c!='y');
    fclose(tf);//закриваєм файл file1.dat
}

void print(FILE *tf)
{
    tf=fopen("file1.dat","rb");
    system("cls");
    int i=1;//лічильник для зручного виводу

    //не використовуєм do while бо може трапитись, що юзер не ввів дані в файл,виводити буде нічого
//    if(counter==0)
//    {
//        return 1;
//    }
    fread(&t1,sizeof(t1),1,tf);

    while(!feof(tf))
    {
    printf("\n %d) Товар: %15s \t Ціна: %6.2f \t Кількість: %d ",i,t1.name,t1.cost,t1.kol);
    fread(&t1,sizeof(t1),1,tf); //заготовка на наступну ітерацію
    //feof(tf) пересуває покажчик tf
    i++;
    }
    fclose(tf);
    getch();//пауза
  //  return 0;
}

void find(FILE* tf)
{
 tf=fopen("file1.dat","rb");
 printf("\nІнформація про найдешевше видання\n");

 fread(&t1,sizeof(t1),1,tf);
 float min=t1.cost;
 long nb=ftell(tf);
 while(!feof(tf))
 {
  fread(&t1,sizeof(t1),1,tf);
  if(t1.cost<min)
  {
      min=t1.cost;
      nb=ftell(tf);
  }
 }
  fseek(tf,nb,SEEK_SET);
  fread(&t1,sizeof(t1),1,tf);
  printf("Товар: %15s \t Ціна: %6.2f \t Кількість: %d ",t1.name,t1.cost,t1.kol);
  fclose(tf);
  getch();
}



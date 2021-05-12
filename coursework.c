#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


struct music
{
    char disk[30];
    int year;
    int lenght;
    char name[30];
    struct music *prev;//предыдущая структура
    struct muisc *next;//следущая структура
};

//для того, чтобы при обьявлении или инициализации не приходилось писать struct music, а просто music.
typedef struct music music;


//обьявляем прототипы функций, которые фигурируют в программе, и которые будут фигурировать в программе.
void create();//создание   (1)
void del();//удаление (2)
//void change();//изменение информации про альбом (3)
void out(music *);//вывод всей информации (4)
//void outyear(music *);//Виведення всієї інформації про альбоми, рік випуску яких пізніше ніж введений (5)
//void sort(music *);//Сортування по року випуску(6)
//void longest(music *);//Поиск самого длинного по звучанию альбома(7)
//void searchau(music *);//Поиск всех альбомов заданного исполнителя(8)

struct music *head, *tail;//указатели на начало и хвост списка


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

 puts("Вибір дії");
 puts("1 - Введення інформації про альбом");
 puts("2 - Видалення інформації про альбом");
 puts("3 - Коригування інформації про альбом");
 puts("4 - Виведення всієї інформації");
 puts("5 - Виведення всієї інформації про альбоми, рік випуску яких пізніше ніж введений");
 puts("6 - Сортування по року випуску");
 puts("7 - Пошук найтривалішого за звучанням альбому");
 puts("8 - Виведення всіх альбомів, заданого виконавця");
 puts("0 - Вихід");

 // Вибір бажаної дії
 int kod;
 puts("Введіть код бажаної дії");
 scanf("%d", &kod);
 printf("Обраний код %d \n", kod);

 // Запуск функції згідно обраної дії
 switch(kod)
 {
 case 1: create(); break;
 case 2: del(); break;
 //case 3: change(); break;
 case 4: out(head); break;
 //case 5: outyear(); break;
 //case 6: sort(); break;
 //case 7: longest(); break;
 //case 8: searchau(MAX); break;
 case 0: exit(1);break;
 }

return EXIT_SUCCESS; // EXIT_SUCCESS - кон
}

//степ 1.4.5.8.10
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

usingnamespacestd;

structvalue{
charvalname[12];
intvalniz;
intvalverh;
floatpogr;
}t2;
structtov
{
charname [10];
intprice;
intgor;
intyear;
intvalamount;
intzakamount;
}t1;
structzak{
charfio[20];
charadres[20];
intkol;
}t3;
structzak *tab;
structvalue *list;

FILE *fa;
intinput(void) //цикл ввода значений в файл
{
intarr=0;
int i=0;
fa=fopen("E:\\Код\\Lab14\\A.dat", "wb+");
do {
printf("\n Названиеприбора: ");
cin>>t1.name;
printf(" Цена: ");
cin>>t1.price;
printf(" Гарантийныйсрок: ");
cin>>t1.gor;
printf("\n Введитекол-во велечинчтоизмеряет прибор: ");
cin>>t1.valamount;
printf("\n Введитекол-во заказчиков: ");
cin>>t1.zakamount;
fwrite(&t1, sizeof(t1), 1, fa);
for(int j=0;j<t1.valamount;j++) {
printf("\n Названиевелечины ");
cin>>list->valname;
printf("\n Верхнийизмерпорог ");
cin>>list->valverh;
printf("\n Нижнийизмерпорог ");
cin>>list->valniz;
printf("\n Погрешность ");
cin>>list->pogr;
fwrite(list, sizeof(structvalue) *1, 1, fa);
 }
for(int k=0;k<t1.zakamount;k++) {
printf("\n ФИО ");
cin>>tab->fio;
printf("\n Адрес ");
cin>>tab->adres;
printf("\n Кол-во приборов ");
cin>>tab->kol;
fwrite(tab, sizeof(structzak) *1, 1, fa);
 }
printf("\nЧтобыпродолжитьнажмите любую цифру кроме 1 ");
cin>>i;
arr++;
list = (structvalue *)realloc(list, arr * sizeof(structvalue));// надо для выделенияпамяти на новыйэлементcтруктурыvalue
tab = (structzak *)realloc(tab, arr * sizeof(structzak)); // надо для выделенияпамяти на новыйэлементcтруктурыzak
 }
while(i!=1);
fclose(fa);
returnarr;
 }
void out1(int d){ //функциявыводавсехвведеныхданных
fa = fopen("A.dat", "rb");
charch(151);
for(int i=0;i<36;i++){
cout<<" "<<ch<<" ";}
for(int i=0;i<d;i++){
fread( &t1, sizeof(t1), 1, fa);

printf("\n| Прибор %6s Цена %6.2d Гарантия %4d Измервелечин %2d Кол-во заказчиков %2d \t \t \t   |",  t1.name, t1.price, t1.gor, t1.valamount, t1.zakamount);


for(int j=0;j<t1.valamount;j++){
fread( list, sizeof(structvalue) * 1, 1, fa);
printf("\n| Измертиельнаявелечина: %9s , Верхнийпорог %4d , Нижнийпорог %4d , Погрешность %4f \t   |", list->valname, list->valverh, list->valniz, list->pogr);
        }
for(int k=0;k<t1.zakamount;k++){
fread( tab, sizeof(structzak) * 1, 1, fa);
printf("\n| ФИО: %10s Адрес %10s Кол-во приборов %4d \t \t \t \t \t \t   |", tab->fio, tab->adres, tab->kol);
    }
 }puts(" ");
for(int i=0;i<36;i++){
cout<<" "<<ch<<" ";}
fclose(fa);
}
voidout(int d){ // функциявыводаспискаклиентов
fa = fopen("A.dat", "rb");
intrez;
printf("\nВведитедопустимуюпогрешность:");
floatporog;
cin>>porog;
printf("\n Список заказчиковподходящих по условию");
for(int i=0;i<d;i++){
fread( &t1, sizeof(t1), 1, fa);
for(int j=0;j<t1.valamount;j++){
fread( list, sizeof(structvalue) * 1, 1, fa);
if(list->pogr<porog){
rez=2; //отметка того чтоданныйвыполняетусловие
        }
    }
for(int k=0;k<t1.zakamount;k++){
fread( tab, sizeof(structzak) * 1, 1, fa);
if(rez==2){
printf("\n \t ФИО: %10s Адрес %10s Кол-во приборов %4d ", tab->fio, tab->adres, tab->kol);
            }
        }
rez=0;
    }
 }
int main()
{    setlocale(LC_ALL, "Rus");
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
list = (structvalue *)malloc(sizeof(structvalue));
tab = (structzak *)malloc(sizeof(structzak));
int d=input();
    out1(d);
out(d);
return 0;
}

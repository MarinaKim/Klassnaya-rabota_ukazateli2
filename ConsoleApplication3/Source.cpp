#include<iostream>
#include<stdio.h>
#include<math.h>
#include <locale>
#include<stdint.h>
#include<Windows.h>

using namespace std; //cout, cin

#define MONTH 12
#define SIZE 4

int strlen(char*s);
int sum(int *ar, int *end);


void main()
{
	int n;
	setlocale(LC_ALL, "Russian");

	do
	{
		cout << "Введите номер задания: ";
		cin >> n;

		switch (n) {

		case 1: {
			int days[MONTH] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

			printf("days=%p;&days[0]=%p\n\n", days, &days[0]);//%p-выводим адрес

			if (days == &days[0]) //адрес в памяти первого элемента массива
				printf("YES\n");
		}break;
		case 2: {
			short dates[SIZE] = { 25,33,45,12 };
			short *pti = NULL;
			short index;
			double bills[SIZE];
			double *ptf = NULL; \

				pti = dates;//этому указателю будет назначен первый элемент массива
			ptf = bills;
			printf("\t\t short double\n");

			for (index = 0; index < SIZE; index++)
			{
				printf("указатели+%d:%10p %10p \n", index, pti + index, ptf + index);  // ""=шаблон вывода данных,%d-целое число,%p-адрес,
			}


			printf("\n");

			for (index = 0; index < SIZE; index++)
			{
				printf("алдрес %d элемента: %d \n", index, *(pti + index));  // *() -разименование по адресу в ()
			}

		}break;

			//указатели и массивы
		case 3: {
			int a[10];
			int *pa = NULL;

			pa = &a[0];//передадим элемент 0 &a[0]=a? pa=&a[0]=>pa=a
			int x = *(pa + 1);
			pa = a;
			printf("-%p-%p", &a[1], a + 1);
		}break;

		case 4: {

			char name[100] = "Leson references";
			int result = strlen(name);
			printf("длина строки: %d\n\n", result);

		}break;


		case 5: {
			int days[MONTH] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
			printf("Объем памяти под массив days =%d;\n", sizeof(days));// days-массив, размер займет 48 байтов

			printf("сумма элементов массива= %d\n", sum(days, days + MONTH));
		}break;

			//опреации с указателями
		case 6: {
			int arn[5] = { 100,200,300,400,500 };// типы должны быть одинаковые
			int *ptrl, *ptrl2, ptrl3;
			//Присваиание значение указателю
			ptrl = arn; // присваивание указателю адреса
			ptrl2 = &arn[2]; // адреса 3-го элемента

			printf("ptrl=%p,ptrl=%d, &ptrl=%p\n", ptrl, *ptrl, &ptrl); //&-выведет адрес указателя
			//Определение значение
			printf("*ptrl=%d\n", *ptrl);
			//Адрес указателя
			printf("*ptrl=%d\n", &ptrl);

			printf("\n");
			//сложение целочисленного значения с указателем

			for (int i = 0; i < 5; i++)
			{
				printf("ptrl+%d=%p-%d\n", i, ptrl + i, *(ptrl + i));
			}


			printf("\n");
			// инкремент значений, увеличение указателя
			printf("адрес указателя ptrl до ptrl++=%p\n\n", &ptrl);
			printf("ptrl=%p,*ptrl=%d,&ptrl=%p \n", ptrl, *ptrl, &ptrl);

			printf("увеличим на 1\n");
			ptrl++; //перескочим на след элемент массива

			printf("адрес указателя ptrl до ptrl++=\n");
			printf("ptrl=%p,*ptrl=%d,&ptrl=%p \n", ptrl, *ptrl, &ptrl);


			printf("\n");
			//6 вычитание целочисленных знаений
			printf("вычитание= *ptrl=%d\n", *(ptrl - 1));

			printf("\n");
			// 7 Дикремент
			--ptrl;//переход на предыдущиц адрес
			printf("дикремент =*ptrl=%d\n", (ptrl));


			printf("\n");
			//8 вычисление разности указателей

			ptrl2 = &arn[3];
			printf("вычисление разности указателей\n");
			printf("ptrl2=%p(%d),ptrl1=%p(%d),ptrl2-ptrl1=%d \n", ptrl2, *ptrl2, ptrl, *ptrl, ptrl2 - ptrl);

			//8.1 Сравнение указателей

		}break;

		}

	} while (n > 0);
}

int strlen(char*s)
{
	int i;
	for (i = 0; *s != '\0'; s++)
	{
		i++;
	}
	return i;
}

//не знаем размер массива 
int sum(int *ar, int *end) //int sum(const int *ar, int *end)- функция не будет изменять значения в массиве (каждое значение в массиве -const)
{
	printf("Объем памяти под массив ar =%d;\n", sizeof(ar)); //ar -указатель, размер займет только 4 байта, т.к. int
	int total = 0;
	//for (int i = 0; i < end; i++)
	//{
	//	total += ar[i]; //or total+=ar[i];
	//}

	while (ar < end)
	{
		total += *ar; //добавление значения к total
		ar++;//перемещаем указатель на след элемент
		//==
		total += *ar++; //выполняются справа налево: сначала увеличиваем адрес, потом вытаскиваем значение ИНКРЕМЕНТ

		*++ar;//сначала увеличилось значение, потом получаем адрес
		(*ar)++; //увеличивает значение
		*(ar++); //*ar++
		*++(ar);
	}
	return 0;
}

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
		cout << "������� ����� �������: ";
		cin >> n;

		switch (n) {

		case 1: {
			int days[MONTH] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

			printf("days=%p;&days[0]=%p\n\n", days, &days[0]);//%p-������� �����

			if (days == &days[0]) //����� � ������ ������� �������� �������
				printf("YES\n");
		}break;
		case 2: {
			short dates[SIZE] = { 25,33,45,12 };
			short *pti = NULL;
			short index;
			double bills[SIZE];
			double *ptf = NULL; \

				pti = dates;//����� ��������� ����� �������� ������ ������� �������
			ptf = bills;
			printf("\t\t short double\n");

			for (index = 0; index < SIZE; index++)
			{
				printf("���������+%d:%10p %10p \n", index, pti + index, ptf + index);  // ""=������ ������ ������,%d-����� �����,%p-�����,
			}


			printf("\n");

			for (index = 0; index < SIZE; index++)
			{
				printf("������ %d ��������: %d \n", index, *(pti + index));  // *() -������������� �� ������ � ()
			}

		}break;

			//��������� � �������
		case 3: {
			int a[10];
			int *pa = NULL;

			pa = &a[0];//��������� ������� 0 &a[0]=a? pa=&a[0]=>pa=a
			int x = *(pa + 1);
			pa = a;
			printf("-%p-%p", &a[1], a + 1);
		}break;

		case 4: {

			char name[100] = "Leson references";
			int result = strlen(name);
			printf("����� ������: %d\n\n", result);

		}break;


		case 5: {
			int days[MONTH] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
			printf("����� ������ ��� ������ days =%d;\n", sizeof(days));// days-������, ������ ������ 48 ������

			printf("����� ��������� �������= %d\n", sum(days, days + MONTH));
		}break;

			//�������� � �����������
		case 6: {
			int arn[5] = { 100,200,300,400,500 };// ���� ������ ���� ����������
			int *ptrl, *ptrl2, ptrl3;
			//����������� �������� ���������
			ptrl = arn; // ������������ ��������� ������
			ptrl2 = &arn[2]; // ������ 3-�� ��������

			printf("ptrl=%p,ptrl=%d, &ptrl=%p\n", ptrl, *ptrl, &ptrl); //&-������� ����� ���������
			//����������� ��������
			printf("*ptrl=%d\n", *ptrl);
			//����� ���������
			printf("*ptrl=%d\n", &ptrl);

			printf("\n");
			//�������� �������������� �������� � ����������

			for (int i = 0; i < 5; i++)
			{
				printf("ptrl+%d=%p-%d\n", i, ptrl + i, *(ptrl + i));
			}


			printf("\n");
			// ��������� ��������, ���������� ���������
			printf("����� ��������� ptrl �� ptrl++=%p\n\n", &ptrl);
			printf("ptrl=%p,*ptrl=%d,&ptrl=%p \n", ptrl, *ptrl, &ptrl);

			printf("�������� �� 1\n");
			ptrl++; //���������� �� ���� ������� �������

			printf("����� ��������� ptrl �� ptrl++=\n");
			printf("ptrl=%p,*ptrl=%d,&ptrl=%p \n", ptrl, *ptrl, &ptrl);


			printf("\n");
			//6 ��������� ������������� �������
			printf("���������= *ptrl=%d\n", *(ptrl - 1));

			printf("\n");
			// 7 ���������
			--ptrl;//������� �� ���������� �����
			printf("��������� =*ptrl=%d\n", (ptrl));


			printf("\n");
			//8 ���������� �������� ����������

			ptrl2 = &arn[3];
			printf("���������� �������� ����������\n");
			printf("ptrl2=%p(%d),ptrl1=%p(%d),ptrl2-ptrl1=%d \n", ptrl2, *ptrl2, ptrl, *ptrl, ptrl2 - ptrl);

			//8.1 ��������� ����������

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

//�� ����� ������ ������� 
int sum(int *ar, int *end) //int sum(const int *ar, int *end)- ������� �� ����� �������� �������� � ������� (������ �������� � ������� -const)
{
	printf("����� ������ ��� ������ ar =%d;\n", sizeof(ar)); //ar -���������, ������ ������ ������ 4 �����, �.�. int
	int total = 0;
	//for (int i = 0; i < end; i++)
	//{
	//	total += ar[i]; //or total+=ar[i];
	//}

	while (ar < end)
	{
		total += *ar; //���������� �������� � total
		ar++;//���������� ��������� �� ���� �������
		//==
		total += *ar++; //����������� ������ ������: ������� ����������� �����, ����� ����������� �������� ���������

		*++ar;//������� ����������� ��������, ����� �������� �����
		(*ar)++; //����������� ��������
		*(ar++); //*ar++
		*++(ar);
	}
	return 0;
}

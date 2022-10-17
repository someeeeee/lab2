
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void qs(int* items, int left, int right)
{
	int i, j;
	int x, y;



	i = left; j = right;

	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i <right)) i++;
		while ((x <items[j]) && (j >left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left< j) qs(items, left, j);
	if (i <right) qs(items, i, right);
}

void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i <count; ++i) {
			x = items[i];
			for (j = i - gap; (x <items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

int compare(const void * x1, const void * x2)   // функци€сравнени€элементовмассива
{
return( *(int*)x1 - *(int*)x2 );              // если результат вычитани€ равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main(void)
{
	srand(time(NULL));
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	system("chcp 1251");
	system("cls");
	clock_t start, end; // объ€вл€ем переменные дл€ определени€ времени выполнени€
	clock_t start1, end1;
	clock_t start2, end2;
	clock_t start3, end3;
	clock_t start4, end4;
	clock_t start5, end5;
	clock_t start6, end6;
	clock_t start7, end7;
	clock_t start8, end8;
	clock_t start9, end9;
	clock_t start10, end10;
	clock_t start11, end11;
	clock_t start12, end12;
	int a[42000], b[42000], c[42000], n = 42000, i;

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 800;
		b[i] = a[i];
		c[i] = a[i];
	}


	printf("\n\n\n");
	unsigned int start_time = clock();
	shell(a, n);
	unsigned int end_time = clock();
	double search_time = (end_time - start_time) / 1000.0;




	unsigned int start4_time = clock();
	qs(b, 0, n - 1);
	unsigned int end4_time = clock();
	double search4_time = (end4_time - start4_time) / 1000.0;


	unsigned int start9_time = clock();
	qsort(c, n, sizeof(int), compare);
	unsigned int end9_time = clock();
	double search9_time = (end9_time - start9_time) / 1000.0;


	for (i = 0; i < n; i++)
	{
		a[i] = i + 1;
		b[i] = a[i];
		c[i] = a[i];
	}
	unsigned int start1_time = clock();
	shell(a, n);
	unsigned int end1_time = clock();
	double search1_time = (end1_time - start1_time) / 1000.0;


	unsigned int start5_time = clock();
	qs(b, 0, n - 1);
	unsigned int end5_time = clock();
	double search5_time = (end5_time - start5_time) / 1000.0;


	unsigned int start10_time = clock();
	qsort(c, n, sizeof(int), compare);
	unsigned int end10_time = clock();
	double search10_time = (end10_time - start10_time) / 1000.0;


	for (i = 0; i < n; i++)
	{
		a[i] = 42000 - i;
		b[i] = a[i];
		c[i] = a[i];
	}
	unsigned int start2_time = clock();
	shell(a, n);
	unsigned int end2_time = clock();
	double search2_time = (end2_time - start2_time) / 1000.0;


	unsigned int start6_time = clock();
	qs(b, 0, n - 1);
	unsigned int end6_time = clock();
	double search6_time = (end6_time - start6_time) / 1000.0;


	unsigned int start11_time = clock();
	qsort(c, n, sizeof(int), compare);
	unsigned int end11_time = clock();
	double search11_time = (end11_time - start11_time) / 1000.0;





	for (i = 0; i < n; i++)
	{
		if (i < 21000) { a[i] = i; }
		if (i >= 21000) { a[i] = a[i - 1] - 1; }
		b[i] = a[i];
		c[i] = a[i];
	}

	unsigned int start8_time = clock();
	shell(a, n);
	unsigned int end8_time = clock();
	double search8_time = (end8_time - start8_time) / 1000.0;
	unsigned int start7_time = clock();
	qs(b, 0, n - 1);
	unsigned int end7_time = clock();
	double search7_time = (end7_time - start7_time) / 1000.0;


	unsigned int start12_time = clock();
	qsort(c, n, sizeof(int), compare);
	unsigned int end12_time = clock();
	double search12_time = (end12_time - start12_time) / 1000.0;




	printf("|-----------------|-----------------|--------------|--------------|\n");
	printf("|       ранд      |     возраст.    |     убыв.    |     труег.   |\n");
	printf("|-----------------|-----------------|--------------|--------------|\n");
	printf("|shel |  %f |   %f      |  %f    |    %f  |\n", search_time, search1_time, search2_time, search8_time);
	printf("| qs  |  %f |   %f      |  %f    |    %f  |\n", search4_time, search5_time, search6_time, search7_time);
	printf("|qsort|  %f |   %f      |  %f    |    %f  |\n", search9_time, search10_time, search11_time, search12_time);
	printf("|-----------------|-----------------|--------------|--------------|\n");
	system("pause");
}




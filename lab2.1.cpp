#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale>

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale (LC_ALL,"Rus");
	system("cls");
	clock_t start, end; // объ€вл€ем переменные дл€ определени€ времени выполнени€
	int i=0, j=0, r;
	int m,u;
int** A;
int** B;
printf("¬ведите размер: ");
scanf("%d",&m);
A = (int**)malloc(m * sizeof(int));
B = (int**)malloc(m * sizeof(int));
for(int i=0;i<m;i++)
{
	A[i]=(int*)malloc(m * sizeof(int));
	B[i]=(int*)malloc(m * sizeof(int));

//—ложностьќ (n^2):
	
	for(int j=0;j<m;j++)
	{
	A[i][j]=rand() %100+1;
	B[i][j]=rand() %100+1;
	}

}
int** C;
C = (int**)malloc(m * sizeof(int));
	unsigned int start_time =  clock();

//—ложностьќ (n^3):

	for(i=0;i<m;i++)
	{
		C[i]=(int*)malloc(m * sizeof(int));
		for(j=0;j<m;j++)
		{
			u=0;
			for(r=0;r<m;r++)
			{
				u=u+A[i][r]*B[r][j];
				C[i][j]=u;
				
			}	
		}
	}
	unsigned int end_time = clock();
double search_time = (end_time - start_time)/1000.0;
	printf("%lf\n\n",search_time);
	system("pause");
}


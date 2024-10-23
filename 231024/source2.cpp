#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int* CreateMas1(int* n)
{
  //ЭТО ПЛОХО!!!
  *n = 10;
  return (int*)malloc(sizeof(int) * *n);
}

void CreateMas2(int* n, int** arr)
{
  //ЭТО ХОРОШО
  *n = 10;
  int*res = (int*)malloc(sizeof(int) * *n);
  *arr = res;
}

void CrateNMas(int* n, int** sizes, int** data)
{
  int i = 0, p = 1;
  scanf("%d", n);//размерность матрицы
  *sizes = (int*)malloc(*n * sizeof(int));
  for (i = 0; i < *n; i++)
  {
    scanf("%d", &((*sizes)[i]));
    p *= (*sizes)[i];
  }
  *data = (int*)malloc(p * sizeof(int));

}

void CrateCopyNMas(int n, int* sizes, int** data)
{
  int i = 0, p = 1;
  for (i = 0; i < n; i++)
    p *= sizes[i];

  *data = (int*)malloc(p * sizeof(int));
}

void RandNMas(int n, int* sizes, int* data)
{
  int i = 0, p = 1, j = 0;
  for (; i < n; ++i)
    p *= sizes[i];

  for (j=0; j < p; ++j)
    data[j] = rand() % 10;
}

void PrintNMas(int n, int* sizes, int* data)
{
  int i = 0, p = 1, j = 0;
  for (; i < n; ++i)
    p *= sizes[i];
  if (n == 2)
  {
    int x = 0, y = 0;
    for (x = 0; x < sizes[0]; ++x)
    {
      for (y = 0; y < sizes[1]; ++y)
        printf("%d\t", data[x * sizes[1] + y]);
      printf("\n");
    }
  }
  else
  {
    for (j = 0; j < p; ++j)
    {
      printf("%d\t", data[j]);
    }
    printf("\n");
  }
}

void FreeNMas(int* sizes, int* data)
{
  free(sizes);
  free(data);
}

int* PlusNMas(int n, int* sizes, 
  int* data1, int* data2)
{
  int* data3;
  CrateCopyNMas(n, sizes, &data3);
  int i = 0, p = 1, j = 0;
  for (; i < n; ++i)
    p *= sizes[i];

  for (j = 0; j < p; ++j)
  {
    data3[j] = data1[j] + data2[j];
  }
  return data3;
}

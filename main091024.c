#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int CreateArray(int* n, short** arr)
{
  int i = 0;
  scanf("%d", n);
  if (*n < 0 || *n > 500000000)
  {
    printf("Error sizer!!!");
    return -1;
  }
  *arr = (int*)malloc(*n * sizeof(short));
  for (i = 0; i < *n; i++)
  {
    (*arr)[i] = (short)rand() % 100;
    printf("%d\n", (int)((*arr)[i]));
  }
  return 0;
}

double Func2(int n, short* arr)
{
  int i = 0;
  double res = 1;
  for (i = 0; i < n; i++)
    res *= arr[i];
  res = pow(res, 1 / (double)n);
  return res;
}

void FreeArray(short* a)
{
  return free(a);
}

int main()
{
  short* a = 0, errorCode = 0;
  int n = 0;
  srand(time(0));
  errorCode = CreateArray(&n, &a);
  if (errorCode != 0)
    return errorCode;
  double res = Func2(n, a);
  FreeArray(a);
  
  printf("%lf\n", res);

  return 0;
}

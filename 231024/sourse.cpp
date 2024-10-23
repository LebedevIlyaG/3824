#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

#include "header.h"
#include <time.h>

int main()
{
  int* mas = 0, *mas2, *mas3;
  int* sizes = 0;
  int n = 0;
  srand(time(0));

  CrateNMas(&n, &sizes, &mas);
  CrateCopyNMas(n, sizes, &mas2);
  RandNMas(n, sizes, mas);
  RandNMas(n, sizes, mas2);
  PrintNMas(n, sizes, mas);
  printf("\n");
  PrintNMas(n, sizes, mas2);
  printf("\n");

  mas3 = PlusNMas(n, sizes, mas, mas2);
  PrintNMas(n, sizes, mas3);

  FreeNMas(sizes, mas);
  free(mas2);

  return 0;
}
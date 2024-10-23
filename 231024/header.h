#ifndef __HEADER_H__
#define __HEADER_H__

int* CreateMas1(int* n);
void CreateMas2(int* n, int** arr);

void CrateNMas(int* n, int** sizes, int** data);
void CrateCopyNMas(int n, int* sizes, int** data);
void RandNMas(int n, int* sizes, int* data);
void PrintNMas(int n, int* sizes, int* data);
void FreeNMas(int* sizes, int* data);

int* PlusNMas(int n, int* sizes, 
  int* data1, int* data2);

#endif // !__HEADER_H__


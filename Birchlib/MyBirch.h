#pragma once
#include <iostream>

class Birch
{
protected:
  double height;
  int numberOfBranches;
  int* numberOfLeaves;
public:
  Birch();
  Birch(double height_);
  Birch(double height_, int numberOfBranches, int* numberOfLeaves = nullptr);
  Birch(const Birch& p);
  Birch(Birch&& p);
  ~Birch();

  double GetHeight();
  int GetNumberOfBranches();
  int* GetNumberOfLeaves();

  void SetHeight(double height_);
  void SetNumberOfBranches(int numberOfBranches_);
  void SetNumberOfLeaves(int* numberOfBranches_);

  friend std::ostream& operator <<(std::ostream& o, Birch& b);
  friend std::istream& operator >>(std::istream& i, Birch& b);
};


std::ostream& operator <<(std::ostream& o, Birch& b);
std::istream& operator >>(std::istream& i, Birch& b);
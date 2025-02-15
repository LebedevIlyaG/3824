
#include "MyBirch.h"

Birch::Birch()
{
}

Birch::Birch(double height_)
{
}

Birch::Birch(double height_, int numberOfBranches, int* numberOfLeaves)
{
}

Birch::Birch(const Birch& p)
{
}

Birch::Birch(Birch&& p)
{
}

Birch::~Birch()
{
}

double Birch::GetHeight()
{
  return 0.0;
}

int Birch::GetNumberOfBranches()
{
  return 0;
}

int* Birch::GetNumberOfLeaves()
{
  return nullptr;
}

void Birch::SetHeight(double height_)
{
}

void Birch::SetNumberOfBranches(int numberOfBranches_)
{
}

void Birch::SetNumberOfLeaves(int* numberOfBranches_)
{
}

std::ostream& operator<<(std::ostream& o, Birch& b)
{
  return o;
}

std::istream& operator>>(std::istream& i, Birch& b)
{
  return i;
}

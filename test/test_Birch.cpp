#include "MyBirch.h"

#include <gtest.h>

TEST(Birch, can_create_birch_with_positive_height)
{
  ASSERT_NO_THROW(Birch bf(3));
}

TEST(Birch, can_get_height)
{
  Birch bf(3);

  EXPECT_NEAR(3, bf.GetHeight(), 0.000001);
}

TEST(Birch, new_birch_is_set_to_zero)
{
  Birch bf(0);

  int sum = 0;
  for (int i = 0; i < bf.GetNumberOfBranches(); i++)
  {
    sum += bf.GetNumberOfLeaves()[i];
  }

  EXPECT_EQ(0, sum);
}

TEST(Birch, can_set_number_of_branches)
{
  Birch bf(10);

  bf.SetNumberOfBranches(3);
  EXPECT_NE(0, bf.GetNumberOfBranches());
}


TEST(Birch, throws_when_create_birch_with_negative_height)
{
  ASSERT_ANY_THROW(Birch bf(-3));
}

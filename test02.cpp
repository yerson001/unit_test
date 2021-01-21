#include "operations.cpp"
#include "lista.h"
#include <gtest/gtest.h>

TEST(SquareRootTest, PositiveNos) 
{ 
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
}
 
TEST(SquareRootTest, PositiveNos) 
{
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}

TEST(sum,PositiveNos)
{
    ASSERT_EQ(7,sum(3,4));
    ASSERT_EQ(3,sum(7,4));
}

TEST(main,add)
{
   lista<int> *a = new lista<int>();
   ASSERT_TRUE(a != NULL)<< "Lista vacia";
   ASSERT_TRUE(a->head == NULL)<< "head es nulo";
   delete a;
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

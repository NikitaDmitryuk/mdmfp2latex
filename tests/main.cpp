#include "gtest/gtest.h"
#include "mdmfp2latex/mdmfp2latex.hpp"

TEST(testTest, test1){
  ASSERT_EQ(add(1, 1), 2);
}

TEST(testTest, test2){
  ASSERT_EQ(add(1, -1), 0);
}

TEST(testTest, test3){
  ASSERT_EQ(add(1, -3), -2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

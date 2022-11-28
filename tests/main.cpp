#include "gtest/gtest.h"
#include "mdmfp2latex/mdfile.hpp"

TEST(MdFile, test1){
  MdFile mdFile = MdFile("a.md");

  ASSERT_EQ(mdFile.getFileName(), "a.md");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#include "test_create_folder.h"
#include <iostream>
#include <string>
#include "../../../../src/core/create/createFolder/create_folder.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

using test::test_core::test_create::TestCraeteFolder;
using core::create::CreateFolder;

TEST_F(TestCraeteFolder, TestCraeteFolderOne) {
    std::string target = "";
    std::string returnValue = "";
    EXPECT_EQ(target, returnValue);
}
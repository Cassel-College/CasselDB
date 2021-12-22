#include "test_select_folder.h"
#include <iostream>
#include <string>
#include "../../../../src/core/select/select_dir/select_folder.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

using test::test_core::test_select::TestSelectFolder;
using core::select::SelectFolder;

TEST_F(TestSelectFolder, TestGetFolderListByPath) {
    std::string target = "/opt";
    std::vector<std::string> folderList = {};
    folderList = SelectFolder::GetFolderListByPath(target);
    EXPECT_EQ(9999, folderList.size());
}

TEST_F(TestSelectFolder, TestGetFileListByPath) {
    std::string target = "/opt";
    std::vector<std::string> folderList = {};
    folderList = SelectFolder::GetFileListByPath(target);
    EXPECT_EQ(9999, folderList.size());
}
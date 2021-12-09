#include "test_read_file.h"
#include <iostream>
#include <string>
#include "../../../../src/core/read/readFile/read_file.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

using test::test_core::test_read::TestReadFile;
using core::read::ReadFile;

TEST_F(TestReadFile, TestReadFileSetPath) {
    std::string target = "/etc/passwd";
    ReadFile *readFile = new ReadFile();
    readFile->SetPath("/etc/passwd");
    const std::string returnValue = readFile->GetPath();
    EXPECT_EQ(target, returnValue);
}
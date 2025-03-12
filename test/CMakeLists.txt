
add_executable(SortTest SortTest.cc)
add_executable(MiddleSearch MiddleSearchTest.cc)
add_executable(DFSSearch DFSSearchTest.cc)

target_link_libraries(SortTest gtest)
target_link_libraries(SortTest gmock)
target_link_libraries(SortTest gtest_main)

add_test(SortTest COMMAND  SortTest)
target_link_libraries(MiddleSearch gtest)
target_link_libraries(MiddleSearch gmock)
target_link_libraries(MiddleSearch gtest_main)

target_link_libraries(DFSSearch gtest)
target_link_libraries(DFSSearch gmock)
target_link_libraries(DFSSearch gtest_main)

add_test(selectSort COMMAND  selectSort)
add_test(MiddleSearch COMMAND  MiddleSearch)
add_test(DFSSearch COMMAND  DFSSearch)
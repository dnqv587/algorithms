
add_executable(SortTest SortTest.cc)

target_link_libraries(SortTest gtest)
target_link_libraries(SortTest gmock)
target_link_libraries(SortTest gtest_main)

add_test(SortTest COMMAND  SortTest)
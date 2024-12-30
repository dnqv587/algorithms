
add_executable(selectSort selectTest.cc)

target_link_libraries(selectSort gtest)
target_link_libraries(selectSort gmock)
target_link_libraries(selectSort gtest_main)

add_test(selectSort COMMAND  selectSort)
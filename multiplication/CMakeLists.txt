add_executable(test_multiplication test.cpp multiplication.h)

target_link_libraries(test_multiplication PRIVATE catch)

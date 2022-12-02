add_executable(test_date test.cpp date.h)

target_link_libraries(test_date PRIVATE catch)

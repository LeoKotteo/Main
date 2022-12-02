add_executable(test_vector test.cpp vector.h)

target_link_libraries(test_vector PRIVATE catch)

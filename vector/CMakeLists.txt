add_executable(test_vector test.cpp vector.h)

target_include_directories(test_vector PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../catch/)

target_link_libraries(test_vector PRIVATE catch)
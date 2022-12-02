set(EXECUTABLE_NAME "test_date")

add_executable(${EXECUTABLE_NAME} test.cpp date.h)

target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../catch/)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE catch)
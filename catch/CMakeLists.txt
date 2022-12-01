add_library(catch STATIC catch.hpp catch_main.cpp)

target_include_directories(catch PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
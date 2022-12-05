#include <catch.hpp>

#include "multiplication.h"

TEST_CASE("Simple", "Multiplication") {
    REQUIRE(Multiply(2, 3) == 6);
}

TEST_CASE("Advanced", "Multiplication") {
    REQUIRE(Multiply(100100100, 999999999) == 100100099899899900ll);
}
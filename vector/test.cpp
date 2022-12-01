#include <catch.hpp>
#include <vector>

#include "vector.h"

void AssertEqual(const Vector& actual, const std::vector<int>& expected) {
    REQUIRE(actual.Size() == expected.size());
    for (int i = 0; i < actual.Size(); ++i) {
        REQUIRE(actual[i] == expected[i]);
    }
}

TEST_CASE("Basic constructors", "Vector") {
    {
        Vector vector;
        REQUIRE(vector.Size() == 0);
    }
    {
        Vector vector(4);
        AssertEqual(vector, std::vector<int>{0, 0, 0, 0});
    }
}

TEST_CASE("Indexing", "Vector") {
    Vector vector(4);
    REQUIRE_THROWS(vector[8]);
    REQUIRE_THROWS(vector[4]);
    REQUIRE_THROWS(vector[-1]);
    vector[0] = 3;
    vector[1] = 8;
    vector[3] = 4;
    AssertEqual(vector, std::vector<int>{3, 8, 0, 4});
}

TEST_CASE("Copying", "Vector") {
    Vector vector(3);
    vector[0] = 8;
    vector[2] = 6;
    Vector vector_copy = vector;
    AssertEqual(vector_copy, std::vector<int>{8, 0, 6});

    vector = vector;
    AssertEqual(vector, std::vector<int>{8, 0, 6});
    vector_copy = vector_copy;
    AssertEqual(vector_copy, std::vector<int>{8, 0, 6});
    vector = vector_copy;
    AssertEqual(vector, std::vector<int>{8, 0, 6});
    
    vector[0] = 5;
    AssertEqual(vector, std::vector<int>{5, 0, 6});
    AssertEqual(vector_copy, std::vector<int>{8, 0, 6});

    vector_copy[1] = 3;
    AssertEqual(vector, std::vector<int>{5, 0, 6});
    AssertEqual(vector_copy, std::vector<int>{8, 3, 6});

    vector = vector_copy = vector = vector;
}

TEST_CASE("Equality", "Vector") {
    Vector a(4);
    Vector b(5);
    REQUIRE_FALSE(a == b);

    Vector c(4);
    REQUIRE(a == c);

    c[2] = 4;
    REQUIRE_FALSE(a == c);

    a[2] = 4;
    REQUIRE(a == c);
}
#include <catch.hpp>
#include <vector>

#include "date.h"

void CheckEqual(const Date& actual, const std::vector<int>& expected) {
    std::vector<int> date_as_vector = {
        actual.GetDay(), actual.GetMonth(), actual.GetYear()
    };
    REQUIRE(date_as_vector == expected);
}

void CheckEqual(const Date& lhs, const Date& rhs) {
    std::vector<int> lhs_as_vector = {
        lhs.GetDay(), lhs.GetMonth(), lhs.GetYear()
    };
    std::vector<int> rhs_as_vector = {
        rhs.GetDay(), rhs.GetMonth(), rhs.GetYear()
    };
    REQUIRE(lhs_as_vector == rhs_as_vector);
}

TEST_CASE("Сonstructor", "Date") {
    {
        Date date(25, 3, 1918);
        CheckEqual(date, std::vector<int>{25, 3, 1918});
    }
    {
        Date date(25, 12, -1);
        CheckEqual(date, std::vector<int>{25, 12, -1});
    }
    {
        REQUIRE_THROWS(Date(0, 0, 0));
        REQUIRE_THROWS(Date(-1, 1, 1));
        REQUIRE_THROWS(Date(1, -1, 1));
        REQUIRE_NOTHROW(Date(1, 1, 1));
    }
    {
        REQUIRE_THROWS(Date(32, 1, 2022));
        REQUIRE_NOTHROW(Date(31, 1, 2022));
        REQUIRE_THROWS(Date(29, 2, 2022));
        REQUIRE_NOTHROW(Date(28, 2, 2022));
        REQUIRE_THROWS(Date(32, 3, 2022));
        REQUIRE_NOTHROW(Date(31, 3, 2022));
        REQUIRE_THROWS(Date(31, 4, 2022));
        REQUIRE_NOTHROW(Date(30, 4, 2022));
        REQUIRE_THROWS(Date(32, 5, 2022));
        REQUIRE_NOTHROW(Date(31, 5, 2022));
        REQUIRE_THROWS(Date(31, 6, 2022));
        REQUIRE_NOTHROW(Date(30, 6, 2022));
        REQUIRE_THROWS(Date(32, 7, 2022));
        REQUIRE_NOTHROW(Date(31, 7, 2022));
        REQUIRE_THROWS(Date(32, 8, 2022));
        REQUIRE_NOTHROW(Date(31, 8, 2022));
        REQUIRE_THROWS(Date(31, 9, 2022));
        REQUIRE_NOTHROW(Date(30, 9, 2022));
        REQUIRE_THROWS(Date(32, 10, 2022));
        REQUIRE_NOTHROW(Date(31, 10, 2022));
        REQUIRE_THROWS(Date(31, 11, 2022));
        REQUIRE_NOTHROW(Date(30, 11, 2022));
        REQUIRE_THROWS(Date(32, 12, 2022));
        REQUIRE_NOTHROW(Date(31, 12, 2022));
    }
    {
        REQUIRE_THROWS(Date(29, 2, 2001));
        REQUIRE_NOTHROW(Date(28, 2, 2001));
        REQUIRE_THROWS(Date(29, 2, 1700));
        REQUIRE_NOTHROW(Date(28, 2, 1700));
        REQUIRE_THROWS(Date(29, 2, 1800));
        REQUIRE_NOTHROW(Date(28, 2, 1800));
        REQUIRE_THROWS(Date(29, 2, 1900));
        REQUIRE_NOTHROW(Date(28, 2, 1900));
        REQUIRE_THROWS(Date(30, 2, 2000));
        REQUIRE_NOTHROW(Date(29, 2, 2000));
        REQUIRE_THROWS(Date(30, 2, 2004));
        REQUIRE_NOTHROW(Date(29, 2, 2004));
        REQUIRE_THROWS(Date(30, 2, 1600));
        REQUIRE_NOTHROW(Date(29, 2, 1600));
        REQUIRE_THROWS(Date(30, 2, 2020));
        REQUIRE_NOTHROW(Date(29, 2, 2020));
    }
}

TEST_CASE("Leap year", "Date") {
    {
        Date date(1, 1, 2020);
        REQUIRE(date.IsLeapYear());
    }
    {
        Date date(1, 1, 2022);
        REQUIRE_FALSE(date.IsLeapYear());
    }
    {
        Date date(1, 1, 2000);
        REQUIRE(date.IsLeapYear());
    }
    {
        Date date(1, 1, 1900);
        REQUIRE_FALSE(date.IsLeapYear());
    }
    {
        Date date(1, 1, 1800);
        REQUIRE_FALSE(date.IsLeapYear());
    }
    {
        Date date(1, 1, 1700);
        REQUIRE_FALSE(date.IsLeapYear());
    }
    {
        Date date(1, 1, 1701);
        REQUIRE_FALSE(date.IsLeapYear());
    }
    {
        Date date(1, 1, 1600);
        REQUIRE(date.IsLeapYear());
    }
}

TEST_CASE("Next-previous day", "Date") {
    {
        Date date(1, 12, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{2, 12, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(30, 12, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{31, 12, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(31, 12, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 1, 2023});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(30, 11, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 12, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(31, 10, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 11, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(30, 9, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 10, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(31, 8, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 9, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(31, 7, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 8, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(30, 6, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 7, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(31, 5, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 6, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(30, 4, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 5, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(31, 3, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 4, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(28, 2, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 3, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(31, 1, 2022);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 2, 2022});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(29, 2, 2020);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 3, 2020});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(28, 2, 2020);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{29, 2, 2020});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(28, 2, 2000);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{29, 2, 2000});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(29, 2, 2000);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 3, 2000});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
    {
        Date date(28, 2, 1900);
        Date next = date.GetNextDay();
        CheckEqual(next, std::vector<int>{1, 3, 1900});

        Date previous_to_next = next.GetPreviousDay();
        CheckEqual(date, previous_to_next);
    }
}

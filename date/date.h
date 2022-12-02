#pragma once

class Date {
public:
    Date(int day, int month, int year);

    Date GetNextDay() const;

private:
    int day_;
    int month_;
    int year_;
};

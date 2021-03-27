#include "airline_ticket.h"

#include <sstream>
#include <iostream>
#include <tuple>

using namespace std;

#define UPDATE_FIELD(ticket, field, values)                         \
    if (values.find(#field) != values.end())                        \
    {                                                               \
        istringstream is(values.find(#field)->second);              \
        is >> ticket.field;                                         \
    }                                  

istream& operator>>(istream& is, Date& date)
{
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    return is;
}

istream& operator>>(istream& is, Time& time)
{
    is >> time.hours;
    is.ignore(1);
    is >> time.minutes;
    return is;
}

bool operator<(const Date& lhs, const Date& rhs) 
{
    auto lhs_key = tie(lhs.year, lhs.month, lhs.day);
    auto rhs_key = tie(rhs.year, rhs.month, rhs.day);
    return lhs_key < rhs_key;
}

bool operator<(const Time& lhs, const Time& rhs)
{
    auto lhs_key = tie(lhs.hours, lhs.minutes);
    auto rhs_key = tie(rhs.hours, rhs.minutes);
    return lhs_key < rhs_key;
}

bool operator==(const Date& lhs, const Date& rhs)
{
    auto lhs_key = tie(lhs.year, lhs.month, lhs.day);
    auto rhs_key = tie(rhs.year, rhs.month, rhs.day);
    return lhs_key == rhs_key;
}

bool operator==(const Time& lhs, const Time& rhs)
{
    auto lhs_key = tie(lhs.hours, lhs.minutes);
    auto rhs_key = tie(rhs.hours, rhs.minutes);
    return lhs_key == rhs_key;
}
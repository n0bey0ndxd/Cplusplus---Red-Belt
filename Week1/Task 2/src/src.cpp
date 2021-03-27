#include "airline_ticket.h"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <tuple>

using namespace std;

ostream& operator<<(ostream& os, const Date& date)
{
    os << setfill('0');
    os << setw(4) << date.year << setw(2) << date.month
        << setw(2) << date.day;
    return os;
}

ostream& operator<<(ostream& os, const Time& time)
{
    os << setfill('0');
    os << setw(2) << time.hours << setw(2) << time.minutes;
    return os;
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


#define SORT_BY(field)                  \
    [](const AirlineTicket& lhs,        \
    const AirlineTicket& rhs) {         \
       return lhs.field < rhs.field; }
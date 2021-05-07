// Date.cpp
#include "StudentHead.h"
// Date instructor
Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
// SetDate function
void Date::SetDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
// printDate function, read only
void Date::PrintDate() const
{
    cout<<year<<"/"<<month<<"/"<<day<<endl;
}
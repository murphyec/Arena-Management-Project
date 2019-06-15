#include "Date.h"


Date::~Date()
{
    //dtor
}

Date::Date(const string date)
{
    setDateFromString(date);
}

void Date::setDateFromString(const string str)
{
    Year=0;
    Month=0;
    Day=0;
    int number=0, pos=1;
    for(int i=0;i<str.length();i++)
        if((str.at(i)>='0')&&(str.at(i)<='9'))
            number=number*10+(str.at(i)-'0');
        else
            if(str.at(i)=='/')
            {
            switch(pos)
                {
                    case 3: Year=number;
                            break;
                    case 1:Month=number;
                            break;
                    default: Day=number;
                            break;
                }
                pos++;
                number=0;
            }
    Year=number;
}


Date::Date(const int _year, const int _month, const int _day)
{
    Year=_year;
    if((_month<1)||(_month>12))
        Month=1;
    else
        Month=_month;
    if((_day<1)||(_day>31))
       Day=1;
    else
       Day=_day;
}

istream &operator >> (istream &in, Date &d){
    string s;
    in>>s;
    d.setDateFromString(s);
    return in;
}
ostream &operator << (ostream &out, const Date &d){
    out<<d.Month<<"/"<<d.Day<<"/"<<d.Year;
    return out;
}

bool operator== (const Date&a,const Date&b)
{
    if((a.Year==b.Year)&&(a.Month==b.Month)&&(a.Day==b.Day))
        return true;
    else
        return false;
}

#ifndef DATE_H
#define DATE_H
#include <string>
#include <istream>
#include <ostream>

using namespace std;
class Date
{
    public:
        Date(const string date);
        Date(const int _year=1, const int _month=1, const int _day=1);
        virtual ~Date();
        int getYear() const {return Year;}
        int getMonth() const {return Month;}
        int getDay() const {return Day;}
        friend istream &operator >> (istream &, Date &);
        friend ostream &operator << (ostream &, const Date &);
        void setDateFromString(const string );
        friend bool operator== (const Date&,const Date&);
    protected:
        int Year;
        int Month;
        int Day;
    private:
};

#endif // DATE_H

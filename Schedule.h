#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "Manageable.h"
#include <string>
#include "Date.h"
using namespace std;

class Schedule: public Manageable
{
    public:
        Schedule(const string name="",const string date="",const string time="");
        Schedule(const string name,const Date date,const string time);
        virtual ~Schedule();
        friend istream &operator >> (istream &, Schedule &);
        string getName() const{return Name;}
        Date getDate() const{return DateEvent;}
        string getTime() const{return Time;}
        void printInfoForUser(ostream &) const;
        void inputInfoFromUser(istream &);
    protected:

    private:
        string Name;
        Date DateEvent;
        string Time;
};

#endif // SCHEDULE_H

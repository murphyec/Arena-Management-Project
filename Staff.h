#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <istream>
#include "Manageable.h"
#define COUNT_SECTION 50
#define COUNT_SEATS 10
#define BASE_COST 45

using namespace std;
class Staff: public Manageable
{
    public:
        Staff(const int _ID=0, const string _FirstName="",const string _LastName="",const string _Job="", const double _Salary=0);
        int getID() const {return ID;}
        double getSalary() const {return Salary;}
        string getFirstName() const {return FirstName;}
        string getLastName() const {return LastName;}
        string getJob() const {return Job;}
        virtual ~Staff();
        friend istream &operator >> (istream &, Staff &);
        void printInfoForUser(ostream &) const;
        void inputInfoFromUser(istream &);
    protected:

    private:
        int ID;
        string FirstName;
        string LastName;
        string Job;
        double Salary;
};


#endif // STAFF_H

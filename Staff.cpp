#include "Staff.h"
#include <iostream>

Staff::Staff(const int _ID, const string _FirstName,const string _LastName,const string _Job, const double _Salary)
{
    //ctor
    ID=_ID;
    FirstName=_FirstName;
    LastName=_LastName;
    Job=_Job;
    Salary=_Salary;
}

Staff::~Staff()
{
    //dtor
}

istream &operator >> (istream &in, Staff &t)
{
	in >> t.ID>> t.FirstName >>t.LastName >>t.Job >>t.Salary;
	return in;
}
/*ostream &operator << (ostream &out, const Staff&a)
{
	char buffer[200];
	sprintf_s(buffer, 200, "%5d%20s%20s%5d", a.Employee_Number, a.Employee_Last_Name, a.Employee_First_Name, a.Employee_Years_of_Service);
	out << buffer ;
	return out;
}*/

void Staff::printInfoForUser(ostream &out) const{
    out<<"Staff ID: "<<ID<<endl;
    out<<"Full Name: "<<LastName<<", "<<FirstName<<endl;
    out<<"Job: "<<Job<<endl;
    out<<"Salary: "<<Salary<<endl;
}
void Staff::inputInfoFromUser(istream & in){
    cout<<"Input staff ID: ";
    in>>ID;
    cout<<"Input First Name: ";
    in>>FirstName;
    cout<<"Input Last Name: ";
    in>>LastName;
    cout<<"Job: ";
    in>>Job;
    cout<<"Salary: ";
    in>>Salary;
}

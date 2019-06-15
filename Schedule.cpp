#include "Schedule.h"
#include <iostream>

Schedule::Schedule(const string name,const string date,const string time)
{
    //ctor
    Name=name;
    DateEvent.setDateFromString(date);
    Time=time;
}

Schedule::Schedule(const string name,const Date date,const string time){
    Name=name;
    DateEvent=date;
    Time=time;
}

Schedule::~Schedule()
{
    //dtor
}

istream &operator >> (istream &in, Schedule &t)
{
	in >> t.Name >> t.DateEvent>>t.Time;
	return in;
}
/*ostream &operator << (ostream &out, const Ticket&a)
{
	char buffer[200];
	sprintf_s(buffer, 200, "%5d%20s%20s%5d", a.Employee_Number, a.Employee_Last_Name, a.Employee_First_Name, a.Employee_Years_of_Service);
	out << buffer ;
	return out;
}*/

void Schedule::printInfoForUser(ostream &out) const{
    out<<"Event Name: "<<Name<<endl;
    out<<"Date: "<<DateEvent<<endl;
    out<<"Time: "<<Time<<endl;

}
void Schedule::inputInfoFromUser(istream &in){
    cout<<"Input event's name: ";
    in>>Name;
    cout<<"Input event's date: ";
    in>>DateEvent;
    cout<<"Input event's time (hh:mm): ";
    in>>Time;
}

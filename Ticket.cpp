#include "Ticket.h"

Ticket::Ticket(int _SectionNum, int _SeatNum, double _Price, bool _IsAvailable, string _EventName)
{
    //ctor
    SectionNum=_SectionNum;
    SeatNum=_SeatNum;
    Price=_Price;
    IsAvailable=_IsAvailable;
    EventName=_EventName;
}

Ticket::~Ticket()
{
    //dtor
}

istream &operator >> (istream &in, Ticket &t)
{
	in >> t.SectionNum >> t.SeatNum >>t.Price >>t.IsAvailable >>t.EventName;
	return in;
}
/*ostream &operator << (ostream &out, const Ticket&a)
{
	char buffer[200];
	sprintf_s(buffer, 200, "%5d%20s%20s%5d", a.Employee_Number, a.Employee_Last_Name, a.Employee_First_Name, a.Employee_Years_of_Service);
	out << buffer ;
	return out;
}*/

void Ticket::printInfoForUser(ostream &out) const{
    out<<"Selection Number: "<<SectionNum<<endl;
    out<<"Seat Number: "<<SeatNum<<endl;
    out<<"Price: "<<Price<<endl;
    out<<"Available: "<<IsAvailable<<endl;
    out<<"Name: "<<EventName<<endl;
}
void Ticket::inputInfoFromUser(istream & in){
}

#include "Parking.h"

Parking::Parking(const int section, const int space, const int price, const bool isAvailable)
{
    //ctor
    Section=section;
    Space=space;
    Price=price;
    IsAvailable=isAvailable;

}

Parking::~Parking()
{
    //dtor
}

istream &operator >> (istream &in, Parking &t)
{
	in >> t.Section >> t.Space>>t.Price >>t.IsAvailable;
	return in;
}
/*ostream &operator << (ostream &out, const Parking&a)
{
	char buffer[200];
	out << buffer ;
	return out;
}*/

void Parking::printInfoForUser(ostream &out) const{
    out<<"Selection: "<<Section<<endl;
    out<<"Space: "<<Space<<endl;
    out<<"Price: "<<Price<<endl;
    out<<"Available: "<<IsAvailable<<endl;
}
void Parking::inputInfoFromUser(istream & in){
}

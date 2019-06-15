#include "Concession.h"

Concession::Concession(const string _name,const int _amount, const double _price)
{
    //ctor
    amount=_amount;
    price=_price;
    name=_name;
}

Concession::~Concession()
{
    //dtor
}

istream &operator >> (istream &in, Concession &t)
{
	in >> t.amount >> t.price;
	return in;
}

void Concession::printInfoForUser(ostream &out) const
{
    out<<name<<" Inventory: "<<amount<<endl;
    out<<"Price: "<<price<<endl;
}

double Concession::sale(int _amount)
{

 if(amount>_amount)
 {
    amount-=_amount;
 }
 else
    _amount=0;
 return _amount*price;
}

double Concession::order(int _amount)
{

 amount+=_amount;
 return _amount*price;
}
void Concession::inputInfoFromUser(istream &in){
}

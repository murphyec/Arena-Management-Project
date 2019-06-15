#ifndef CONCESSION_H
#define CONCESSION_H
#include <string>
#include "Manageable.h"

using namespace std;
class Concession: public Manageable
{
    public:
        Concession(const string _name="",const int _amount=0, const double _price=0);
        virtual ~Concession();
        friend istream &operator >> (istream &, Concession &);
        void printInfoForUser(ostream &) const;
        void inputInfoFromUser(istream &);
        string getName() const {return name;}
        int getAmount() const {return amount;}
        double getPrice() const{ return price;}
        double sale(int _amount);
        double order(int _amount);
    protected:
        int amount;
        double price;
        string name;

};

#endif // CONCESSION_H

#ifndef PARKING_H
#define PARKING_H

#include <string>
#include <istream>
#include "Manageable.h"
#define COUNT_PARKING_SECTION 20
#define COUNT_PARKING_SPOTS 30
#define BASE_PARKING_COST 10

using namespace std;
class Parking: public Manageable
{
    public:
        Parking (const int section=0, const int space=1, const int price=0, const bool isAvailable=true);
        int getSectionNumber() const {return Section;}
        int getSpace() const {return Space;}
        double getPrice() const {return Price;}
        bool isAvailable() const {return IsAvailable;}
        virtual ~Parking();
        friend istream &operator >> (istream &, Parking &);
        void printInfoForUser(ostream &) const;
        void inputInfoFromUser(istream &);
        bool changeAvailable(){IsAvailable=!IsAvailable; return IsAvailable;}
    protected:

    private:
        int Section;
        int Space;
        int Price;
        bool IsAvailable;
};


#endif // PARKING_H

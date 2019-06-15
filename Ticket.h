#ifndef TICKET_H
#define TICKET_H
#include <string>
#include <istream>
#include "Manageable.h"
#define COUNT_SECTION 50
#define COUNT_SEATS 10
#define BASE_COST 45

using namespace std;
class Ticket: public Manageable
{
    public:
        Ticket(int _SectionNum=0, int _SeatNum=0, double _Price=0, bool _IsAvailable=false, string _EventName="");
        int getSectionNumber() const {return SectionNum;}
        int getSeatNum() const {return SeatNum;}
        double getPrice() const {return Price;}
        bool isAvailable() const {return IsAvailable;}
        string getEventName() const {return EventName;}
        virtual ~Ticket();
        friend istream &operator >> (istream &, Ticket &);
        void printInfoForUser(ostream &) const;
        void inputInfoFromUser(istream &);
        void sale(){IsAvailable=false;}
        void refund(){IsAvailable=true;}
    protected:

    private:
        int SectionNum;
        int SeatNum;
        double Price;
        bool IsAvailable;
        string EventName;
};
#endif // TICKET_H

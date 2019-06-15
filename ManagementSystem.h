#ifndef MANAGEMENTSYSTEM_H
#define MANAGEMENTSYSTEM_H

#include "Ticket.h"
#include "Schedule.h"
#include "Parking.h"
#include "Concession.h"
#include "Staff.h"
#include <list>

class ManagementSystem
{
    public:
        ManagementSystem();
        virtual ~ManagementSystem();
        void showTickets() const;
        void showParking(int section=-1) const;
        void showConcession() const;

        void showSectionByFreeSpace(int amount) const;
        void showTicketsByAvailable(const bool typeAvailable=true) const;
        void showEventForDate(const Date eventDate) const;

        void showStaffByJob(const string job="") const;
        Staff findStaffById(const int id) const;
        void removeStaffById(const int id);
        void addStaff(Staff newEl){staff.push_back(&newEl);}

        void showEventDetail(const string eventName) const;
        void showTicketForName(const string eventName) const;
        void createEvent(const Schedule& s);
        void showTicketForDate(const Date eventDate) const;
        bool changeAvailableParking(int section, int spot) ;

        int getTotalSales() const {return TotalSales;}
        int getCashOnHand() const {return CashOnHand;}
        int getDebt() const {return Debt;}
        double payCash(int amount){CashOnHand+=amount;Debt-=amount; return amount;}

        void saleTicket(string name,int section, int place);
        void orderInventory();
        void saleInventory();
        double getSaleConcession() const{return saleConcession;}
    protected:
        static void printListForUser(const list<Manageable*>);
    private:
        list<Manageable*>tickets;
        list<Manageable*>schedule;
        list<Manageable*>parking;
        list<Manageable*>staff;
        list<Manageable*>concession;
        int TotalSales;
        int CashOnHand;
        int Debt;
        double saleConcession;
};

#endif // MANAGEMENTSYSTEM_H



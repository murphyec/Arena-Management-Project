#include "ManagementSystem.h"
#include <fstream>
#include <iostream>
const string nameConcession[]={"Hot Dog", "Peanuts","Burger", "Drinks","Beer","Jersey"};

ManagementSystem::ManagementSystem()
{
    //ctor
    //read tickets:
    ifstream fIn("ticket.txt");
    if(!fIn.is_open())
    {
        cout<<"I can not to open file with tickets (ticket.txt)"<<endl;
        exit(1);
    }
    Ticket *t;
    while(!fIn.eof())
    {
            t=new Ticket();
            fIn>>*t;
            tickets.push_back(t);
    }
    fIn.close();


    //read Schedule:
    ifstream fInS("schedule.txt");
    if(!fInS.is_open())
    {
        cout<<"I can not to open file with schedule (schedule.txt)"<<endl;
        exit(1);
    }
    Schedule *s;
    while(!fInS.eof())
    {
            s=new Schedule();
            fInS>>*s;
            schedule.push_back(s);
    }
    fInS.close();

    //read parking:
    ifstream fInP("parking.txt");
    if(!fInP.is_open())
    {
        cout<<"I can not to open file with parking (parking.txt)"<<endl;
        exit(1);
    }
    Parking *p;
    while(!fInP.eof())
    {
            p=new Parking();
            fInP>>*p;
            parking.push_back(p);
    }
    fInP.close();

    //read staff:
    ifstream fInSt("staff.txt");
    if(!fInSt.is_open())
    {
        cout<<"I can not to open file with staff (staff.txt)"<<endl;
        exit(1);
    }
    Staff *st;
    while(!fInSt.eof())
    {
            st=new Staff();
            fInSt>>*st;
            staff.push_back(st);
    }
    fInSt.close();

    //read data about bank:
    ifstream fInB("bank.txt");
    if(!fInB.is_open())
    {
        cout<<"I can not to open file with bank data (bank.txt)"<<endl;
        exit(1);
    }
    fInB>>TotalSales;
    fInB>>CashOnHand;
    fInB>>Debt;
    fInB.close();

    //read concession:
    ifstream fInC("concession.txt");
    if(!fInC.is_open())
    {
        cout<<"I can not to open file with concession (concession.txt)"<<endl;
        exit(1);
    }
    Concession *c;
    int k=0;
    while(!fInC.eof())
    {
            c=new Concession(nameConcession[k++]);
            fInC>>*c;
            concession.push_back(c);
            if(k>5)
                break;
    }
    saleConcession=0;
    fInC>>saleConcession;
    fInC.close();


}

ManagementSystem::~ManagementSystem()
{
    //dtor
}

void ManagementSystem::showTickets() const
{
    printListForUser(tickets);
}

void ManagementSystem::showConcession() const{
    printListForUser(concession);
}
void ManagementSystem::showParking(int section) const
{
    int k=0;
    const Parking* p;
    for (list<Manageable*>::const_iterator iter = parking.begin(); iter != parking.end(); iter++)
    {
        p=(Parking *) *iter;
        if((section==-1)||(section==p->getSectionNumber()))
          {
              p->printInfoForUser(cout);
              cout<<endl;

              k++;
          }
    }
    if(k==0)
        cout<<"\nSorry, we have not such parking!\n";
}

Staff ManagementSystem::findStaffById(const int id) const
{
    const Staff* p;
    for (list<Manageable*>::const_iterator iter = staff.begin(); iter != staff.end(); iter++)
    {
        p=(Staff *) *iter;
        if(id==p->getID())
          return *p;

    }
    return Staff();
}

void ManagementSystem::removeStaffById(const int id)
{
    const Staff* p;
    for (list<Manageable*>::iterator iter = staff.begin(); iter != staff.end(); iter++)
    {
        p=(Staff *) *iter;
        if(id==p->getID())
          {
              staff.erase(iter);
              break;
           }
    }
}

void ManagementSystem::showStaffByJob(const string job) const
{
    int k=0;
    const Staff* p;
    for (list<Manageable*>::const_iterator iter = staff.begin(); iter != staff.end(); iter++)
    {
        p=(Staff *) *iter;
        if((job=="")||(job==p->getJob()))
          {
              p->printInfoForUser(cout);
              cout<<endl;
              k++;
          }
    }
    if(k==0)
        cout<<"\nSorry, we have not such staff!\n";
}

void ManagementSystem::showSectionByFreeSpace(int amount) const{
    int freeSpace[COUNT_PARKING_SECTION]={0};
    //go throw parking and count free space:
    Parking *p;
    for (list<Manageable*>::const_iterator iter = parking.begin(); iter != parking.end(); iter++)
    {
        p=(Parking *) *iter;
        if(p->isAvailable())
          freeSpace[p->getSectionNumber()]++;
    }

    cout<<"List of section with at least "<<amount<<" free spots: ";
    for(int i=0;i<COUNT_PARKING_SECTION;i++)
    {
        if(freeSpace[i]>=amount)
            cout<<i<<" ";
    }
    cout<<endl;
}

bool ManagementSystem::changeAvailableParking(int section, int spot) {

    //go throw parking:
    Parking *p;
    for (list<Manageable*>::const_iterator iter = parking.begin(); iter != parking.end(); iter++)
    {
        p=(Parking *) *iter;
        if((p->getSectionNumber()==section)&&(p->getSpace()==spot))
            {
                if(p->isAvailable())
                    Debt+=BASE_PARKING_COST;
                return p->changeAvailable();
            }

    }
    return false;
}

void ManagementSystem::showTicketsByAvailable(const bool typeAvailable) const
{
    int k=0;
    const Ticket *t;
    for (list<Manageable*>::const_iterator iter = tickets.begin(); iter != tickets.end(); iter++)
    {
        t=(Ticket *) *iter;
        if(t->isAvailable()==typeAvailable)
          {
              t->printInfoForUser(cout);
              cout<<endl;
              k++;
          }
    }
    if(k==0)
        cout<<"\nSorry, we have not such tickets!\n";
}

void ManagementSystem::printListForUser(const list<Manageable*> listItems)
{
    for (list<Manageable*>::const_iterator iter = listItems.begin(); iter != listItems.end(); iter++)
    {
        (*iter)->printInfoForUser(cout);
        cout<<endl;
    }
}

void ManagementSystem::showEventForDate(const Date eventDate) const{
    for (list<Manageable*>::const_iterator iter = schedule.begin(); iter != schedule.end(); iter++)
    {
        Schedule *item=(Schedule*)*iter;
        if(item->getDate()==eventDate)
        {
        item->printInfoForUser(cout);
        cout<<endl;
        }
    }
}

void ManagementSystem::showTicketForName(const string eventName) const{
    Ticket *t;
for (list<Manageable*>::const_iterator iterEvent = tickets.begin(); iterEvent != tickets.end(); iterEvent++)
    {
        t=(Ticket *) *iterEvent;
        if(t->getEventName()==eventName)
          {
              t->printInfoForUser(cout);
              cout<<endl;

          }
    }
}
void ManagementSystem::showEventDetail(const string eventName) const{
    for (list<Manageable*>::const_iterator iter = schedule.begin(); iter != schedule.end(); iter++)
    {
        Schedule *item=(Schedule*)*iter;
        if(item->getName()==eventName)
        {
            item->printInfoForUser(cout);
            showTicketForName(eventName);
        }
    }
}

void ManagementSystem::createEvent(const Schedule& s){
    Schedule *item=new Schedule(s.getName(),s.getDate(),s.getTime());
    schedule.push_back(item);
    //add tickets:
    int i, j;
    for(i=0;i<COUNT_SECTION;i++)
        for(j=0;j<COUNT_SEATS;j++)
            {
                Ticket *t=new Ticket(i,j,BASE_COST,true,s.getName());
                tickets.push_back(t);
            }

}

void ManagementSystem::showTicketForDate(const Date eventDate) const{

    for (list<Manageable*>::const_iterator iter = schedule.begin(); iter != schedule.end(); iter++)
    {
        Schedule *item=(Schedule*)*iter;
        if(item->getDate()==eventDate)
            showTicketForName(item->getName());
    }

}
void ManagementSystem::saleTicket(string name,int section, int place)
{

for (list<Manageable*>::iterator iter = tickets.begin(); iter != tickets.end(); iter++)
    {
        Ticket *item=(Ticket *)*iter;
        if((item->getEventName()==name)&&(section==item->getSectionNumber())&&(place==item->getSeatNum()))
        {
            if(item->isAvailable())
            {
                TotalSales+=item->getPrice();
                item->sale();
                cout<<"Sold"<<endl;
            }
            else
            {
                TotalSales-=item->getPrice();
                item->refund();
                cout<<"Refund"<<endl;
            }
        }

    }
}

void ManagementSystem::orderInventory(){
    cout<<"What item would you like to order? "<<endl;
    int k=0;
    for (list<Manageable*>::iterator iter = concession.begin(); iter != concession.end(); iter++)
    {
        Concession *item=(Concession *)*iter;
        cout<<(k+1)<<". "<<item->getName()<<endl;
        k++;
    }
    int ans,amount;
    cin>>ans;
    cout<<"How many you like to buy? ";
    cin>>amount;
    //find item:
    k=0;
    for (list<Manageable*>::iterator iter = concession.begin(); iter != concession.end(); iter++,k++ )
        if(k==ans-1)
            {
            Concession *item=(Concession *)*iter;
            CashOnHand-=item->order(amount);
            break;
            }
}

void ManagementSystem::saleInventory(){
    cout<<"What item would you like to buy? "<<endl;
    int k=0;
    for (list<Manageable*>::iterator iter = concession.begin(); iter != concession.end(); iter++)
    {
        Concession *item=(Concession *)*iter;
        cout<<(k+1)<<". "<<item->getName()<<endl;
        k++;
    }
    int ans,amount;
    cin>>ans;
    cout<<"How many you like to buy? ";
    cin>>amount;
    //find item:
    k=0;
    for (list<Manageable*>::iterator iter = concession.begin(); iter != concession.end(); iter++,k++ )
        if(k==ans-1)
            {
            Concession *item=(Concession *)*iter;
            CashOnHand+=item->sale(amount);
            saleConcession+=item->sale(amount);
            break;
            }
}

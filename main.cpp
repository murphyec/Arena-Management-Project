#include <iostream>
#include "ManagementSystem.h"

using namespace std;

int mainMenu();
int ticketSubmenu();
void ticketSubsystem(ManagementSystem &);
int scheduleSubmenu();
void scheduleSubsystem(ManagementSystem &);
int parkingSubmenu();
void parkingSubsystem(ManagementSystem &);
int staffSubmenu();
void staffSubsystem(ManagementSystem &);
int bankSubmenu();
void bankSubsystem(ManagementSystem &);
int concessionSubmenu();
void concessionSubsystem(ManagementSystem &);


int main()
{
    ManagementSystem system;
    int input=1;
    while(input!=0)
    {
        input=mainMenu();
        switch(input)
        {
        case 1: ticketSubsystem(system);
                break;
        case 2: scheduleSubsystem(system);
                break;
        case 3: parkingSubsystem(system);
                break;
        case 4: staffSubsystem(system);
                break;
        case 5: bankSubsystem(system);
                break;
        case 6: concessionSubsystem(system);
                break;
        }
    }


    return 0;
}




int mainMenu()
{
    int s=-1;
    cout<<"\nWelcome to Arena Management System. Please choose an action: ";
    cout<<"\nMain Menu: ";
    cout<<"\n1.  Manage Tickets ";
    cout<<"\n2.  Manage Schedule ";
    cout<<"\n3.  Manage Parking ";
    cout<<"\n4.  Manage Staff ";
    cout<<"\n5.  Manage Bank Account ";
    cout<<"\n6.  Manage Concession Stand ";
    cout<<"\n\n0. Exit";
    cout<<"\n-----------------------------";
    cout<<"\nYour choice? ";
    cin>>s;
    if((s<0)||(s>6))
        {
            cout<<"You have input wrong number. Please, try one more time!";
            return mainMenu();
        }
    else
        return s;
}

int ticketSubmenu()
{
    int s;
    cout<<"\nTicket manage\n";
    cout<<"\n1.  Show all ticket's info";
    cout<<"\n2.  Show all available tickets";
    cout<<"\n3.  Show all unavailable tickers";
    cout<<"\n4.  Sell/Refund ticket";
    cout<<"\n5.  Update ticket info";
    cout<<"\n6.  Search for ticket by date";
    cout<<"\n0.  Return to main menu";
    cout<<"\nYour choice? ";
    cin>>s;
    if((s<0)||(s>6))
        {
            cout<<"You have input wrong number. Please, try one more time!";
            return ticketSubmenu();
        }
    else
        return s;
}

void ticketSubsystem(ManagementSystem &system)
{
    int input=1;
    while(input!=0)
    {
        input=ticketSubmenu();
        switch(input)
        {
        case 1:
            system.showTickets();
            break;
        case 2:
            system.showTicketsByAvailable();
            break;
        case 3:
            system.showTicketsByAvailable(false);
            break;
        case 4:{
            string name;
            int section, place;
            cout<<"Input name of event";
            cin>>name;
            cout<<"Input section: ";
            cin>>section;
            cout<<"Input place: ";
            cin>>place;
            system.saleTicket(name,section, place);
        }
        case 6:{
            Date eventDate;
            cout<<"Input date for ticket (mm/dd/yyyy): ";
            cin>>eventDate;
            system.showTicketForDate(eventDate);

        }
        //cout<<"\n5.  Update ticket info";
        }
    }
}
int scheduleSubmenu()
{
    int s;
    cout<<"\nSchedule manage\n";
    cout<<"\n1. Create a new event";
    cout<<"\n2. Show all events on a certain date";
    cout<<"\n3. Adjust an event's information";
    cout<<"\n4. Cancel an event";
    cout<<"\n5. Show all event's information";
    cout<<"\n0.  Return to main menu";
    cout<<"\nYour choice? ";
    cin>>s;
    if((s<0)||(s>5))
        {
            cout<<"You have input wrong number. Please, try one more time!";
            return scheduleSubmenu();
        }
    else
        return s;
}

void scheduleSubsystem(ManagementSystem &system)
{
    //cout<<"\n3. Adjust an event's information";
    //cout<<"\n4. Cancel an event";

    int input=1;
    while(input!=0)
    {
        input=scheduleSubmenu();
        switch(input)
        {
        case 1:
            {
            Schedule newItem;
            newItem.inputInfoFromUser(cin);
            system.createEvent(newItem);
            break;
            }

        case 2://Show all events on a certain date
            {
                Date eventDate;
                cout<<"Input date for event (mm/dd/yyyy): ";
                cin>>eventDate;
                system.showEventForDate(eventDate);
                break;
            }
        case 4://Cancel an event
            {
            string eventName;
            cout<<"Input event's name: ";
            cin>>eventName;
            system.showTicketsByAvailable(false);
            break;
            }
        case 5://Show all event's information
            {
            string eventName;
            cout<<"Input event's name: ";
            cin>>eventName;
            system.showEventDetail(eventName);
            break;
            }

        case 6:{
        }
        }
    }
}

int parkingSubmenu()
{
    int s;
    cout<<"\nParking manage\n";
    cout<<"\n1.  Show all parking's info";
    cout<<"\n2.  Show all parking for certain parking section";
    cout<<"\n3.  Show all section with at least selected amount free places";
    cout<<"\n4.  Change availability for parking slot";

    cout<<"\n0.  Return to main menu";
    cout<<"\nYour choice? ";
    cin>>s;
    if((s<0)||(s>4))
        {
            cout<<"You have input wrong number. Please, try one more time!";
            return parkingSubmenu();
        }
    else
        return s;
}

void parkingSubsystem(ManagementSystem &system)
{
    int input=1;
    while(input!=0)
    {
        input=parkingSubmenu();
        switch(input)
        {
        case 1:
            system.showParking();
            break;
        case 2:
            {
            int number;
            cout<<"Input section's number: ";
            cin>>number;
            system.showParking(number);
            break;
            }

        case 3://3.  Show all section with at least selected amount free places
            {
            int number;
            cout<<"Input amount free places: ";
            cin>>number;
            system.showSectionByFreeSpace(number);
            break;
            }
        case 4:{// 4.  Change availability for parking slot
                int section, place;
                cout<<"Input section: ";
                cin>>section;
                cout<<"Input place: ";
                cin>>place;
                if(system.changeAvailableParking(section,place))
                    cout<<"Now spot is free";
                else
                    cout<<"Now spot is busy";
                }
        }
    }
}


int staffSubmenu()
{
    int s;
    cout<<"\nStaff manage\n";
    cout<<"\n1.  Show all staff's info";
    cout<<"\n2.  Show detail info by ID";
    cout<<"\n3.  Show staff by job";
    cout<<"\n4.  Edit staff By Id";
    cout<<"\n5.  Add new staff";
    cout<<"\n6.  Fire staff";
    cout<<"\n0.  Return to main menu";
    cout<<"\nYour choice? ";
    cin>>s;
    if((s<0)||(s>6))
        {
            cout<<"You have input wrong number. Please, try one more time!";
            return ticketSubmenu();
        }
    else
        return s;
}

void staffSubsystem(ManagementSystem &system)
{
    int input=1;
    while(input!=0)
    {
        input=staffSubmenu();
        switch(input)
        {
        case 1: //Show all staff's info
            system.showStaffByJob();
            break;
        case 2:// Show detail info by ID
            {
                int id;
                cout<<"Input id: ";
                cin>>id;
                system.findStaffById(id).printInfoForUser(cout);
                break;
            }

        case 3://Show staff by job
            {
                string job;
                cout<<"Input job: ";
                cin>>job;
                system.showStaffByJob(job);
                break;
            }
        /* cout<<"\n4.  Edit staff By Id";*/
        case 5: { // Add new staff
                Staff newStaff;
                newStaff.inputInfoFromUser(cin);
                system.addStaff(newStaff);
                }
        case 6:{//6.  Fire staff
                int id;
                cout<<"Input id staff for fire: ";
                cin>>id;
                system.removeStaffById(id);
                break;
                }
        }
    }
}
int bankSubmenu()
{
    int s;
    cout<<"\nBank manage\n";
    cout<<"\n1.  Show bank account information";
    cout<<"\n2.  Calculate a given months ticket sales";
    cout<<"\n3.  Pay off a given amount cash";
    cout<<"\n4.  Calculate how long it will take for the arena to pay off its debt";
    cout<<"\n0.  Return to main menu";
    cout<<"\nYour choice? ";
    cin>>s;
    if((s<0)||(s>4))
        {
            cout<<"You have input wrong number. Please, try one more time!";
            return bankSubmenu();
        }
    else
        return s;
}

void bankSubsystem(ManagementSystem &system)
{
    int input=1;
    while(input!=0)
    {
        input=bankSubmenu();
        switch(input)
        {
        case 1: //Show bank account information"
            {
            cout<<"Total Sales: "<<system.getTotalSales()<<endl;
            cout<<"Cash on hand: "<<system.getCashOnHand()<<endl;
            cout<<"Debt: "<<system.getDebt()<<endl;
            break;
            }

        case 2://Calculate a given months ticket sales
            {
                int number;
                cout<<"Input month number: ";
                cin>>number;
                Date start(2018,number,1);
                Date end(2018,number,31);

                break;
            }

        case 3://Pay off a given amount cash";
            {
                double c;
                cout<<"Input amount cash: ";
                cin>>c;
                system.payCash(c);
                break;
            }

        }
    }
}


int concessionSubmenu()
{
    int s;
    cout<<"\nConcession manage\n";
    cout<<"\n1. Show concession stand info";
    cout<<"\n2. Sell item";
    cout<<"\n3. Print total lifetime sales amount";
    cout<<"\n4. Order inventory";
    cout<<"\n0.  Return to main menu";
    cout<<"\nYour choice? ";
    cin>>s;
    if((s<0)||(s>4))
        {
            cout<<"You have input wrong number. Please, try one more time!";
            return concessionSubmenu();
        }
    else
        return s;
}

void concessionSubsystem(ManagementSystem &system)
{

    int input=1;
    while(input!=0)
    {
        input=concessionSubmenu();
        switch(input)
        {
        case 1: //Show concession stand info
            {
            system.showConcession();
            break;
            }
        case 2://Show all events on a certain date
            {
            system.saleInventory();
            break;
            }
        case 3:
            {
                cout<<"Total lifetime sales amount from the concession stand  is "<<system.getSaleConcession()<<endl;
                break;
            }
        case 4://Order inventory
            {
            system.orderInventory();
            break;
            }
        case 0:
            break;
        default:
            cout<<"Sorry, wrong number";
        }
    }
}

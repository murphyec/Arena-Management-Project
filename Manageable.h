#ifndef MANAGEABLE_H
#define MANAGEABLE_H
#include <ostream>
#include <istream>
using namespace std;
/*interface for work with standard items (like output, input etc.*/
class Manageable
{
    public:
        virtual void printInfoForUser(ostream &out) const=0;
        virtual void inputInfoFromUser(istream &in)=0;
};

#endif // MANAGEABLE_H

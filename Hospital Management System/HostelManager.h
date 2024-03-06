#ifndef HOSTELMANAGER_H
#define HOSTELMANAGER_H
#include "Hostel.h"

// Replace Method with Method Object
class HostelManager
{
    public:
        HostelManager();
        static void manageHostel(Hostel&);
        virtual ~HostelManager();

    protected:

    private:
        static void displayMenu();
    static void addStudent(Hostel& hostel);
    static void markRentPayment(Hostel& hostel);
    static void markSecurityFeePayment(Hostel& hostel);
};

#endif // HOSTELMANAGER_H

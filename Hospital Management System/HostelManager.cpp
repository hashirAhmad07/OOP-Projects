#include "HostelManager.h"
#include<iostream>
#include<string>
using namespace std;
HostelManager::HostelManager()
{
    //ctor
}

// Extract Method

void HostelManager::displayMenu() {
    cout << "\nHostel Management System\n";
    cout << "1. Add Student\n";
    cout << "2. Allocate Rooms\n";
    cout << "3. Display Room Allocation\n";
    cout << "4. Mark Rent Payment\n";
    cout << "5. Mark Security Fee Payment\n";
    cout << "6. Display Students\n";
    cout << "7. View Room Students\n";
    cout << "0. Exit\n";
}

void HostelManager::addStudent(Hostel& hostel) {
    string newName;
    int newRollNumber;

    cout << "Enter name of the new student: ";
    cin.ignore();
    getline(cin, newName);
    cout << "Enter Roll Number of the new student: ";
    cin >> newRollNumber;

    hostel.addStudent(Student(newName, newRollNumber));
    cout << "New student added successfully." << endl;
}

void HostelManager::markRentPayment(Hostel& hostel) {
    int rentRollNumber;
    cout << "Enter Roll Number for rent payment: ";
    cin >> rentRollNumber;
    hostel.markRentPaid(rentRollNumber);
}

void HostelManager::markSecurityFeePayment(Hostel& hostel) {
    int securityFeeRollNumber;
    cout << "Enter Roll Number for security fee payment: ";
    cin >> securityFeeRollNumber;
    hostel.markSecurityFeePaid(securityFeeRollNumber);
}

void HostelManager::manageHostel(Hostel& hostel) {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(hostel);
                break;
            case 2:
                hostel.allocateRooms();
                break;
            case 3:
                hostel.displayRoomAllocation();
                break;
            case 4:
                markRentPayment(hostel);
                break;
            case 5:
                markSecurityFeePayment(hostel);
                break;
            case 6:
                hostel.displayStudents();
                break;
            case 7:
                hostel.viewRoomStudents();
                break;
            case 0:
                cout << "Exiting Hostel Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);
}
HostelManager::~HostelManager()
{
    //dtor
}

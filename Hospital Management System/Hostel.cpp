#include "Hostel.h"
#include "Student.h"
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

Hostel::Hostel()
{
    //ctor
}
void Hostel::addStudent(const Student& student) {
    students.push_back(student);
}

void Hostel::displayStudents() const {
    cout << setw(20) << left << "Name" << setw(10) << "Roll Number" << setw(20) << "Rent Paid" << setw(18) << "Security Fee Paid" << endl;
    cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

    for (const auto& student : students) {
        cout << setw(20) << left << student.getName() << setw(10) << student.getRollNumber();
        cout << setw(15) << (student.isRentPaid() ? "Yes" : "No");
        cout << setw(18) << (student.isSecurityFeePaid() ? "Yes" : "No") << endl;
    }
}

void Hostel::allocateRooms() {
    int roomNumber = 1;

    cout << "Allocating Rooms..." << endl;

    for (int i = 0; i < students.size(); i += 3) {
        Room room;
        for (int j = i; j < i + 3 && j < students.size(); ++j) {
            room.addOccupant(students[j]);
            cout << "Room " << roomNumber << " allocated to: " << students[j].getName() << endl;
        }
        rooms.push_back(room);
        roomNumber++;
    }

    cout << "Rooms allocated successfully." << endl;
}

void Hostel::displayRoomAllocation() const {
    cout << "Room allocation:" << endl;
    for (int i = 0; i < rooms.size(); ++i) {
        cout << "Room " << (i + 1) << ": ";
        for (const auto& student : rooms[i].occupants) {
            cout << student.getName() << ", ";
        }
        cout << endl;
    }
}

void Hostel::markRentPaid(int rollNumber) {
    for (auto& student : students) {
        if (student.getRollNumber() == rollNumber) {
            student.markRentPaid();
            cout << "Rent marked as paid for student " << student.getName() << "." << endl;
            return;
        }
    }

    cout << "Student with Roll Number " << rollNumber << " not found." << endl;
}

void Hostel::markSecurityFeePaid(int rollNumber) {
    for (auto& student : students) {
        if (student.getRollNumber() == rollNumber) {
            student.markSecurityFeePaid();
            cout << "Security Fee marked as paid for student " << student.getName() << "." << endl;
            return;
        }
    }

    cout << "Student with Roll Number " << rollNumber << " not found." << endl;
}

void Hostel::viewRoomStudents() const {
    int roomNumber;
    cout << "Enter the room number to view students: ";
    cin >> roomNumber;

    if (roomNumber >= 1 && roomNumber <= rooms.size()) {
        cout << "Students in Room " << roomNumber << ": ";
        for (const auto& student : rooms[roomNumber - 1].occupants) {
            cout << student.getName() << ", ";
        }
        cout << endl;
    } else {
        cout << "Invalid room number. Please enter a valid room number." << endl;
    }
}

Hostel::~Hostel()
{
    //dtor
}

#ifndef HOSTEL_H
#define HOSTEL_H

#include<iostream>
#include<string>
#include "Student.h"
#include "Room.h"

class Hostel
{
public:
    Hostel();
    void addStudent(const Student& student);
    void displayStudents() const;
    void allocateRooms();
    void displayRoomAllocation() const;
    void markRentPaid(int rollNumber);
    void markSecurityFeePaid(int rollNumber);
    void viewRoomStudents() const;
    virtual ~Hostel();

protected:

private:
    std::vector<Student> students;
    std::vector<Room> rooms;
};

#endif // HOSTEL_H

#include "Student.h"

Student::Student(std::string n, int roll) : name(n), rollNumber(roll), rentPaid(false), securityFeePaid(false) {
}

std::string Student::getName() const {
    return name;
}

int Student::getRollNumber() const {
    return rollNumber;
}

bool Student::isRentPaid() const {
    return rentPaid;
}

bool Student::isSecurityFeePaid() const {
    return securityFeePaid;
}

void Student::markRentPaid() {
    rentPaid = true;
}

void Student::markSecurityFeePaid() {
    securityFeePaid = true;
}
Student::Student()
{
    //ctor
}

Student::~Student()
{
    //dtor
}

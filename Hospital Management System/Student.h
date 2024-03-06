#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>

class Student
{
public:

    std::string name;
    int rollNumber;
    bool rentPaid;
    bool securityFeePaid;
    Student();
    std::string getName() const;
    int getRollNumber() const;
    bool isRentPaid() const;
    bool isSecurityFeePaid() const;

    void markRentPaid();
    void markSecurityFeePaid();
    Student(std::string, int);
    virtual ~Student();

protected:

private:
};

#endif // STUDENT_H

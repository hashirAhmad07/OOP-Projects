#ifndef ROOM_H
#define ROOM_H

#include<iostream>
#include<string>
#include<vector>
#include "Student.h"

class Room
{
    public:
        std::vector<Student> occupants;
        void addOccupant(const Student&);
        Room();
        virtual ~Room();

    protected:

    private:
};

#endif // ROOM_H

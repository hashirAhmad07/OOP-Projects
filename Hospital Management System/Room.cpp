#include "Room.h"
#include "Student.h"

Room::Room()
{
    //ctor
}

void Room::addOccupant(const Student& student)
{
    occupants.push_back(student);
}

Room::~Room()
{
    //dtor
}

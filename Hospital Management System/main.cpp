#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Student.h"
#include "Hostel.h"
#include "Room.h"
#include "HostelManager.h"

int main()
{
    Hostel hostel;
    HostelManager::manageHostel(hostel);
    return 0;
}

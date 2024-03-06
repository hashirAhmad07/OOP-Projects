#include <iostream>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include "Login.h"
#include "Client.h"
#include "Account.h"
#include "Bank.h"
#include "ChoiceHandler.h"
#include "Client.h"



using namespace std;


int main() {
    system("color 75 ");
    std::vector<Client::Data> clients;
    Bank bank(clients);
    bank.choice();

    return 0;
}

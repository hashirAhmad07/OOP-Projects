#include "Bank.h"
#include "Login.h"
#include "Client.h"
#include <windows.h>
#include <iomanip>
#include <windows.h>
#include<iostream>
using namespace std;

Bank::Bank(std::vector<Client::Data>& clients) : clients(clients)
{
    //ctor
}

void Bank::choice()
{
    int key;
    while (1)
    {
        system("cls"); // Clear the console for a cleaner look
        cout<<"\n\n\n\n\n";
        cout << "\t\t\t\t\t***************************************" << endl;
        cout << "\t\t\t\t\t*            BANK MAIN MENU           *" << endl;
        cout << "\t\t\t\t\t***************************************" << endl;
        cout << "\t\t\t\t\t1. LOGIN\n"
             "\t\t\t\t\t2. LOGOUT\n"
             "\t\t\t\t\t3. RETURN TO MAIN MENU\n"
             "\t\t\t\t\t***************************************\n"
             "\t\t\t\t\tEnter your choice: ";

        cin >> key;

        switch (key)
        {
        case 1:
            system("color f8");
//            Login::login();
            bool Access;
            Access = Login::login();
            if(Access == true){
                 choiceHandler.handleChoice(client);
            }
            else{
                cout << "\t\t\t\t\tInvalid Credential, Access Denied!" << endl;
                Sleep(1000);
            }
            break;

        case 2:
            system("color 77");
            Login::Logout();
            break;

        case 3:
            // Handle other cases or delegate to ChoiceHandler as needed.
            break;

        default:
            cout << "Invalid input! Please enter a valid option." << endl;
            break;
        }
    }
}

Bank::~Bank()
{
    //dtor
}

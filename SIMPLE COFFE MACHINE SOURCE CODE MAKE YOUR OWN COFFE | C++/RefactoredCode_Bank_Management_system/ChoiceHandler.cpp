#include "ChoiceHandler.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "Client.h"

using namespace std;

Client ChoiceHandler::obj;

ChoiceHandler::ChoiceHandler() {
    // Initialize other members if needed
}

void ChoiceHandler::handleChoice(vector<Client::Data>& clients) {
    while (ch != '7') {
        displayMenu();
        cin >> ch;
        theme.ClearScreen();
        processChoice(clients);
    }
}

void ChoiceHandler::displayMenu() {
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t***************************************" << endl;
    cout << "\t\t\t\t\t*                 Menu                *" << endl;
    cout << "\t\t\t\t\t***************************************" << endl;
    cout << "\t\t\t\t\tPRESS 1 TO CREATE ACCOUNT" << endl;
    cout << "\t\t\t\t\tPRESS 2 TO VIEW ACCOUNT" << endl;
    cout << "\t\t\t\t\tPRESS 3 TO UPDATE ACCOUNT INFORMATION" << endl;
    cout << "\t\t\t\t\tPRESS 4 TO VIEW ACCOUNT DETAILS" << endl;
    cout << "\t\t\t\t\tPRESS 5 FOR TRANSACTIONS" << endl;
    cout << "\t\t\t\t\tPRESS 6 TO REMOVE EXISTING ACCOUNT" << endl;
    cout << "\t\t\t\t\tPRESS 7 TO EXIT: ";
}

void ChoiceHandler::processChoice(const std::vector<Client::Data>& client) {
    switch (ch) {
        case '1':
            obj.Register();
            break;

        case '2':
            if (obj.isEmpty()) {
                cout << "\t\t\t\t\tNO DATA IS ENTERED" << endl;
            } else {
                cout << "\t\t\t\t\tDisplaying Client Data:" << endl;
                obj.getdata();
            }
            break;

        case '3':
            if (obj.isEmpty()) {
                cout << "\t\t\t\t\tNO DATA IS ENTERED" << endl;
            } else {
                obj.update();
            }
            break;

        case '4':
            if (obj.isEmpty()) {
                cout << "\t\t\t\t\tNO DATA IS ENTERED" << endl;
            } else {
                account.searching(obj);
            }
            break;

        case '5':
            if (obj.isEmpty()) {
                cout << "\t\t\t\t\tNO DATA IS ENTERED" << endl;
            } else {
                account.transactions(obj);
            }
            break;

        case '6':
            if (obj.isEmpty()) {
                cout << "\t\t\t\t\tNO DATA IS ENTERED" << endl;
            } else {
                account.del(obj);
            }
            break;

        case '7':
            cout << "\t\t\t\t\tSUCCESSFULLY EXIT" << endl;
            break;

        default:
            cout << "\t\t\t\t\tINVALID INPUT" << endl;
            break;
    }
}

ChoiceHandler::~ChoiceHandler() {
    // Destructor implementation, if needed
}

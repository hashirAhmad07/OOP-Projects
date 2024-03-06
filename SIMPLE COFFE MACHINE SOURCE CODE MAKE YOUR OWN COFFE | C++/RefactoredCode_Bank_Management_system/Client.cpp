#include<iostream>
#include<windows.h>
using namespace std;
#include "Login.h"
#include "Client.h"
#include "Theme.h"
#include <limits>

Client::Client()
{
    client_no = 0;
    registration = false;
}

void Client::setdata()
{
    Data newClient;

    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\tENTER THE DATA OF PERSON " << client_no + 1 << endl;

    cout << "\t\t\t\t\tENTER NAME : ";
    cin.ignore();
    getline(cin, newClient.name);

    cout << "\t\t\t\t\tENTER ID : ";
    getline(cin, newClient.ID);

    cout << "\t\t\t\t\tENTER ADDRESS : ";
    getline(cin, newClient.address);

    cout << "\t\t\t\t\tENTER CONTACT : ";
    cin >> newClient.contact;

    cout << "\t\t\t\t\tENTER CASH : ";
    cin >> newClient.cash;

    cout << "\n\t\t\t\t\tENTER DATE OF BIRTH" << endl;
    cout << "\n\t\t\t\t\tDAY   :";
    cin >> newClient.day;

    cout << "\t\t\t\t\tMONTH:";
    cin >> newClient.month;

    cout << "\t\t\t\t\tYEAR:";
    cin >> newClient.year;

    setCredential(newClient);

    // Add the new client data to the vector
    client.push_back(newClient);

    // Increment the client counter
    client_no++;
}

void Client::Register()
{
    setdata();
    theme.ClearScreen();
    theme.showLoadingAnimation();
    theme.ClearScreen();
    registration = true;
    client_no++;
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t\tSUCCESSFULLY REGISTERED" << endl;
    Sleep(1000);
    theme.ClearScreen();
}

void Client::setCredential(Data& clients)
{
    theme.ClearScreen();
    cout << "\t\t\t\t\t***************************************" << endl;
    cout << "\t\t\t\t\t*     Setting up login credential     *" << endl;
    cout << "\t\t\t\t\t***************************************" << endl;
    cout << "\t\t\t\t\tSET THE USER NAME: ";
    cin.ignore();
    getline(cin, clients.username);

    cout << "\t\t\t\t\tENTER PASSWORD: ";
    cin >> clients.password;

    string Password1;
    while (true)
    {
        cout << "\t\t\t\t\tTYPE YOUR PASSWORD AGAIN: ";
        cin >> Password1;

        if (Password1 == clients.password)
        {
            cout << "\t\t\t\t\t Credential Set Successfully:" <<endl;
            break;
        }
        else
        {
            cout << "\t\t\t\t\t PASSWORD DOESN'T MATCH" << endl;
        }
    }
}

void Client::update()
{
    cout << "\t\t\t\t\tENTER THE ID OF USER YOU WANT TO UPDATE : ";
    cin >> id;
    for (int i = 0; i < client_no; i++)
    {
        if (id == client[i].ID)
        {
            cout << "\t\t\t\t\tPREVIOUS DATA" << endl;
            cout << "\t\t\t\t\t***************************" << endl;
            cout << "\t\t\t\t\tDATA OF PERSON : " << i + 1 << endl;
            cout << "\t\t\t\t\tNAME           : " << client[i].name << endl;
            cout << "\t\t\t\t\tID             : " << client[i].ID << endl;
            cout << "\t\t\t\t\tDOB            : " << client[i].day<<"/"<<client[i].month<<"/"<<client[i].year<< endl;
            cout << "\t\t\t\t\tCONTACT        : " << client[i].contact << endl;
            cout << "\t\t\t\t\tADDRESS        : " << client[i].address << endl;
            cout << "\t\t\t\t\tCASH           : " << client[i].cash << endl;
            cout << "\t\t\t\t\t****************************" << endl;
            cout << "\t\t\t\t\tENTER NEW DATA" << endl;

            cout << "\t\t\t\t\tENTER NAME : ";
            cin >> ws;  // consume any leading white spaces
            getline(cin, client[i].name);

            cout << "\t\t\t\t\tENTER ID : ";
            cin >> client[i].ID;

            cout << "\t\t\t\t\tENTER DAY : ";
            cin >> client[i].day;

            cout << "\t\t\t\t\tENTER MONTH : ";
            cin >> client[i].month;

            cout << "\t\t\t\t\tENTER YEAR : ";
            cin >> client[i].year;

            cout << "\t\t\t\t\tENTER ADDRESS : ";
            cin >> ws;  // consume any leading white spaces
            getline(cin, client[i].address);

            cout << "\t\t\t\t\tENTER CONTACT : ";
            cin >> client[i].contact;

            cout << "\t\t\t\t\tENTER CASH : ";
            cin >> client[i].cash;
            break;
        }

        if (i == client_no - 1)
            cout << "\t\t\t\t\tNO SEARCH RECORD FOUND" << endl;
    }
}
int Client::searchClient() {
    cout << "ENTER ID OF USER WHOSE DATA YOU WANT TO SEARCH FOR : ";
    cin >> id;

    for (int i = 0; i < client_no; i++) {
        if (id == client[i].ID) {
            return i;
        }
    }

    return -1;
}


void Client::ViewClientDetail(int i)
{
    cout << "\t\t\t\t\t*************************" << endl;
        cout << "\t\t\t\t\tDATA OF PERSON : " << i + 1 << endl;
        cout << "\t\t\t\t\tNAME           : " << client[i].name << endl;
        cout << "\t\t\t\t\tID             : " << client[i].ID << endl;
        cout << "\t\t\t\t\tDOB            : " << client[i].day<<"/"<<client[i].month<<"/"<<client[i].year<< endl;
        cout << "\t\t\t\t\tCONTACT        : " << client[i].contact << endl;
        cout << "\t\t\t\t\tADDRESS        : " << client[i].address << endl;
        cout << "\t\t\t\t\tCASH           : " << client[i].cash << endl;
        cout << "\t\t\t\t\t**************************" << endl;
}

void Client::getdata()
{

    for (int i = 0; i < client.size(); i++)
    {
        cout << "\t\t\t\t\t*************************" << endl;
        cout << "\t\t\t\t\tDATA OF PERSON : " << i + 1 << endl;
        cout << "\t\t\t\t\tNAME           : " << client[i].name << endl;
        cout << "\t\t\t\t\tID             : " << client[i].ID << endl;
        cout << "\t\t\t\t\tDOB            : " << client[i].day<<"/"<<client[i].month<<"/"<<client[i].year<< endl;
        cout << "\t\t\t\t\tCONTACT        : " << client[i].contact << endl;
        cout << "\t\t\t\t\tADDRESS        : " << client[i].address << endl;
        cout << "\t\t\t\t\tCASH           : " << client[i].cash << endl;
        cout << "\t\t\t\t\t**************************" << endl;
    }
}
int Client::getClientCount() const
{
    return client_no;
}

bool Client::isEmpty()
{
    return client.empty();
}


Client::~Client()
{
//dtor
}

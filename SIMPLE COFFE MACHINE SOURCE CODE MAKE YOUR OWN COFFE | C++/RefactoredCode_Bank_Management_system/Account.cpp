#include "Account.h"
#include<iostream>
#include "Login.h"
#include "Client.h"
#include <windows.h>
#include <algorithm>

using namespace std;

Account::Account()
{
    //ctor
}

void Account::searching(Client& obj)
{
    int exist = obj.searchClient();
    if(exist != -1)
        obj.ViewClientDetail(exist);
    else
        cout<<"\t\t\t\t\tNo Record Found"<<endl;

}

void Account::transactions(Client& obj)
{
    char trans;
    int csh;

    int index = obj.searchClient();

    if (index != -1) {
        Client::Data& clientData = obj.client[index];
        cout << "\t\t\t\t\tData of Person at index: " << index + 1 << endl;
        cout << "\t\t\t\t\tNAME          : " << clientData.name << endl;
        cout << "\t\t\t\t\tCONTACT       : " << clientData.contact << endl;
        cout << "\t\t\t\t\tADDRESS       : " << clientData.address << endl;
        cout << "\t\t\t\t\tEXISTING CASH : " << clientData.cash << endl;
        cout << "\t\t\t\t\tPRESS 1 TO DEPOSIT " << endl;
        cout << "\t\t\t\t\tPRESS 2 TO WITHDRAW" << endl;
        cin >> trans;

        switch (trans)
        {
        case '1':
        {
            cout << "\t\t\t\t\tHOW MUCH CASH YOU WANT TO DEPOSIT : ";
            cin >> csh;
            obj.client[index].cash += csh;
            cout << "\t\t\t\t\tYOUR BALANCE NOW IS " << obj.client[index].cash << endl;
            break;
        }

        case '2':
        {
            cout << "\t\t\t\t\tHOW MUCH CASH YOU WANT TO WITHDRAW : ";
            cin >> csh;

            if (csh > clientData.cash)
            {
                theme.showLoadingAnimation();
                cout << "\t\t\t\t\tYOUR EXISTING CASH IS JUST : " << clientData.cash << endl;
            }
            else
            {
                obj.client[index].cash -= csh;
                cout << "\t\t\t\t\tWITHDRAWAL SUCCESSFUL. YOUR NEW BALANCE IS : " << obj.client[index].cash << endl;
            }
            break;
        }

        default:
        {
            cout << "\t\t\t\t\tInvalid Input" << endl;
            break;
        }
        }

        if (index == client_no - 1)
            cout << "\t\t\t\t\tNO SEARCH RECORD FOUND " << endl;
    }
    else {
        cout << "\t\t\t\t\tNO USER RECORD FOUND " << endl;
    }
}





void Account::del(Client& obj)
{
    char ch;

    cout << "PRESS 1 TO DELETE SPECIFIC RECORD " << endl;
    cout << "PRESS 2 TO DELETE ALL RECORDS " << endl;
    cin >> ch;

    switch (ch)
    {
    case '1':
    {
        int index = obj.searchClient();

        if (index != -1)
        {
            obj.client.erase(obj.client.begin() + index);
            cout << "\t\t\t\t\tYOUR REQUIRED DATA IS DELETED " << endl;
        }
        else
        {
            cout << "\t\t\t\t\tNO SEARCH RECORD FOUND" << endl;
        }
        break;
    }

    case '2':
    {
        obj.client.clear();
        cout << "\t\t\t\t\tALL RECORDS ARE DELETED " << endl;
        break;
    }

    default:
    {
        cout << "INVALID INPUT" << endl;
        break;
    }
    }
}

Account::~Account()
{
    //dtor
}

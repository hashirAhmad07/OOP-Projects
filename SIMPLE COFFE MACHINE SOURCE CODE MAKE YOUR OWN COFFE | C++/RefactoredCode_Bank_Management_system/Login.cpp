#include <iostream>
#include <windows.h>
#include "Login.h"

using namespace std;

Login::Login() {
    username = "admin";
    password = "123";
}

bool Login::login() {
    cout << "\n\t\t\t\t\tPLEASE SIGN IN FIRST" << endl;
    char choice = 'n';
    string userAttempt, passAttempt;

    cout << "\n\t\t\t\t\tENTER THE USERNAME:";
    cin >> userAttempt;
    cout << "\n\t\t\t\t\tPASSWORD:";
    cin >> passAttempt;

    if(userAttempt == username && passAttempt == password) {
        theme.showLoadingAnimation();
        cout<<"\t\t\t\t\tSuccessfully login to the system";
        Sleep(1000);
        theme.ClearScreen();
        return true;
    } else {
        cout << "\t\t\t\t\tInvalid Credential, Access Denied!" << endl;
    }
    return false;
}

void Login::Logout() {
    cout << "\t\t\t\t\tPRESS 1 TO LOGOUT FROM YOUR ACCOUNT :" << endl;
    int choice;
    cin >> choice;

    theme.showLoadingAnimation();
    theme.ClearScreen();

    if (choice == 1) {
        // Implement logout action if needed
        cout << "\t\t\t\t\tSUCCESSFULLY LOGGED OUT " << endl;
    } else {
        cout << "\t\t\t\t\tINVALID INPUT" << endl;
    }
}

Login::~Login() {
    // Destructor
}

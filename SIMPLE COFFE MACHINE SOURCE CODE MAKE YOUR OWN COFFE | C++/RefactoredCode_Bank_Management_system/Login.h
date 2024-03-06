#ifndef LOGIN_H
#define LOGIN_H

#include "Client.h"
#include "Theme.h"
#include <string>

class Login
{
public:
    Login();
    bool login();
    void Logout();
    void showLoadingAnimation();
    void ClearScreen();
    virtual ~Login();

protected:

private:
    std::string username = "admin";
    std::string password = "123";
    Theme theme;
};

#endif // LOGIN_H

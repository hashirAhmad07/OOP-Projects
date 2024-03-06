#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Login.h"
#include "Theme.h"



class Client
{
public:
    struct Data
    {
        std::string name, address, ID, username;
        long long int cash, contact;
        std::string password;
        int day, month, year;
    };

    std::vector<Data> client;

    Client();
    void setdata();
    void setCredential(Data& clients);
    void Register();
    void getdata();
    void update();
    int searchClient();
    void ViewClientDetail(int);

    int getClientCount() const;
    bool isEmpty();
    virtual ~Client();

protected:
    int client_no;
    std::string id;
    char load = 219;
    bool registration;
private:
    Theme theme;


};

#endif // CLIENT_H

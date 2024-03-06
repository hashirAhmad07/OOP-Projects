#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Login.h"
#include "Client.h"
#include "ChoiceHandler.h"
#include <vector>

class Bank : public Account, public Login
{
    public:
        Bank(std::vector<Client::Data>& clients);
        void choice();

        virtual ~Bank();

    protected:

    private:
    Login loginManager;
    ChoiceHandler choiceHandler;
    char ch;
     std::vector<Client::Data>& clients;

};

#endif // BANK_H

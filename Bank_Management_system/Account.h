#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Client.h"
#include <string>

class Account : public Client
{
    public:
        Account();
        void searching(Client& );
        void transactions(Client& );
        void del(Client&);
        virtual ~Account();

    protected:

    private:
        std::string id;
        Theme theme;
};

#endif // ACCOUNT_H

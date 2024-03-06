#ifndef CHOICEHANDLER_H
#define CHOICEHANDLER_H

#include "Account.h"
#include "Client.h"
#include <vector>
#include "Theme.h"


class ChoiceHandler {
public:
    ChoiceHandler();
    void handleChoice(std::vector<Client::Data>&);
    void processChoice(const std::vector<Client::Data>&);
    void displayMenu();
    virtual ~ChoiceHandler();

protected:

private:
    char ch;
    Account account;
    Login loginManager;
    Theme theme;
    static Client obj;
};

#endif // CHOICEHANDLER_H

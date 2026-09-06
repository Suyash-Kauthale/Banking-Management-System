#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

#include "Account.h"

// Holds all the accounts and does the banking operations.
// Notice: no cout / cin anywhere in this class - printing is main's job.
class Bank {
private:
    std::vector<Account*> accounts;   // pointers to base class
    int nextNumber;

public:
    Bank();
    ~Bank();     // deletes every account we created with new

    // type: 1 = Savings, 2 = Current. Returns NULL if it failed.
    Account* openAccount(int type, std::string name, double amount);

    Account* findAccount(std::string id);

    bool deposit (std::string id, double amount);
    bool withdraw(std::string id, double amount);
    bool transfer(std::string fromId, std::string toId, double amount);

    std::vector<Account*> getAllAccounts() const;
    double getTotalBalance() const;
};

#endif

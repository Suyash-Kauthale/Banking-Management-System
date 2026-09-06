#include "Bank.h"

Bank::Bank() {
    nextNumber = 1001;
}

// Destructor: every "new" needs a matching "delete"
Bank::~Bank() {
    for (unsigned int i = 0; i < accounts.size(); i++) {
        delete accounts[i];
    }
    accounts.clear();
}

Account* Bank::openAccount(int type, std::string name, double amount) {
    if (name == "" || amount < 0) {
        return NULL;
    }

    // Savings accounts need Rs 1000 to open
    if (type == 1 && amount < 1000) {
        return NULL;
    }

    std::string id;
    if (type == 1) {
        id = "SAV" + std::to_string(nextNumber);
    } else if (type == 2) {
        id = "CUR" + std::to_string(nextNumber);
    } else {
        return NULL;
    }
    nextNumber++;

    Account* acc;
    if (type == 1) {
        acc = new SavingsAccount(id, name, amount);
    } else {
        acc = new CurrentAccount(id, name, amount);
    }

    accounts.push_back(acc);
    return acc;
}

Account* Bank::findAccount(std::string id) {
    for (unsigned int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getId() == id) {
            return accounts[i];
        }
    }
    return NULL;
}

bool Bank::deposit(std::string id, double amount) {
    Account* acc = findAccount(id);
    if (acc == NULL) {
        return false;
    }
    return acc->deposit(amount);
}

bool Bank::withdraw(std::string id, double amount) {
    Account* acc = findAccount(id);
    if (acc == NULL) {
        return false;
    }
    // The correct withdraw() runs depending on the real account type
    return acc->withdraw(amount);
}

bool Bank::transfer(std::string fromId, std::string toId, double amount) {
    if (fromId == toId) {
        return false;
    }

    Account* from = findAccount(fromId);
    Account* to   = findAccount(toId);

    if (from == NULL || to == NULL) {
        return false;
    }

    if (!from->withdraw(amount)) {
        return false;          // nothing has moved yet
    }

    if (!to->deposit(amount)) {
        from->deposit(amount); // put the money back
        return false;
    }

    return true;
}

std::vector<Account*> Bank::getAllAccounts() const {
    return accounts;
}

double Bank::getTotalBalance() const {
    double total = 0;
    for (unsigned int i = 0; i < accounts.size(); i++) {
        total += accounts[i]->getBalance();
    }
    return total;
}

#include "Account.h"
using namespace std;

// Static member must be defined once, outside the class
int Account::totalAccounts = 0;

// ---------------- Account (base) ----------------

Account::Account(::string id, ::string name, double balance) {
    this->id      = id;
    this->name    = name;
    this->balance = balance;
    totalAccounts++;
}

Account::~Account() {
    totalAccounts--;
}

bool Account::deposit(double amount) {
    if (amount <= 0) {
        return false;
    }
    balance += amount;
    return true;
}

// Default rule: cannot withdraw more than the balance
bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}

// interestRate() is pure virtual, so the correct child version runs here.
// This is run-time polymorphism.
double Account::calculateInterest() const {
    return balance * interestRate() / 100.0;
}

int Account::getTotalAccounts() {
    return totalAccounts;
}


// ---------------- SavingsAccount ----------------

SavingsAccount::SavingsAccount(::string id, ::string name, double balance)
    : Account(id, name, balance) {
    // base constructor runs first
}

double SavingsAccount::interestRate() const {
    return 4.0;
}

::string SavingsAccount::type() const {
    return "Savings";
}

// Overriding: must leave at least Rs 1000 in the account
bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        return false;
    }
    if (balance - amount < 1000) {
        return false;
    }
    balance -= amount;
    return true;
}


// ---------------- CurrentAccount ----------------

CurrentAccount::CurrentAccount(::string id, ::string name, double balance)
    : Account(id, name, balance) {
}

double CurrentAccount::interestRate() const {
    return 0.0;
}

::string CurrentAccount::type() const {
    return "Current";
}

// Overriding: allowed to go negative, up to an overdraft of Rs 10000
bool CurrentAccount::withdraw(double amount) {
    if (amount <= 0) {
        return false;
    }
    if (balance - amount < -10000) {
        return false;
    }
    balance -= amount;
    return true;
}

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;
// Abstract base class.
// You cannot create an "Account" directly - only a Savings or Current one.
class Account {
protected:
    string id;
    string name;
    double balance;

    static int totalAccounts;   // shared by ALL accounts

public:
    Account(string id, string name, double balance);
    virtual ~Account();         // virtual = important, see note in README

    // Pure virtual: every child class MUST write its own version
    virtual double interestRate() const = 0;
    virtual string type() const = 0;

    // Virtual: child classes may replace this
    virtual bool withdraw(double amount);

    bool deposit(double amount);
    double calculateInterest() const;

    // Getters
    string getId() const { return id; }
    string getName() const { return name; }
    double getBalance() const { return balance; }

    // Static member function
    static int getTotalAccounts();
};


// Savings: earns 4% interest, must always keep Rs 1000
class SavingsAccount : public Account {
public:
    SavingsAccount(string id, string name, double balance);

    double interestRate() const;
    string type() const;
    bool withdraw(double amount);
};


// Current: no interest, can go negative up to Rs 10000
class CurrentAccount : public Account {
public:
    CurrentAccount(string id, string name, double balance);

    double interestRate() const;
    string type() const;
    bool withdraw(double amount);
};

#endif

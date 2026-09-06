#include <iomanip>
#include <iostream>

#include "Bank.h"

using namespace std;

void showMenu() {
    cout << "\n----------------------------------------\n";
    cout << " 1. Open account\n";
    cout << " 2. Deposit\n";
    cout << " 3. Withdraw\n";
    cout << " 4. Transfer\n";
    cout << " 5. View account\n";
    cout << " 6. List all accounts\n";
    cout << " 7. Bank summary\n";
    cout << " 0. Exit\n";
    cout << "----------------------------------------\n";
    cout << "Choice: ";
}

void openAccount(Bank& bank) {
    string name;
    int    type;
    double amount;

    cout << "\nHolder name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Type (1 = Savings, 2 = Current): ";
    cin >> type;

    cout << "Opening amount: ";
    cin >> amount;

    Account* acc = bank.openAccount(type, name, amount);

    if (acc == NULL) {
        cout << "\nCould not open account.";
        cout << " (Savings needs at least Rs 1000)\n";
    } else {
        cout << "\nAccount created!\n";
        cout << "ID      : " << acc->getId() << "\n";
        cout << "Type    : " << acc->type() << "\n";
        cout << "Balance : Rs " << acc->getBalance() << "\n";
    }
}

void deposit(Bank& bank) {
    string id;
    double amount;

    cout << "\nAccount ID: ";
    cin >> id;
    cout << "Amount: ";
    cin >> amount;

    if (bank.deposit(id, amount)) {
        cout << "\nDeposited. New balance: Rs "
             << bank.findAccount(id)->getBalance() << "\n";
    } else {
        cout << "\nDeposit failed. Check the ID and the amount.\n";
    }
}

void withdraw(Bank& bank) {
    string id;
    double amount;

    cout << "\nAccount ID: ";
    cin >> id;
    cout << "Amount: ";
    cin >> amount;

    if (bank.withdraw(id, amount)) {
        cout << "\nWithdrawn. New balance: Rs "
             << bank.findAccount(id)->getBalance() << "\n";
    } else {
        cout << "\nWithdrawal declined.";
        cout << " (Savings must keep Rs 1000, Current limit is -Rs 10000)\n";
    }
}

void transfer(Bank& bank) {
    string fromId, toId;
    double amount;

    cout << "\nFrom account ID: ";
    cin >> fromId;
    cout << "To account ID: ";
    cin >> toId;
    cout << "Amount: ";
    cin >> amount;

    if (bank.transfer(fromId, toId, amount)) {
        cout << "\nTransfer done.\n";
        cout << fromId << " : Rs " << bank.findAccount(fromId)->getBalance() << "\n";
        cout << toId   << " : Rs " << bank.findAccount(toId)->getBalance()   << "\n";
    } else {
        cout << "\nTransfer failed.\n";
    }
}

void viewAccount(Bank& bank) {
    string id;
    cout << "\nAccount ID: ";
    cin >> id;

    Account* acc = bank.findAccount(id);

    if (acc == NULL) {
        cout << "\nNo account with that ID.\n";
        return;
    }

    cout << "\nID              : " << acc->getId() << "\n";
    cout << "Holder          : " << acc->getName() << "\n";
    cout << "Type            : " << acc->type() << "\n";
    cout << "Balance         : Rs " << acc->getBalance() << "\n";
    cout << "Interest rate   : " << acc->interestRate() << " %\n";
    cout << "Yearly interest : Rs " << acc->calculateInterest() << "\n";
}

void listAccounts(Bank& bank) {
    vector<Account*> all = bank.getAllAccounts();

    cout << "\n";
    if (all.size() == 0) {
        cout << "No accounts yet.\n";
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(18) << "HOLDER"
         << setw(10) << "TYPE"
         << right << setw(12) << "BALANCE" << "\n";
    cout << string(50, '-') << "\n";

    /* Every item is an Account*, but type() gives the correct
     answer for each one. That is polymorphism.
    */
    for (unsigned int i = 0; i < all.size(); i++) {
        cout << left << setw(10) << all[i]->getId()
             << setw(18) << all[i]->getName()
             << setw(10) << all[i]->type()
             << right << setw(12) << all[i]->getBalance() << "\n";
    }
}

void summary(Bank& bank) {
    cout << "\nTotal accounts : " << Account::getTotalAccounts() << "\n";
    cout << "Total balance  : Rs " << bank.getTotalBalance() << "\n";
}

int main() {
    Bank bank;

    // Some accounts to start with, so there is something to show
    bank.openAccount(1, "Rohan Deshmukh", 25000);
    bank.openAccount(1, "Aditi Kulkarni", 8500);
    bank.openAccount(2, "Shreyas Traders", 12000);

    cout << fixed << setprecision(2);
    cout << "\n========================================\n";
    cout << "     BANK MANAGEMENT SYSTEM\n";
    cout << "========================================\n";

    int choice = -1;

    while (choice != 0) {
        showMenu();

        if (!(cin >> choice)) {   // user typed letters
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nPlease enter a number from the menu.\n";
            continue;
        }

        switch (choice) {
            case 1: openAccount(bank);  break;
            case 2: deposit(bank);      break;
            case 3: withdraw(bank);     break;
            case 4: transfer(bank);     break;
            case 5: viewAccount(bank);  break;
            case 6: listAccounts(bank); break;
            case 7: summary(bank);      break;
            case 0: cout << "\nGoodbye.\n"; break;
            default: cout << "\nWrong choice.\n";
        }
    }

    return 0;
}

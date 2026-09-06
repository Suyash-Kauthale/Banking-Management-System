# Bank Management System — Simple Version

CS2303 Object Oriented Programming — Course Project


## Build

**Windows:**
```
g++ -std=c++11 -Wall main.cpp Account.cpp Bank.cpp -o bank.exe
bank.exe
```

**Linux / Mac:**
```
g++ -std=c++11 -Wall main.cpp Account.cpp Bank.cpp -o bank
./bank
```


## Files

| File | What is in it |
|---|---|
| `Account.h` / `.cpp` | `Account` (abstract), `SavingsAccount`, `CurrentAccount` |
| `Bank.h` / `.cpp` | holds all accounts, does deposit / withdraw / transfer |
| `main.cpp` | the menu — all `cout` and `cin` live here |

`Account` and `Bank` contain **no `cout` and no `cin`**.
They return values, and `main.cpp` decides what to print.

## OOP concepts and where they are

| Concept | Where |
|---|---|
| Class, private data, public functions | `Account`, `Bank` |
| Constructor | `Account::Account()`, both child classes |
| Destructor | `Account::~Account()`, `Bank::~Bank()` |
| Static data member | `Account::totalAccounts` |
| Static member function | `Account::getTotalAccounts()` |
| Abstract class + pure virtual | `interestRate()`, `type()` in `Account` |
| Inheritance | `SavingsAccount` and `CurrentAccount` from `Account` |
| Function overriding | `withdraw()` in both child classes |
| Run-time polymorphism | `calculateInterest()`, and the list in option 6 |
| Base class pointer | `vector<Account*>` in `Bank` |
| `new` and `delete` | `Bank::openAccount()` and `Bank::~Bank()` |

## Demo order

1. Option **6** — three accounts, each showing its own type
2. Option **3**, `SAV1002`, `8000` — **declined**, savings must keep Rs 1000
3. Option **3**, `CUR1003`, `20000` — **allowed**, current can go to -Rs 10000
4. Option **5**, `SAV1001` — 4% interest; then `CUR1003` — 0%
5. Option **4** — transfer between two accounts
6. Option **7** — total from the static member


## Not built yet

File saving, login, Fixed Deposit accounts, transaction history.

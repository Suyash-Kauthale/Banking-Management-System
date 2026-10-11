# Online Bank Management System

Course project for **CS2303 Object Oriented Programming (C++)**,
Vishwakarma Institute of Technology, Pune.

A console-based bank management system written in C++ that demonstrates the core
concepts of object-oriented programming: classes, encapsulation, inheritance,
run-time polymorphism, operator overloading, file handling, exception handling and
templates.

> **Status:** M0 — project setup. Code is being added milestone by milestone.

## Features

Planned features. Each one is ticked when its milestone is complete.

- [ ] Savings and Current accounts with their own withdrawal rules
- [ ] Open and close accounts, deposit, withdraw and transfer
- [ ] Customers linked to their accounts
- [ ] Transaction history and mini statement
- [ ] Accounts sorted by balance
- [ ] Data saved to files and loaded again on startup
- [ ] Login with Admin and Customer roles
- [ ] Fixed Deposit account with lock-in period and early-withdrawal penalty
- [ ] Clear error messages for every invalid input (exception handling)
- [ ] Interest posting and admin report

## System Architecture

```
   ConsoleUI            menus and input — the only class that uses cin/cout
      │
      ▼
   Bank                 banking logic
      │ owns ──▶ Accounts, Customers, Transactions
      │                Account (abstract)
      │                  ├── SavingsAccount
      │                  ├── CurrentAccount
      │                  └── FixedDepositAccount
      ▼
   Storage (abstract)   saving and loading data
      └── FileStorage   text and binary files
```

The banking classes never print anything; they return results and the user
interface decides what to display. Storage is behind an abstract class, so the way
data is saved can change without touching the banking logic.

## Milestones

| Milestone | Work | Syllabus units |
|---|---|---|
| M0 | Setup, repository, architecture | — |
| M1 | `Account` hierarchy (abstract base, Savings, Current) | 1, 2, 4 |
| M2 | `Bank` class, console menu, input validation | 2, 4 |
| M3 | `Customer` and `Transaction` classes, mini statement | 2, 3 |
| M4 | `Date` class, operator overloading, friend functions, sorting | 3 |
| M5 | File handling — text and binary files, file pointers | 5 |
| M6 | Login, Admin and Customer roles, Fixed Deposit account | 4, 6 |
| M7 | Exceptions, templates, SOLID principles | 6 |
| M8 | Hardening and testing | — |
| M9 | Documentation and submission | — |

## Requirements

- Windows
- g++ (MinGW), C++11 or later
- No external libraries — standard library only

## Build and Run

The build command will be kept in `build.bat` once the first source files are added.
From Command Prompt in the project folder:

```
build.bat
bank.exe
```

## Documentation

The `docs/` folder is kept up to date as each milestone is finished:

- `concept_map.md` — each OOP concept and where it appears in the code
- `testing.md` — test cases with expected and actual results
- UML class diagram

## Team

Team members will be listed here.

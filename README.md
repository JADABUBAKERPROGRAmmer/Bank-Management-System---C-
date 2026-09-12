# Bank Management System - C++

A simple **Bank Management System** built using **C++**.

This is the second version of the project. It includes client management features as well as basic banking transactions such as **Deposit** and **Withdraw**.

## Features

### Client Management

* Show all clients
* Add new clients
* Delete clients
* Update client information
* Find a client by account number

### Transactions

* Deposit money
* Withdraw money
* Check the current balance during transactions
* Prevent withdrawal when the balance is insufficient

## Client Information

Each client contains:

* Account Number
* Pin Code
* Name
* Phone
* Account Balance

## Technologies Used

* C++
* `fstream`
* `vector`
* `string`
* `struct`
* Functions
* File Handling
* String Manipulation

## Data Storage

Client information is stored in:

`fileclientslist.txt`

The data is separated using the delimiter:

`#//#`

## Project Concepts

This project demonstrates practical use of:

* Structures
* Functions
* Vectors
* File Handling
* Reading and writing files
* Searching
* Updating data
* Deleting data
* String manipulation
* `stoi()` and `to_string()`
* Menu-driven programming

## Transactions

The transaction menu provides two operations:

```text
[1] Deposit
[2] Withdraw
[3] Back to main menu
```

### Deposit

The user enters an account number and the amount to deposit. The amount is added to the client's current balance.

### Withdraw

The user enters an account number and the amount to withdraw. The program checks whether the client has enough balance before completing the withdrawal.

## Project Purpose

The purpose of this project is to practice C++ programming and gradually build a more complete Bank Management System using file handling and data structures.

## Version History

### Version 1

Client management features:

* Add
* Show
* Search
* Delete
* Update

### Version 2

Added:

* Transactions
* Deposit
* Withdraw
* Balance updates

## Future Updates

Possible future improvements:

* Transfer money between accounts
* Transaction history
* Login system
* Admin authentication
* Better input validation
* More banking operations

## Author

Jad Abubaker

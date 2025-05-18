#include <iostream>
#include <vector>
#include "Account.h"
#include <fstream>
#include <sstream>
using namespace std;

int FindAccountById(const vector<Account>& accounts, int id) {
    for (int i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void SaveAccounts(const vector<Account>& accounts) {
    ofstream outFile("accounts.txt");

    for (const Account& acc : accounts) {
        outFile << acc.getName() << ","
                << acc.getId() << ","
                << acc.getPassword() << ","
                << acc.getBalance() << "\n";
    }

    outFile.close();
}

void LoadAccounts(vector<Account>& accounts) {
    ifstream inFile("accounts.txt");
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, password, idStr, balanceStr;

        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, password, ',');
        getline(ss, balanceStr, ',');

        int id = stoi(idStr);
        double balance = stod(balanceStr);

        accounts.push_back(Account(name, id, password, balance));
    }

    inFile.close();
}

int main() {
    string inputPassword;
    bool running = true;
    vector<Account> accounts;
    int loggedInIndex = -1;
    LoadAccounts(accounts);


    while (running) {

       if (loggedInIndex == -1) {
        cout << "\n===== Main Menu (Not Logged In) =====\n";
        cout << "1. Create New Account\n";
        cout << "2. Log In\n";
        cout << "3. Exit\n";
       } else {
        cout << "\n===== Welcome, " << accounts[loggedInIndex].getName() << " =====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. View Account Info\n";
        cout << "4. Log Out\n";
       }

       cout << "Choose an option: ";
       int choice;
       cin >> choice;

       while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> choice;
       }

       if (loggedInIndex == -1) {
        switch (choice) {
            case 1: {
                string name, password;
                int id;
                double balance;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter an ID number: ";
                cin >> id;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter starting balance: ";
                cin >> balance;

                accounts.push_back(Account(name, id, password, balance));
                cout << "Account created successfully \n";
                break;
            }
        

            case 2: {
                int id; 

                cout << "Enter your account ID: ";
                cin >> id;
                int index = FindAccountById(accounts, id);

                if (index == -1) {
                    cout << "Account not found.\n";
                    break;
                }

                cout << "Enter password: ";
                cin >> inputPassword;

                if (accounts[index].checkPassword(inputPassword)) {
                    loggedInIndex = index;
                    cout << "Login successful! Welcome, " << accounts[index].getName() << ".\n";
                } else {
                    cout << "incorrect password.\n";
                }
            } break;

            case 3: {
                cout << "Exiting...\n";
                SaveAccounts(accounts);
                running = false;
            } break;

            default: 
                cout << "Invalid choice\n";
            }
        }

        else {
          switch (choice) {
            case 1: {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                accounts[loggedInIndex].deposit(amount);
                cout << "Deposit successful.\n";
            } break;

            case 2: {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                if (accounts[loggedInIndex].withdraw(amount)) {
                    cout << "Withdrawal successful.\n";
                } else {
                    cout << "Insufficient funds.\n";
                }
            } break;

            case 3: {
                cout << "Name: " << accounts[loggedInIndex].getName() << "\n";
                cout << "ID: " << accounts[loggedInIndex].getId() << "\n";
                cout << "Balance: $" << accounts[loggedInIndex].getBalance() << "\n";
            } break;

            case 4: {
                cout << "Logged out successfully.\n";
               loggedInIndex = -1;
            } break;

        default:
            cout << "Invalid choice.\n";
            }
        }
    }

    return 0;
}
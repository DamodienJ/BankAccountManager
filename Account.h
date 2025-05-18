#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private: 
    std::string name;
    int id;
    std::string password;
    double balance;

public:
    Account();
    Account(std::string name, int id, std::string password, double balance);

    std::string getName() const;
    int getId() const;
    double getBalance() const;
    std::string getPassword() const;
    bool checkPassword(const std::string& input) const;

    void deposit(double amount);
    bool withdraw(double amount);
};

#endif

#include "Account.h"

Account::Account() : name(""), id(0), password(""), balance(0.0) {}

Account::Account(std::string name, int id, std::string password, double balance)
    : name(name), id(id), password(password), balance(balance) {}

std::string Account::getName() const {
    return name;
}

int Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getPassword() const {
    return password;
}

bool Account::checkPassword(const std::string& input) const {
    return input == password;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}
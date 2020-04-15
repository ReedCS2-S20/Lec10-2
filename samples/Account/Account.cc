#include <iostream>
#include <string>
#include "Account.hh"

long Account::gNextNumber = 100000000;

std::string money_format(double amount) {
  std::string s = std::to_string(amount);
  std::string ms {"$"};
  bool saw_period {false};
  int fraction_digits = 0;
  for (char c:s) { 
    if (saw_period) {
      if (fraction_digits < 2) {
	fraction_digits++;
	ms += c;
      }
    } else {
      if (c == '.') {
	saw_period = true;
      }
      ms += c;
    }
  }
  return ms;
}

Account::Account(std::string name, double amount, double interest) :
  name {name},
  balance {amount},
  rate {interest},
  number {Account::gNextNumber++}
{ }

double Account::getBalance() const {
  return balance;
}

std::string Account::getName() const {
  return name;
}

long Account::getNumber() const {
  return number;
}

double Account::getRate() const {
  return rate;
}

void Account::deposit(double amount) {
  balance += amount;
}

void Account::gainInterest() {
  deposit(rate * balance);
}

double Account::withdraw(double amount) {
  if (amount > balance) {
    amount = balance;
    balance = 0.0;
  } else {
    balance -= amount;
  }
  return amount;
}

std::ostream& operator<<(std::ostream& os, const Account& acct) {
  os << "[" << acct.getName() << "-" << acct.getNumber() << ": " << money_format(acct.getBalance()) << "]";
  return os;
}

Savings::Savings(std::string name, double amount) :
  Account {name,amount,0.02}, penalty {50.0}
{ }

double Savings::withdraw(double amount) {
  double howmuch = Account::withdraw(amount);
  Account::withdraw(penalty);
  return howmuch;
}

Checking::Checking(std::string name, double amount) :
  Account {name, amount, 0.01}, level {1000.0}
{ }

void Checking::gainInterest() {
  if (balance >= level) {
    Account::gainInterest();
  }
}

Promotional::Promotional(std::string name, double amount) :
  Checking {name, amount + 100.0}
{ 
  rate = 0.07;
  level = 100.0;
}




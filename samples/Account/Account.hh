#include <iostream>
#include <string>

class Account {
private:
  static long gNextNumber;
protected:
  std::string name;
  long number;
  double balance;
  double rate;
public:
  Account(std::string name, double amount, double interest);
  virtual double getBalance() const;
  virtual std::string getName() const;
  virtual long getNumber() const;
  virtual double getRate() const;
  virtual void deposit(double amount);
  virtual void gainInterest();
  virtual double withdraw(double amount);
  friend std::ostream& operator<<(std::ostream& os, const Account& acct);
};

class Savings : public Account {
protected:
  double penalty;
public:
  Savings(std::string name, double amount);
  double withdraw(double amount);
};

class Checking : public Account {
protected:
  double level;
public:
  Checking(std::string name, double amount);
  void gainInterest();
};

class Promotional : public Checking {
public:
  Promotional(std::string name, double amount);
};


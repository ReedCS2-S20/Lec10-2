#include <iostream>
#include <string>
#include "Account.hh"

int main() {
  std::cout << "Opening a checking account.\n";
  Savings sAcct {"my savings",100.0};
  std::cout << "Opening a savings account.\n";
  Checking cAcct {"my checking",1000.0};
  // Promotional cAcct {"my special checking",0.0};

  std::string entry;
  do {
    std::cout << sAcct << "\n";
    std::cout << cAcct << "\n";
    std::cout << "\n";
    std::cout << "Enter [d]eposit, [w]ithdraw, [m]onth, [q]uit: ";
    std::cin >> entry;
    std::string which;
    double amt;
    if (entry == "d" || entry == "w") {
      std::cout << "Enter amount: ";
      std::cin >> amt;
      std::cout << "Enter [c] or [s]: ";
      std::cin >> which;
      Account* ap;
      if (which == "c") {
	ap = &cAcct;
      } else {
	ap = &sAcct;
      }
      if (entry == "w") {
	ap->withdraw(amt);
      } else {
	ap->deposit(amt);
      }
    } else if (entry == "m") {
      cAcct.gainInterest();
      sAcct.gainInterest();
    }
  } while (entry != "q");
}

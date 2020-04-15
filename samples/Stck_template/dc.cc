
#include <iostream>
#include <string>
#include "Stck_T.hh"

int main() {

  Stck<int> s(100);

  std::string entry;
  do {
    std::cin >> entry;
    if (entry == "+") {
      int v1 = s.pop();
      int v2 = s.pop();
      int v = v1 + v2;
      s.push(v);
    } else if (entry == "-") {
      int v1 = s.pop();
      int v2 = s.pop();
      int v = v1 - v2;
      s.push(v);
    } else if (entry == "*") {
      int v1 = s.pop();
      int v2 = s.pop();
      int v = v1 * v2;
      s.push(v);
    } else if (entry == "/") {
      int v1 = s.pop();
      int v2 = s.pop();
      int v = v1 / v2;
      s.push(v);
    } else if (entry == "d") {
      s.push(s.top());
    } else if (entry == "++") {
      s.push(s.pop()+1);
    } else if (entry == "--") {
      s.push(s.pop()-1);
    } else if (entry == "t") {
      std::cout << std::to_string(s.top()) << std::endl;
    } else if (entry == "p") {
      std::cout << s.to_string() << std::endl;
    } else if (entry != "q") {
      int v = std::stoi(entry);
      s.push(v);
    }
  } while (entry != "q");
}

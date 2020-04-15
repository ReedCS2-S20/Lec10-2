#include <string>

template <class X>
class Stck {

private:
  int capacity;
  int num_elements;
  X *elements;

public:  
  Stck(const int size);
  const bool is_empty() const;
  void push(const X value);
  X pop();
  const X top() const;
  const std::string to_string() const;
  ~Stck();
};

template <class X>
Stck<X>::Stck(const int size) :
  capacity {size},
  num_elements{0},
  elements {new X[size]}
{ }

template <class X>
const bool Stck<X>::is_empty() const {
  return (num_elements == 0);
}

template <class X>
void Stck<X>::push(const X value) {
  elements[num_elements] = value;
  num_elements++;
}  

template <class X>
X Stck<X>::pop() {
  num_elements--;
  return elements[num_elements];
}  

template <class X>
const X Stck<X>::top() const {
  return elements[num_elements-1];
}  

template <class X>
const std::string Stck<X>::to_string() const {
  if (is_empty()) {
    return "[ ]";
  } else {
    int i = num_elements-1;
    std::string ss = "[("+std::to_string(elements[i])+")";
    i--;
    while (i >= 0) {
      ss += " "+std::to_string(elements[i]);
      i--;
    }
    return ss + "]";
  }
}

template <class X>
Stck<X>::~Stck() {
  delete [] elements;
}






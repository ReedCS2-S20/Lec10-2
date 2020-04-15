#include <cmath>
#include <iostream>
#include <string>

class Rectangle;

class Shape {
public:
  virtual double perimeter(void) const = 0;
  virtual double area(void) const = 0;
  virtual void print(void) const = 0;
  virtual double getHeight(void) const = 0;
  virtual double getWidth(void) const = 0;
  virtual void scale(double factor) = 0;
  Rectangle bounds(void);
};

class Circle : public Shape {
private:
  double radius;
public:
  Circle(double r) : radius(r) { }
  double perimeter(void) const { return 2.0 * M_PI * radius; } 
  double area(void) const { return M_PI * radius * radius; } 
  void print(void) const;
  double getHeight(void) const { return 2.0 * radius; }
  double getWidth(void) const { return 2.0 * radius; }
  void scale(double factor) { radius *= factor;}
};

class Rectangle : public Shape {
private:
  double width;
  double height;
  void depict(void) const;
public:
  Rectangle(double w,double h) : width(w), height(h) { }
  double perimeter(void) const { return 2.0 * (width + height); } 
  double area(void) const { return width * height; } 
  void print(void) const;
  double getHeight(void) const { return height; }
  double getWidth(void) const { return width; }
  void scale(double factor) { width *= factor; height *= factor;}

  friend class Square;
};

class Square : public Rectangle {
public:
  Square(double s) : Rectangle {s, s} { }
  void print(void) const;
};


Rectangle Shape::bounds(void) { return Rectangle {getWidth(),getHeight()}; }

void Circle::print(void) const {
  std::cout << "Here is a circle with radius " << radius << ":\n" << std::endl;
  int w = static_cast<int>(ceil(getWidth()));
  if (w == 1) {
    std::cout << "+" << std::endl;
    return;
  }
  if (w == 2) {
    std::cout << "++" << std::endl;
    std::cout << "++" << std::endl;
    return;
  }
  int hw = w/2;
  int r;
  std::string L;
  std::string R;
  for (r=hw; r>=1; r--) {
    L = "";
    R = "";
    int n = ceil(sqrt(radius*radius-static_cast<double>((r-1)*(r-1))));
    for (int i=0; i<hw; i++) {
      if (i < n) {
	L = "+" + L;
	R = R + "+";
      } else {
	L = " " + L;
	R = R + " ";
      }
    }
    if (w % 2 == 1) {
      std::cout << L << "+" << R << std::endl;
    } else {
      std::cout << L << R << std::endl;
    }
  }
  if (w % 2 == 1) {
    std::string M = "";
    for (int i=0; i<w; i++) {
      M += "+";
    }
    std:: cout << M << std::endl;
  }
  for (r=1; r<=hw; r++) {
    L = "";
    R = "";
    int n = ceil(sqrt(radius*radius-static_cast<double>((r-1)*(r-1))));
    for (int i=0; i<hw; i++) {
      if (i < n) {
	L = "+" + L;
	R = R + "+";
      } else {
	L = " " + L;
	R = R + " ";
      }
    }
    if (w % 2 == 1) {
      std::cout << L << "+" << R << std::endl;
    } else {
      std::cout << L << R << std::endl;
    }
  }
  std::cout << std::endl;
}

void Rectangle::depict(void) const {
  int w = static_cast<int>(ceil(getWidth()));
  int h = static_cast<int>(ceil(getHeight()));
  std::string M = "";
  for (int i=0; i<w; i++) {
    M += "+";
  }
  for (int j=0; j<h; j++) {
    std::cout << M << std::endl;
  }
  std::cout << std::endl;
}

void Rectangle::print(void) const {
  std::cout << "Here is a " << width << "x" << height;
  std::cout << " rectangle:\n" << std::endl;
  depict();
}

void Square::print(void) const {
  std::cout << "Here is a " << getWidth() << "x" << getHeight();
  std::cout << " square:\n" << std::endl;
  Rectangle::depict();
}
  
int main(void) {
  Circle c {5.0};
  Rectangle r {8.0,5.0};
  Square s {4.5};
  c.print();
  r.print();
  s.print();
  Circle c1 {12.5};
  Rectangle r1 {18.0,1};
  Square s1 {2.0};
  c1.print();
  r1.print();
  s1.print();
}





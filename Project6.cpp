#include <iostream>
using namespace std;

class Complex {
    int real, img;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }

    void operator++() {
        real++;
        img++;
    }

    void operator--() {
        real--;
        img--;
    }

    Complex operator+(Complex c) {
        return Complex(real + c.real, img + c.img);
    }

    Complex operator-(Complex c) {
        return Complex(real - c.real, img - c.img);
    }

    void display() {
        cout << real << " + " << img << "i" << endl;
    }
};

int main() {
    Complex a(5, 3), b(4, 7), c;

    cout << "First number: ";
    a.display();

    ++a;
    cout << "After increment of a: ";
    a.display();

    --a;
    cout << "After decrement: ";
    a.display();

  cout << "Second number: ";
    b.display();

   ++b;
    cout << "After increment of b: ";
    b.display();

    --b;
    cout << "After decrement: ";
    b.display();

  cout<<"==== Operations ==== \n";
  
    c = a + b;
    cout << "Addition of a and b: ";
    c.display();

    c = a - b;
    cout << "Subtraction of a and b: ";
    c.display();

    return 0;
}
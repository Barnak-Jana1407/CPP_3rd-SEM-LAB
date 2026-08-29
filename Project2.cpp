#include <iostream>
using namespace std;

// Call by Value
void callByValue(int x) {
    x = x + 10;
    cout << "Inside Call by Value: " << x << endl;
}

// Call by Reference
void callByReference(int &x) {
    x = x + 10;
    cout << "Inside Call by Reference: " << x << endl;
}

int main() {
    int a, b;

    // User input
    cout << "Enter a number for Call by Value: ";
    cin >> a;

    cout << "Enter a number for Call by Reference: ";
    cin >> b;

    // Call by Value
    cout << "\n--- Call by Value ---" << endl;
    cout << "Before function call: " << a << endl;

    callByValue(a);

    cout << "After function call: " << a << endl;

    // Call by Reference
    cout << "\n--- Call by Reference ---" << endl;
    cout << "Before function call: " << b << endl;

    callByReference(b);

    cout << "After function call: " << b << endl;

    return 0;
}
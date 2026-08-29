#include <iostream>
#include <string>
using namespace std;

int main() {
    // Number Palindrome 
    int num, original, reversed = 0, remainder;

    cout << "Enter a number: ";
    cin >> num;

    original = num;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    if (original == reversed)
        cout << "Number is a palindrome." << endl;
    else
        cout << "Number is not a palindrome." << endl;


    // String Palindrome
    string str;
    bool palindrome = true;

    cout << "Enter a string: ";
    cin >> str;

    int n = str.length();

    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
        cout << "String is a palindrome." << endl;
    else
        cout << "String is not a palindrome." << endl;

    return 0;
}
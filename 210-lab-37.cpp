// COMSC-210 | Lab 37 | Noel Mier-Luna
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    string s = "536B9DFC93AF";
    cout << s << endl;
    int total = 0;
    for (int i = 0; i < s.length(); i++) { // This for loop will be used for sum_ascii function.
        total += (int) s[i]; // Iterates through each character of a string and adds ASCII value to total variable.
    }
    cout << total << endl;

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

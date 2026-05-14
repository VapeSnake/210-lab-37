// COMSC-210 | Lab 37 | Noel Mier-Luna
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(string s);

int main() {
    ifstream infile("lab-37-data-3.txt");
    if (!infile) { // Check if the file was opened successfully.
        cerr << "Error opening file!" << endl;
        return 1;
    }
    int grantTotal = 0; // Used to accumulate total sum of ASCII values for each string read from the file.
    while (infile) {
        string str;
        infile >> str;
        if (infile) { // Check if the read was successful.
            int asciiSum = sum_ascii(str); // Calculate the sum of ASCII values for the string.
            grantTotal += asciiSum; // Add the ASCII sum to the grand total.
        }
    }
    cout << "Grand Total of ASCII values: " << grantTotal << endl; // Correctly displays grand total of 69893419.

    return 0;
}
// Returns the sum of the ASCII values of the characters in the string s.
int sum_ascii(string s) {
    int sum = 0;
    for (char c : s) {
        sum += (int) c; // Add the ASCII value of each character to the sum.
    }
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

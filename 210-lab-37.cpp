// COMSC-210 | Lab 37 | Noel Mier-Luna
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(string s);

int main() {
    // Testing target test values with sum_ascii function.
    string target1 = "536B9DFC93AF"; // ASCII sum is 729
    string target2 = "1DA9D64D02A0"; // ASCII sum is 692
    string target3 = "666D109AA22E"; // ASCII sum is 683
    string target4 = "E1D2665B21EA"; // ASCII sum is 696

    cout << "ASCII sum of " << target1 << " is: " << sum_ascii(target1) << endl; // Showed correct ASCII sum for target1.
    // I miscounted, sums are correct.
    cout << "ASCII sum of " << target2 << " is: " << sum_ascii(target2) << endl;
    cout << "ASCII sum of " << target3 << " is: " << sum_ascii(target3) << endl;
    cout << "ASCII sum of " << target4 << " is: " << sum_ascii(target4) << endl; 



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

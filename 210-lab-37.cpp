// COMSC-210 | Lab 37 | Noel Mier-Luna
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(string s);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    // Testing target test values with sum_ascii function.
    string target1 = "536B9DFC93AF"; // ASCII sum is 729
    string target2 = "1DA9D64D02A0"; // ASCII sum is 694
    string target3 = "666D109AA22E"; // ASCII sum is 674
    string target4 = "E1D2665B21EA"; // ASCII sum is 681

    cout << "ASCII sum of " << target1 << " is: " << sum_ascii(target1) << endl; // Showed correct ASCII sum for target1.
    cout << "ASCII sum of " << target2 << " is: " << sum_ascii(target2) << endl; // Showed incorrect ASCII sum.
    cout << "ASCII sum of " << target3 << " is: " << sum_ascii(target3) << endl; // Showed incorrect ASCII sum.
    cout << "ASCII sum of " << target4 << " is: " << sum_ascii(target4) << endl; // Showed incorrect ASCII sum. Error caused likely by newline.



    return 0;
}

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

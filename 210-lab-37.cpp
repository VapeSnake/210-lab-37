// COMSC-210 | Lab 37 | Noel Mier-Luna
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// Changing to generate hash index.
int gen_hash_index(const string &s); // Passing string by reference to avoid unnecessary copying and const to prevent modification of the string.

int main()
{
    // Create our map. Hash index will be key, list of strings will be value.
    map<int, list<string>> hashMap;

    ifstream infile("lab-37-data-3.txt");
    if (!infile)
    { // Check if the file was opened successfully.
        cerr << "Error opening file!" << endl;
        return 1;
    }
    while (infile)
    {
        string str;
        infile >> str;
        if (infile)
        {                                        // Check if the read was successful.
            int hashIndex = gen_hash_index(str); // Generates hash index for the string.
            hashMap[hashIndex].push_back(str);   // Insert the string into the list associated with the hash index.
        }
    }
    infile.close(); // Close the file after reading.

    return 0;
}
// Now generates a hash index using modulo to ensure the index fits within a certain range.
int gen_hash_index(const string &s)
{
    const int HASH_SIZE = 105; // Define a hash size to limit the range of hash indices. Using a little over 100 for part 3.
    int sum = 0;
    for (char c : s)
    {
        sum += (int)c; // Add the ASCII value of each character to the sum.
    }
    return sum % HASH_SIZE; // Return the hash index within the defined range.
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

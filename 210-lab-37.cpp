// COMSC-210 | Lab 37 | Noel Mier-Luna
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// Changing to generate hash index.
int gen_hash_index(const string & s); // Passing string by reference to avoid unnecessary copying and const to prevent modification of the string.

int main() {
    // Create our map. Hash index will be key, list of strings will be value.
    map < int, list < string >> hashMap;

    ifstream infile("lab-37-data-3.txt");
    if (!infile) { // Check if the file was opened successfully.
        cerr << "Error opening file!" << endl;
        return 1;
    }
    while (infile) {
        string str;
        infile >> str;
        if (infile) { // Check if the read was successful.
            int hashIndex = gen_hash_index(str); // Generates hash index for the string.
            hashMap[hashIndex].push_back(str); // Insert the string into the list associated with the hash index.
        }
    }
    infile.close(); // Close the file after reading.
    // Print the hash map contents.
    int maxDisplay = 0; // Counter for limiting the number of hash indices displayed.
    for (const auto & pair: hashMap) {
        if (maxDisplay >= 100)
            break; // After displaying 100 hash indices, stop.
        cout << "Hash Index: " << pair.first << endl; // Print the hash index.
        for (const string & s: pair.second) {
            cout << "  " << s << endl; // Print each string in the list associated with the hash index.
        }
        maxDisplay++; // Increment the display counter after printing each hash index and its associated strings.
    }

    /*
     // Test to see how many codes each index has.
     for (const auto &pair : hashMap)
     {
         if (maxDisplay >= 100) break; // Fixed to exactly 100

         // This will print exactly 1 line per index, showing how many codes each index has.
         cout << "Hash Index: " << pair.first << " (Contains " << pair.second.size() << " codes)" << endl;

         maxDisplay++;
     }
     */
    return 0;
}
// Now generates a hash index using modulo to ensure the index fits within a certain range.
int gen_hash_index(const string & s) {
    const int HASH_SIZE = 105; // Define a hash size to limit the range of hash indices. Using a little over 100 for part 3.
    int sum = 0;
    for (char c: s) {
        sum += (int) c; // Add the ASCII value of each character to the sum.
    }
    return sum % HASH_SIZE; // Return the hash index within the defined range.
}
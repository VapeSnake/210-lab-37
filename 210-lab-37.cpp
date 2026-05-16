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
    int choice; // Variable to store the user's menu choice.
    // Menu Loop
    do {
        cout << "Main Menu:" << endl;
        cout << "[1] Display Hash Map (First 100 entries)" << endl;
        cout << "[2] Search for a string" << endl;
        cout << "[3] Add a string" << endl;
        cout << "[4] Delete a string" << endl;
        cout << "[5] Modify a string" << endl;
        cout << "[6] Exit" << endl;
        cout << "\nEnter your choice: ";
        if (!(cin >> choice)) { // Validate input to ensure it's an integer.
            cin.clear(); // Clear the error state.
            cin.ignore(1000, '\n'); // Ignore the rest of the line.
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue; // Restart the loop to prompt for input again.
        };
        

        switch (choice) {
            case 1: {
                cout << "Hash Map Contents (First 100 entries):" << endl;
                int count = 0; // Counter to limit the number of entries displayed.
                for (const auto & pair: hashMap) {
                    cout << "Hash Index: " << pair.first << " -> ";
                    for (const auto & str: pair.second) {
                        cout << str << " ";
                    }
                    cout << endl;
                    count++;
                    if (count >= 100) break; // Limit to first 100 entries.
                }
            }
            /*
            case 2: {
                string searchStr;
                cout << "Enter string to search: ";
                cin >> searchStr;
                bool found = false; // Flag to track if the string is found.
                int hashIndex = gen_hash_index(searchStr);
                for (const auto & str: hashMap[hashIndex]) {
                    if (str == searchStr) { // Check if the string matches the search string.
                        cout << "String found!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "String not found." << endl;
                }
            }
            case 3: {
                string newStr;
            }
                */
        }
    } while (choice != 6); // Continue the menu loop until the user chooses to exit.

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
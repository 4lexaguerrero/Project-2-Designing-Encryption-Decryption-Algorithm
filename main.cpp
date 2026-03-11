#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

string encrypt(string plaintext, int key);
string decrypt(string ciphertext, int key);
void encryptFile(string inputFileName, string outputFileName, int key);
void decryptFile(string inputFileName, string outputFileName, int key);

int main() {
    int choice = 0;
    string inputFile, outputFile;
    int key = 0;

    cout << "1. Encrypt a file?\n";
    cout << "2. Decrypt a file?\n";
    cout << "Enter your choice: ";
    if (!(cin >> choice)) {
        cerr << "Invalid menu input. Please enter 1 or 2." << endl;
        return 1;
    }

    if (choice != 1 && choice != 2) {
        cerr << "Invalid choice. Please enter 1 (encrypt) or 2 (decrypt)." << endl;
        return 1;
    }

    cout << "Enter the input file name: ";
    cin >> inputFile;
    cout << "Enter the output file name: ";
    cin >> outputFile;
    cout << "Enter the encryption/decryption key (integer): ";
    if (!(cin >> key)) {
        cerr << "Invalid key input. Please enter an integer key." << endl;
        return 1;
    }

    if (inputFile.empty() || outputFile.empty()) {
        cerr << "Input and output file names cannot be empty." << endl;
        return 1;
    }

    if (choice == 1) {
        encryptFile(inputFile, outputFile, key);
    } else if (choice == 2) {
        decryptFile(inputFile, outputFile, key);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
// this is the shifting method for encryption, it shifts the characters by the key value
string encrypt(string plaintext, int key) {
    string encryptedText = plaintext;
    for (char &c : encryptedText) {
        if (isupper(c)) {
            c = 'A' + (c - 'A' + key) % 26;
        }
        else if (islower(c)) {
            c = 'a' + (c - 'a' + key) % 26;
        }
    }

// this is the substitution method for encryption, it replaces each character with its opposite in the alphabet!
    for (char &c : encryptedText) {
        if (isupper(c)) {
            c = 'Z' - (c-'A');
        }
        else if (islower(c)) {
            c = 'z' - (c-'a');
    }
    }

    // this is the transposition method for encryption, it reverses the order of the characters in the string!
    reverse(encryptedText.begin(), encryptedText.end());

    return encryptedText;
}

string decrypt(string ciphertext, int key) {
    string decryptedText = ciphertext;
// this is the transposition method for decryption, it reverses the order of the characters in the string!
   reverse(decryptedText.begin(), decryptedText.end());
         
    

    // this is the substitution method for decryption, it replaces each character with its opposite in the alphabet!
    for (char &c : decryptedText) {
        if (isupper(c)) {
            c = 'Z' - (c-'A');
        }
        else if (islower(c)) {
            c = 'z' - (c-'a');
        }
     }
// this is the shifting method for decryption, it shifts the characters back by the key value
    
    for (char &c : decryptedText) {
        if (isupper(c)) {
            c = ((c - 'A' - key + 26) % 26) + 'A';
        }
        else if (islower(c)) {
            c = ((c - 'a' - key + 26) % 26) + 'a';
        }
    }
    return decryptedText;
}

void encryptFile(string inputFileName, string outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening input or output file for encryption." << endl;
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << encrypt(line, key) << endl;
    }

    inputFile.close();
    outputFile.close();
}

void decryptFile(string inputFileName, string outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening input or output file for decryption." << endl;
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << decrypt(line, key) << endl;
    }

    inputFile.close();
    outputFile.close();
}
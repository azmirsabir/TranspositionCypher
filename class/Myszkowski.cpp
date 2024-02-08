//
// Created by Azmir.Sleman on 2/4/2024.
//
#include "Myszkowski.h"
#include <algorithm>
#include <map>

//constructor
Myszkowski::Myszkowski(string key) {
    this->key=key;
}

// Implementation of encryptMyszkowski
string Myszkowski::encrypt(const string &textt) {
    // Remove spaces from the text for simplicity
    string text=textt;
    text.erase(remove(text.begin(), text.end(), ' '), text.end());

    // Create a map to hold characters and their positions based on the key
    map<char, vector<int>> keyMap;
    for (int i = 0; i < key.length(); ++i) {
        keyMap[key[i]].push_back(i);
    }

    // Calculate the number of rows for the grid
    int rows = text.length() / key.length() + (text.length() % key.length() ? 1 : 0);
    vector<vector<char>> grid(rows, vector<char>(key.length(), '\0'));

    // Fill the grid with characters from the text
    for (int i = 0, k = 0; i < rows && k < text.length(); ++i) {
        for (int j = 0; j < key.length() && k < text.length(); ++j) {
            grid[i][j] = text[k++];
        }
    }

    // Encrypt based on the key order
    string encrypted;
    for (auto &pair : keyMap) {
        for (auto &col : pair.second) {
            for (int row = 0; row < rows; ++row) {
                if (grid[row][col] != '\0') {
                    encrypted += grid[row][col];
                }
            }
        }
    }

    return encrypted;
}

// Implementation of decryptMyszkowski
string Myszkowski::decrypt(const string &encryptedText) {
    // This is a simplified decryption process and may need to be adapted
    // based on how you choose to handle padding and uneven column lengths

    // Create a map to hold characters and their positions based on the key
    map<char, vector<int>> keyMap;
    for (int i = 0; i < key.length(); ++i) {
        keyMap[key[i]].push_back(i);
    }

    // Calculate the number of rows for the grid
    int rows = encryptedText.length() / key.length();
    vector<vector<char>> grid(rows, vector<char>(key.length(), '\0'));

    int index = 0;
    for (auto &pair : keyMap) {
        for (auto col : pair.second) {
            for (int row = 0; row < rows; ++row) {
                if (index < encryptedText.length()) {
                    grid[row][col] = encryptedText[index++];
                }
            }
        }
    }

    // Decrypt based on the key order
    string decrypted;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < key.length(); ++j) {
            if (grid[i][j] != '\0') {
                decrypted += grid[i][j];
            }
        }
    }

    return decrypted;
}

//destructor
 Myszkowski::~Myszkowski() {

}



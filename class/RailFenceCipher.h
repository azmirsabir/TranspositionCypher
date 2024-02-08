//
// Created by Azmir.Sleman on 1/4/2024.
//

#ifndef UNTITLED1_RAILFENCECIPHER_H
#define UNTITLED1_RAILFENCECIPHER_H
#include <bits/stdc++.h>
#include "TranspositionCipher.h"
using namespace std;

class RailFenceCipher: public TranspositionCipher {
private:
    int const key;
public:
    explicit RailFenceCipher(const int &key);

    string encrypt(const string &text) override;
    string decrypt(const string &cipher) override;

    ~RailFenceCipher() override;
};

#endif //UNTITLED1_RAILFENCECIPHER_H

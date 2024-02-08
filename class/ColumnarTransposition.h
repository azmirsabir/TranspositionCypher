//
// Created by Azmir.Sleman on 1/4/2024.
//

#ifndef UNTITLED1_COLUMNARTRANSPOSITION_H
#define UNTITLED1_COLUMNARTRANSPOSITION_H

#include <bits/stdc++.h>
#include "TranspositionCipher.h"
using namespace std;

class ColumnarTransposition: public TranspositionCipher{
private:
    string key;
    map<int, int> keyMap;

public:
    explicit ColumnarTransposition(string key);

    void setPermutationOrder();
    string encrypt(const string &text) override;
    string decrypt(const string &cipher) override;

    ~ColumnarTransposition() override;
};

#endif //UNTITLED1_COLUMNARTRANSPOSITION_H

//
// Created by Azmir.Sleman on 2/6/2024.
//

#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <string>

using namespace std;
class TranspositionCipher{
public:

    virtual string encrypt(const string &text)=0;
    virtual string decrypt(const string &cipher)=0;

    virtual ~TranspositionCipher();
};


#endif //CRYPTOGRAPHY_H

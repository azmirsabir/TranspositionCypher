#ifndef UNTITLED1_MYSZKOWSKI_H
#define UNTITLED1_MYSZKOWSKI_H

#include <string>
#include <vector>
#include "TranspositionCipher.h"


using namespace std;
class Myszkowski: public TranspositionCipher{
private:
    string key;
public:
    explicit Myszkowski(string key);
    string encrypt(const string &text) override;
    string decrypt(const string &cypher) override;
    ~Myszkowski() override;
};

#endif //UNTITLED1_MYSZKOWSKI_H

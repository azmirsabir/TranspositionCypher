#include <iostream>
#include "class/ColumnarTransposition.h"
#include "class/RailFenceCipher.h"
#include "class/Myszkowski.h"

using namespace std;

//Note: find the Encryption classes code in class/ folder

//checks for duplicate letter
bool hasUniqueLetters(string str){
    bool isUnique=true;
    for (string::size_type i = 0; i < str.size(); ++i)
    {
        if(i < str.size()-1){
            for (string::size_type j = i+1; j < str.size(); ++j)
            {
                if (str[j] == str[i])
                {
                    isUnique = false;
                }
            }
        }
    }
    return isUnique;
}

//below function decide based on the condition which class to be called
TranspositionCipher* createCipher(const string& key) {
    if(key=="4") return new RailFenceCipher(4);
    if (hasUniqueLetters(key)) return new ColumnarTransposition(key);
    if (!hasUniqueLetters(key)) return new Myszkowski(key);

    throw invalid_argument("Unsupported cipher type or incorrect parameters");
}

int main() {
    string message;
    getline(cin,message);
    try{
        TranspositionCipher* cipher=createCipher("4");//columns
        string enc=cipher->encrypt(message);
        string dec=cipher->decrypt(enc);
        cout<<"Encrypted Text: "<<enc<<"\nDecrypted Text: "<<dec<<endl<<endl;
        delete cipher;

        cipher= createCipher("httmx");//repeated letter
        enc=cipher->encrypt(message);
        dec=cipher->decrypt(enc);
        cout<<"Encrypted Text: "<<enc<<"\nDecrypted Text: "<<dec<<endl<<endl;
        delete cipher;

        cipher= createCipher("key");//non repeated key
        enc=cipher->encrypt(message);
        dec=cipher->decrypt(enc);
        cout<<"Encrypted Text: "<<enc<<"\nDecrypted Text: "<<dec<<endl<<endl;
        delete cipher;

    }catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}

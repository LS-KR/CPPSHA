
#include "MD5.h"
#include "SHA256.h"
#include "SHA384.h"
#include "SHA512.h"
#include <ios>
#include <iostream>
#include <fstream>
#include <vector>

int main() {

	SHA256 sha256;
	SHA384 sha384;
	SHA512 sha512;
    MD5 md5;

    std::ifstream fi;
    fi.open("./example-file.cpp", std::ios_base::binary);
    std::vector<unsigned char> byteVector;
    while (!fi.eof()) {
        unsigned char c;
        fi.read((char*) (&c), sizeof(c));
        byteVector.push_back(c);
    }

    std::cout << "SHA256: " << sha256.hash(byteVector.data(), byteVector.size()) << std::endl;
    std::cout << "SHA384: " << sha384.hash(byteVector.data(), byteVector.size()) << std::endl;
    std::cout << "SHA512: " << sha512.hash(byteVector.data(), byteVector.size()) << std::endl;
    std::cout << "MD5: " << md5.hash(byteVector.data(), byteVector.size()) << std::endl;
    
    return 0;
}
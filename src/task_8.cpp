#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Function to calculate (base^exponent) % modulus efficiently
int modPow(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    // Seed for random number generation
    std::srand(std::time(0));

    // Given input parameters
    int primeNumber = 13;
    int g = 2;
    int unknown_power = 144;
    std::string message = "cisl1o1v1e";

    // Generate random number randomB (from 1 to primeNumber-1)
    int randomB = 1 + std::rand() % (primeNumber - 1);

    // Calculate g^b mod N
    int gb_mod_N = modPow(g, randomB, primeNumber);
    std::cout << gb_mod_N << std::endl;

    // Calculate p^b mod N and use XOR operation to decrypt the message
    std::string decryptedMessage;
    for (int i = 0; i < message.length(); ++i) {
        char decryptedChar = message[i] ^ modPow(unknown_power, randomB, primeNumber);
        decryptedMessage += decryptedChar;
    }

    std::cout << decryptedMessage << std::endl;

    return 0;
}

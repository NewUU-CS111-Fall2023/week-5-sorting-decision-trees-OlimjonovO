#include <iostream>
#include <string>

// Function to calculate a basic hash value based on the sum of ASCII values of characters
int calculateBasicHash(const std::string& input) {
    int hashValue = 0;
    for (char c : input) {
        hashValue += static_cast<int>(c);
    }
    return hashValue;
}

// Function to verify if the calculated hash value matches the provided hash value
bool verifyIntegrity(const std::string& input, int providedHash) {
    int calculatedHash = calculateBasicHash(input);
    return calculatedHash == providedHash;
}

int main() {
    std::string message;
    int verifyHash;

    // Enter a string
    std::cout << "Enter a string: ";
    std::getline(std::cin, message);

    // Calculate and display the hash value of the entered string
    int calculatedHash = calculateBasicHash(message);
    std::cout << "Calculated Hash: " << calculatedHash << std::endl;

    // Enter a hash value
    std::cout << "Enter a hash value: ";
    std::cin >> verifyHash;

    // Verify if the entered hash value matches the calculated hash value
    std::cout << "Verification: ";
    if (verifyIntegrity(message, verifyHash)) {
        std::cout << "Hash values match." << std::endl;
    } else {
        std::cout << "Hash values did not match." << std::endl;
    }

    return 0;
}

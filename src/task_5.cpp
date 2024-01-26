#include <iostream>
#include <string>

unsigned int hashFunction1(const std::string& s) {
    unsigned int h = 0;
    for (char c : s) {
        h = c;
    }
    return h;
}

unsigned int hashFunction2(const std::string& s) {
    unsigned int h = 0;
    for (char c : s) {
        h = h * 31 + c;
    }
    return h;
}

unsigned int hashFunction3(const std::string& s) {
    unsigned int h = 0;
    for (char c : s) {
        h = h + c;
    }
    return h;
}

unsigned int hashFunction4(const std::string& s) {
    unsigned int h = 0;
    for (char c : s) {
        h = ((h + 1) * 31 * c) % 250;
    }
    return h;
}

unsigned int hashFunction5(const std::string& s) {
    unsigned int h = 0;
    for (char c : s) {
        h = h ^ c;
    }
    return h;
}

unsigned int hashFunction6(const std::string& s) {
    unsigned int h = 0;
    for (char c : s) {
        h = (h << 4) ^ (h >> 28) ^ c;
    }
    return h;
}

int main() {
    int m;
    std::string s;

    std::cout << "Enter hashing method (1-6): ";
    std::cin >> m;

    std::cout << "Enter the string: ";
    std::cin.ignore(); // Ignore newline from previous input
    std::getline(std::cin, s);

    unsigned int result;

    switch (m) {
        case 1:
            result = hashFunction1(s);
            break;
        case 2:
            result = hashFunction2(s);
            break;
        case 3:
            result = hashFunction3(s);
            break;
        case 4:
            result = hashFunction4(s);
            break;
        case 5:
            result = hashFunction5(s);
            break;
        case 6:
            result = hashFunction6(s);
            break;
        default:
            std::cerr << "Invalid hashing method!" << std::endl;
            return 1;
    }

    std::cout << "Hash value: " << result << std::endl;

    return 0;
}

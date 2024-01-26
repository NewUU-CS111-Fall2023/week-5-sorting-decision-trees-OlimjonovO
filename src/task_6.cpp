#include <iostream>
#include <unordered_set>
#include <string>
#include <cmath>

bool hasAllCodes(std::string s, int k) {
    int n = s.length();
    int totalCodes = pow(2, k);
    
    if (n < k || totalCodes > n) {
        return false;  // Not enough characters in s for all binary codes of size k
    }

    std::unordered_set<std::string> binaryCodesSet;

    for (int i = 0; i <= n - k; ++i) {
        std::string sub = s.substr(i, k);
        binaryCodesSet.insert(sub);

        if (binaryCodesSet.size() == totalCodes) {
            return true;
        }
    }

    return false;
}

int main() {
    // Example usage:
    std::string s1 = "00110110";
    int k1 = 2;
    std::cout << std::boolalpha << hasAllCodes(s1, k1) << std::endl;  // Output: true

    std::string s2 = "0110";
    int k2 = 1;
    std::cout << std::boolalpha << hasAllCodes(s2, k2) << std::endl;  // Output: true

    std::string s3 = "0110";
    int k3 = 2;
    std::cout << std::boolalpha << hasAllCodes(s3, k3) << std::endl;  // Output: false

    return 0;
}

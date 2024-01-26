#include <iostream>
#include <vector>

class MyHashSet {
private:
    std::vector<bool> hashSet;

public:
    MyHashSet() {}

    void add(int key) {
        if (key >= hashSet.size()) {
            hashSet.resize(key + 1, false);
        }
        hashSet[key] = true;
    }

    bool contains(int key) {
        return key < hashSet.size() && hashSet[key];
    }

    void remove(int key) {
        if (key < hashSet.size()) {
            hashSet[key] = false;
        }
    }
};

int main() {
    MyHashSet myHashSet;

    std::cout << "add(1): " << std::endl;
    myHashSet.add(1);

    std::cout << "add(2): " << std::endl;
    myHashSet.add(2);

    std::cout << "contains(1): " << myHashSet.contains(1) << std::endl;
    std::cout << "contains(3): " << myHashSet.contains(3) << std::endl;

    std::cout << "add(2): " << std::endl;
    myHashSet.add(2);

    std::cout << "contains(2): " << myHashSet.contains(2) << std::endl;

    std::cout << "remove(2): " << std::endl;
    myHashSet.remove(2);

    std::cout << "contains(2): " << myHashSet.contains(2) << std::endl;

    return 0;
}

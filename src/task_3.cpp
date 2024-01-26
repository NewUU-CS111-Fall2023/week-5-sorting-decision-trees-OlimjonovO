#include <iostream>
#include <vector>

class MyHashMap {
private:
    std::vector<std::pair<int, int>> data;

public:
    MyHashMap() {}

    void put(int key, int value) {
        for (auto& entry : data) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        data.push_back({key, value});
    }

    int get(int key) {
        for (const auto& entry : data) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        auto it = std::remove_if(data.begin(), data.end(),
                                 [key](const std::pair<int, int>& entry) { return entry.first == key; });
        data.erase(it, data.end());
    }
};

int main() {
    MyHashMap myHashMap;

    std::cout << "put(1, 1): " << std::endl;
    myHashMap.put(1, 1);

    std::cout << "put(2, 2): " << std::endl;
    myHashMap.put(2, 2);

    std::cout << "get(1): " << myHashMap.get(1) << std::endl;
    std::cout << "get(3): " << myHashMap.get(3) << std::endl;

    std::cout << "put(2, 1): " << std::endl;
    myHashMap.put(2, 1);

    std::cout << "get(2): " << myHashMap.get(2) << std::endl;

    std::cout << "remove(2): " << std::endl;
    myHashMap.remove(2);

    std::cout << "get(2): " << myHashMap.get(2) << std::endl;

    return 0;
}

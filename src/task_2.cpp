#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k, int f) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& flight : flights) {
        graph[flight[0]].emplace_back(flight[1], flight[2]);
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {cost, city, stops, remaining fuel}
    pq.push({0, src, 0, f});

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int cost = curr[0];
        int city = curr[1];
        int stops = curr[2];
        int remainingFuel = curr[3];

        if (city == dst) {
            return cost;
        }

        if (stops > k || remainingFuel < 0) {
            continue;
        }

        for (const auto& neighbor : graph[city]) {
            int nextCity = neighbor.first;
            int flightCost = neighbor.second;

            pq.push({cost + flightCost, nextCity, stops + 1, remainingFuel - flightCost});
        }
    }

    return -1; // If no valid path is found
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100, 0},
                                   {1, 2, 600, 1},
                                   {2, 0, 100, 1},
                                   {1, 3, 600, 0},
                                   {2, 3, 200, 0}};
    int src = 0, dst = 3, k = 2, f = 600;

    int result = findCheapestPrice(n, flights, src, dst, k, f);

    cout << "Cheapest price: " << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    vector<bool> visited(n, false);
    vector<int> minDist(n, INT_MAX);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 0});  // Start with any point, for example, the first point.
    
    int minCost = 0;
    
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        
        visited[u] = true;
        minCost += cost;
        
        for (int v = 0; v < n; ++v) {
            if (!visited[v]) {
                int distance = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (distance < minDist[v]) {
                    minDist[v] = distance;
                    pq.push({distance, v});
                }
            }
        }
    }
    
    return minCost;
}

int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << "Minimum Cost: " << minCostConnectPoints(points) << endl;
    
    points = {{3,12},{-2,5},{-4,1}};
    cout << "Minimum Cost: " << minCostConnectPoints(points) << endl;

    return 0;
}

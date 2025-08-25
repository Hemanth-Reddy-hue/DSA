#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int n, int s, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w}); // if undirected
        }

        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [nei, w] : graph[node]) {
                if (dist[nei] > d + w) {
                    dist[nei] = d + w;
                    pq.push({dist[nei], nei});
                }
            }
        }
        return dist;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 2, 2},
        {1, 2, 5}, {1, 3, 10},
        {2, 4, 3}, {4, 3, 4},
        {3, 5, 11}
    };

    Solution s;
    vector<int> result = s.dijkstra(n, 0, edges);
    for (int r : result) {
        cout << r << " ";
    }
}

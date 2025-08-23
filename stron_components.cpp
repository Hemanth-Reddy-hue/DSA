#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> scc(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n), rev_graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            rev_graph[e[1]].push_back(e[0]);
        }

        stack<int> stk;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i, graph, stk, visited);
            }
        }

        vector<bool> visited2(n, false);
        vector<vector<int>> result;
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            if (!visited2[node]) {
                vector<int> component;
                dfs2(node, rev_graph, component, visited2);
                result.push_back(component);
            }
        }
        return result;
    }

private:
    void dfs1(int src, vector<vector<int>> &graph, stack<int> &stk, vector<bool> &visited) {
        visited[src] = true;
        for (int nei : graph[src]) {
            if (!visited[nei]) dfs1(nei, graph, stk, visited);
        }
        stk.push(src);
    }

    void dfs2(int src, vector<vector<int>> &graph, vector<int> &component, vector<bool> &visited) {
        visited[src] = true;
        component.push_back(src);
        for (int nei : graph[src]) {
            if (!visited[nei]) dfs2(nei, graph, component, visited);
        }
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0},
        {1, 3}, {3, 4}
    };

    Solution s;
    vector<vector<int>> result = s.scc(n, edges);

    for (auto &comp : result) {
        cout << "{ ";
        for (int node : comp) cout << node << " ";
        cout << "}\n";
    }
    return 0;
}

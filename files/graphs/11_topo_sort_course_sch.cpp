#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool DFS(vector<vector<int>>& adj, vector<int>& visited, int u,
             stack<int>& stk) {
        if (visited[u] == 1)
            return false;
        if (visited[u] == 2)
            return true;

        visited[u] = 1;
        for (int v : adj[u]) {
            if (visited[v] == 1)
                return false;

            if (visited[v] == 0) {
                if (!DFS(adj, visited, v, stk))
                    return false;
            }
        }
        visited[u] = 2;
        // Neighbours are visited. Push current node in stack.
        stk.push(u);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>{});
        for (auto v : prerequisites) {
            adj[v[1]].push_back(v[0]);
        }
        // topo sorting
        stack<int> stk;
        vector<int> visited(numCourses, 0);
        for (int u = 0; u < numCourses; u++) {
            if (!visited[u]) {
                if (!DFS(adj, visited, u, stk))
                    return {};
            }
        }
        // Stack built.
        vector<int> result;
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool DFS(vector<vector<int>>& adjList, int currNode, vector<int>& visited, vector<int>& dfsPath) {
        visited[currNode] = 1;
        dfsPath[currNode] = 1;
        for (auto& u : adjList[currNode]) {
            // Traverse if not visited already.
            if (!visited[u]) {  // not visited yet
                if (DFS(adjList, u, visited, dfsPath))
                    return true;
            } else if (dfsPath[u] == 1) { // visited also dfsPath = 1.
                return true;
            }
        }
        // backTrack
        dfsPath[currNode] = 0; // visited but not in rec stack
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Detect cycle in directed graph.
        // We need to track current DFS path as well for directed graph.
        // Cuz a->b->c This is NOT A CYCLE.
        //    \|/ /^
        //     d

        vector<vector<int>> adjList(numCourses);
        for (auto& vec : prerequisites) {
            adjList[vec[1]].push_back(vec[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> dfsPath(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (DFS(adjList, i, visited, dfsPath))
                    return true;
            }
        }

        return false;
    }
};
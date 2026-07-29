// DFS BFS both possible.
// Conditions are exactly same. Just DFS replaces queue by recursion. All other logics are pretty much same.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Coloring problem.
        queue<int> q;
        int vertexNo = graph.size();
        vector<int> color(vertexNo, 0);

        for (int i = 0; i < vertexNo; i++) {
            // Start a bfs from unvisited vertex
            if (color[i] == 0) {
                q.push(i);
                color[i] = 1;
                // no need for bool col. We are always assigning colour based on parent color.
                while (!q.empty()) {
                    // Now if neighbours are uncoloured: push them and color
                    // them in different color If they are coloured:
                    // 1. Same as current node: Coloring not possible. Odd cycle
                    // exists.
                    // 2. Diff than current: either parent or adjacent node
                    // differently colored. In both cases they are valid... we
                    // are not pushing them in queue anyway so parent checking
                    // not required.
                    int u = q.front();
                    q.pop();

                    for (int v : graph[u]) {
                        if (color[v] == 0) {
                            color[v] = 3 - color[u]; // Derive from parent always. 3-1 = 2; 3-2=1 so oppo coloring always.
                            q.push(v);
                        } else if (color[v] ==
                                   color[u]) { // u and v same coloured: not
                                               // possible if v was parent. So v
                                               // must be adj to u. But still
                                               // same colour: that means valid
                                               // colouring not possible.
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
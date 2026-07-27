#include<bits/stdc++.h>
using namespace std;

//  Approach:
//  - Boundary land cells (1s) can escape to the sea.
//  - Traverse all boundary cells, run BFS/DFS to mark reachable land cells as -1.
//  - Remaining land cells (still 1) are enclaves.


class Solution {
    void markBoundaryConnected(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        // Step 1: Push all boundary land cells
        for (int i = 0; i < cols; i++) {
            if (grid[0][i] == 1) { q.push({0,i}); grid[0][i] = -1; }
            if (grid[rows-1][i] == 1) { q.push({rows-1,i}); grid[rows-1][i] = -1; }
        }
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 1) { q.push({i,0}); grid[i][0] = -1; }
            if (grid[i][cols-1] == 1) { q.push({i,cols-1}); grid[i][cols-1] = -1; }
        }

        // Step 2: BFS to mark all connected land cells
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (auto& d : dir) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    grid[nr][nc] == 1) {
                    grid[nr][nc] = -1; // mark as boundary-connected
                    q.push({nr,nc});
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Mark all boundary-connected land cells
        markBoundaryConnected(grid);

        // Count enclaves (land cells still == 1)
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

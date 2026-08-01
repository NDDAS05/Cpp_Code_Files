#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowNo = mat.size();
        int colNo = mat[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        vector<vector<int>> distance(rowNo, vector<int>(colNo, -1));

        // Idea: Start from all 0s and update distance of 1s.
        // BFS idea: BFS explores level by level, so for two 0s: 01 and 02, the 1 that 01 reaches first has the minimum distance from 01. So If a distance is not written for a 1 node (-1 inn distance matrix) write its distance. And if it is, because of BFS it must have been written by the 0 that is closer to it. DO NOT CHANGE IT.

        // So BFS itself takes care of "shortest distance" AND "visited marker" as distance are updated(non -1) ONLY because it was already traversed and got its distance updated from some node.

        queue<pair<int, int>> q;

        for(int i=0; i<rowNo; i++){
            for(int j=0; j<colNo; j++){
                if(mat[i][j] == 0) {
                    distance[i][j] = 0;
                    q.push({i, j});
                } // We shall start from 0. but not touch the nodes with valid distaneces(>=0) other than -1
            }
        }


        // Starting BFS traversal.
        while(!q.empty()){
            // level wise traversal needed? No. Because we don't care abt level info. Level wise is same as non level wise. Only diff is we get to know when a level ends in level wise (like using currSize)
            auto [row, col] = q.front();
            q.pop();

            for(auto& d: dir){
                int newRow = d[0] + row;
                int newCol = d[1] + col;

                if((newRow >= 0 && newRow < rowNo) && (newCol >=0 && newCol <colNo) && (distance[newRow][newCol]==-1)){
                    // Unvisited node.
                    // Update distance
                    distance[newRow][newCol] = distance[row][col]+1;
                    q.push({newRow, newCol});
                }
            }

        }

        return distance;

    }
};
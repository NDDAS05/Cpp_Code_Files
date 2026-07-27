#include<bits/stdc++.h>
using namespace std;


      // Only the border and their connected components can not be surrounded.
      // My idea: traverse border-wise, find their connected components, remember thier index somehow.
      // Do another traversal over the entire array fill remaining Os with X where the O is not a connected component of a corner cell.



class Solution {
    void captureRegion(vector<vector<char>>& board){
        int rowSize = board.size();
        int colSize = board[0].size();
        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
        // no need for vis array: we could just have updated "board" with Q or something.
        // When filling X, we could replace Q with O.
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        // Boundary travarsal
        for(int i=0; i<colSize; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                visited[0][i] = 1;
            } 
        }

        for(int i=1; i<rowSize; i++){
            if(board[i][colSize-1] == 'O'){
                q.push({i, colSize-1});
                visited[i][colSize-1] = 1;
            }
        }

        for(int i=colSize-2; i>=0; i--){
            if(board[rowSize-1][i] == 'O'){
                q.push({rowSize-1, i});
                visited[rowSize-1][i] = 1;
            }
        }

        for(int i=rowSize-2; i>=1; i--){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                visited[i][0] = 1;
            }
        }


        // Now start BFS from them.
        while(!q.empty()){
            auto [trow, tcol] = q.front();
            q.pop();

            for(auto& d: dir){
                int newrow = d[0]+trow;
                int newcol = d[1]+tcol;

                if((newrow<rowSize && newrow >=0) && (newcol<colSize && newcol>=0) && (board[newrow][newcol] == 'O') && (!visited[newrow][newcol])){
                    q.push({newrow, newcol}); //push when: in bound, cell is O not X, O marked cell is not visited already.
                    visited[newrow][newcol] = 1;
                }
            } 
        }

        // final filling.
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(visited[i][j] == 0) board[i][j] = 'X'; //  
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
      // Only the border and their connected components can not be surrounded.
      // My idea: traverse border-wise, find their connected components, remember thier index somehow.
      // Do another traversal over the entire array fill remaining Os with X where the O is not a connected component of a corner cell.
      captureRegion(board);
    }
};
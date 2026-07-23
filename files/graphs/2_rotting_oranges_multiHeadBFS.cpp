class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir ={{0,1},{0,-1},{1,0},{-1,0}};

        int gridLength = grid[0].size();
        int gridHeight = grid.size();
        int freshTotal = 0;
        int minTime = -1; // first pq pop(initial rotting orng happens at time 0. So +1 while popping makes time = 0 for first pop.) 

        queue<pair<int, int>> pq;

        for(int i=0; i<gridHeight;i++){
            for(int j=0; j<gridLength; j++){
                if(grid[i][j] == 2){
                    pq.push({i,j});
                }
                if(grid[i][j] == 1){
                    // Then orange is fresh
                    freshTotal++;
                }
            }
        }

        if(pq.empty() && freshTotal>0) return -1; // [[0 1]] no rotten to cover it
        if(pq.empty() && freshTotal == 0) return 0;  // [[0]] no orange.

        // q contains initial rotting oranges.
        while(!pq.empty()){
            int currSize = pq.size();
            for(int i=0; i<currSize; i++){
                pair currRot = pq.front();
                pq.pop();
                for(auto& pr: dir){
                    int newRow = currRot.first + pr.first;
                    int newCol = currRot.second + pr.second;

                    if((newRow < gridHeight && newRow >=0) &&
                        (newCol < gridLength && newCol >=0) &&
                        (grid[newRow][newCol] == 1)){
                        
                        grid[newRow][newCol] = 2;
                        pq.push({newRow, newCol});
                        freshTotal--;
                    }
                }
            }

            minTime++;

        }
        if(freshTotal!=0) return -1;
        else return minTime;
    }
};
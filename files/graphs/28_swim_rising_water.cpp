// Binary search.
// We know how to reach end, we know max and min values of the grid (max n^2 that is 2500, min is 0)
// We can do a binary search to see if we can reach in time to the end.

// Union Find and Dijkastra are also viable.


class Solution {
    vector<pair<int, int>> dir= {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int DFS(vector<vector<int>>& visited, int i, int j, int mid, vector<vector<int>>& grid){
        if(visited[i][j] == 1) return 0;
        visited[i][j] = 1;
        int size = visited.size();
        if(i==size-1 && j==size-1) return 1;

        // DFS on adj non visited nodes.
        for(auto& d : dir){
            int nR = i+d.first;
            int nC = j+d.second;

            if(nR>=0 && nR<visited.size() && nC>=0 && nC<visited.size() && visited[nR][nC] == 0 && grid[nR][nC]<=mid){
                if(DFS(visited, nR, nC, mid, grid)) return 1;
            }
        }

        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int low = 0;
        int high = 2500;
        int mid, ans=2500;
        int n = grid.size();
        

        while(low<=high){
            mid = low+(high-low)/2;
            vector<vector<int>>visited(n, vector<int>(n, 0));
            if(grid[0][0] > mid){
                low = mid+1;
            }

            else if(DFS(visited, 0,0,mid, grid)){
                ans=mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;
    }
};
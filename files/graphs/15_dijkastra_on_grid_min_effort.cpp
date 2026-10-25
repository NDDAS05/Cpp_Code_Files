class Solution {
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    struct edge{
        int row;
        int col;
        int effort;
    };

    struct CompareNode{
        bool operator()(const edge& a, const edge& b){
            return a.effort > b.effort;
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Whenever graph problems have path with "unit/uniform" costs, then standard BFS works cuz it always gives the "shortest path"

        // But Dijkastra comes when paths are not "uniform". Because, BFS technically gives path with "minimum number of edges." But if those edges that are included in "minimum number of edges" have very high edge weight, then they can not be called "shortest".

        // Here that is why Dijkastra Comes in.

        // Dijkastra Logic: 
        // Put starting vertex in PQ (say {distance_from_src, node} format).

        // Maintain a dist array. Set all to INT_MAX. src to 0.

        // While PQ is not empty
        // ---- Pop PQ. Get the node. Access its neighbours.
        // ---- Check if distance of neighbour from src (dist[neigh]) is greater than the distance of (src--->curr_node) + (currNode--->neighbour). If so, update to the new shorter distance
        // ---- ---- If updated: only then push the new {dist[neighbour], neighbour} pair in PQ.

        // Continue untill the PQ is not empty.
        int rowSize = heights.size();
        int colSize = heights[0].size();
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));

        dist[0][0] = 0;
        priority_queue<edge, vector<edge>, CompareNode> pq;
        pq.push({0, 0, 0}); // i  j  effort


        while(!pq.empty()){
            auto n = pq.top();
            pq.pop();

            int source_to_curr = n.effort;
            int curr_row = n.row;
            int curr_col = n.col;

            for(auto& d: dir){
                int newRow = curr_row + d[0];
                int newCol = curr_col + d[1];

                if((newRow>=0 && newRow < rowSize) && (newCol >= 0 && newCol < colSize)){
                    int effort = max(source_to_curr ,abs(heights[curr_row][curr_col] - heights[newRow][newCol]));
                    
                    if(dist[newRow][newCol] > effort){
                        pq.push({newRow, newCol , effort});
                        dist[newRow][newCol] = effort;
                    }
                }
            }
        }

        return dist[rowSize-1][colSize - 1];

    }
};
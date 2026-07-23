class Solution {
    void DFS(vector<vector<int>>& isConnected, int u, vector<int>& visited){
        if(visited[u] == 1) return;
        visited[u] = 1;
        for(int v=0; v<isConnected[u].size(); v++){ // adjacency matrix traversal. If edge exists [u][v] == 1. If not visited, visited[v] == 0.
            if(isConnected[u][v]==1 && visited[v]==0){
                DFS(isConnected, v, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int count = 0;

        for(int i=0; i<visited.size(); i++){
            if(visited[i] == 0) { // if not visited, increment connected component count by 1. Then visit it and mark its adjacent nodes.
                count++;
                DFS(isConnected, i, visited);
            }
        }

        return count;
    }
};
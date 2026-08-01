// This is first DFS based soln. To explore state based DFS.
// One BFS/Kahn based soln exists as well.


class Solution {
    int DFS(vector<int>& visited, vector<vector<int>>& graph, int u){
        if(visited[u] == 1 || visited[u] == 3){
            // Circle exists
            // Or leads to a path that leads to a cycle
            visited[u] = 3;
            return 3;
        }
        else if (visited[u] == 2){
            return 2;
        }
        else{
            visited[u] = 1;
            for(int &v: graph[u]){
                if(3 == DFS(visited, graph, v)){
                    visited[u] =3;
                    return visited[u];
                }
            }
            visited[u] = 2;
            return visited[u];
        }
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // DFS using 4 states: 
        // 0: Not visited yet
        // 1: In recursive stack
        // 2: Safe (all paths lead to safe location)
        // 3: Not safe (at least 1 path leads to cycle)
        int gSize = graph.size();

        vector<int> visited(gSize, 0);
        for(int i=0; i<gSize; i++){
            if(graph[i].empty()) visited[i] = 2;
        }
        vector<int> result;

        for(int u=0; u<gSize; u++){
            if(visited[u] == 0){
                DFS(visited, graph, u);
            }
        }

        for(int i=0; i<gSize; i++){
            if(visited[i] == 2) result.push_back(i);
        }

        return result;
    }
};
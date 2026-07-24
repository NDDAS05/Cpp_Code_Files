class Solution {
    bool findCycle(){}
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // We need to keep track of current node as well as the prevNode.
        // This will make sure that we are detecting cycle by getting a visited node in forward direction, not due to backward traversal. 
        // If traversed node != prev node but already visited in BFS: we got there in two different ways starting from a single node.
        // So cycle exists.
        
        // Creating a ADJ list.
        unordered_map<int, vector<int>> ump; // Issue: if vertices does not have edges, they will not appear in the ump. Here this is fine as they will not make cycle without a single edge anyway.
        for(auto& i: edges){
            ump[i[0]].push_back(i[1]);
            ump[i[1]].push_back(i[0]);
        }
        
        
        //  Doing BFS.
        // Pair format: {currNode, prevNode}
        queue<pair<int, int>> q;
        q.push({edges[0][0], -1});
        // Creating visited array.
        vector<int> visited(V, 0);
        
        // May have more than one connected components. So we need to make sure that every component is visited: thus run a loop for all vertex and try to start BFS from diff vertices.
        for(int u=0; u<V; u++){
            if(visited[u]==0){
                queue<pair<int, int>> q;
                q.push({u, -1});
                visited[u] = 1;
                
                while(!q.empty()){
                    pair p = q.front();
                    q.pop();
                    
                    for(auto& edge: ump[p.first]){
                        if(!visited[edge]){
                            visited[edge] = 1;
                            q.push({edge, p.first});
                        }
                        else if(p.second != edge){
                            return true;
                        }
                    }
                }
            }
        }
// itr: node TO BE visited p.second is prevNode of that q top. This ensures we are not hitting "already visited" due to backward traversal        
        return false;
        
    }
};
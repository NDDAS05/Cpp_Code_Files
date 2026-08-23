class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Finding MST
        // Steps:
        // 1. Have MST, VISITED ARRAY, PQ(wt, node, par)
        // 2. Start off with (0,0,-1) in PQ
        // 3. Pop. Explore neighbours: 
        //    >> Mark 0 as visited. Sum = sum+wt = 0.
        //    >> For every neighbours not already visited: put them in PQ. DO NOT MARK AS VISITED.
        //    >> Other than the first iteration: Whenever we are popping some node,
        //       put the (node, parent) pair in MST to reconstruct the MST.
        
        vector<bool> visited(V, false);
        vector<vector<pair<int, int>>> adjList(V, vector<pair<int, int>>{});
        
        for(auto& itr: edges){ // dest, weight
            adjList[itr[0]].push_back({itr[1], itr[2]});
            adjList[itr[1]].push_back({itr[0], itr[2]});
        }
        
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // pq contains weight, node.
        
        while(!pq.empty()){
            auto [weight, node] = pq.top();
            pq.pop();
            
            if(visited[node] == true) continue;
            visited[node] = true;
            sum = sum + weight;
            
            for(auto& adj : adjList[node]){
                if(!visited[adj.first]){
                    pq.push({adj.second, adj.first});
                }
            }
        }
        
        return sum;
    }
};
class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        if(src == dest) return 0; 
        // First: Building the adj list
        vector<vector<int>> adjlist(V, vector<int>{});
        
        for(auto& v: edges){ // Undirected graph so both u-->v and v-->u
            adjlist[v[0]].push_back(v[1]);
            adjlist[v[1]].push_back(v[0]);
        }
        
        // Create a distance array
        // Doubles as visited array as distance non -1 means updated through BFS and BFS guarantees shortest path so that IS the shortest path + that is visited already.
        vector<int> dist(V, -1);
        
        // Start traversing from the given node.
        dist[src] = 0; // starting vertex has distance 0
        // Now from here we will do a BFS and update distance of all the nodes. If dest is found terminate early. If not return -1
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            // Start bfs. Level info not needed. Just get distance updated.
            int curr = q.front();
            q.pop();
            
            // traverse adj list
            for(int n : adjlist[curr]){
                if(dist[n] == -1){
                    dist[n] = dist[curr]+1;
                    if(n ==  dest) return dist[n];
                    q.push(n);
                }
            }
        }
        
        return dist[dest]; // BFS ended but destination not found.
        // Could return -1 also
        // If src == dest, we do early termination. Even if that was not done, dist[dest] == dist[src] == 0, so correct ans is returned.
    }
};

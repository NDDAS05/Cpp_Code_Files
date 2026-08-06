class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto& v: flights){
            adjList[v[0]].push_back({v[1], v[2]}); // dest, cost
        }

        // Using BFS
        
        vector<int> price(n, INT_MAX);
        price[src] = 0;

        queue<pair<int, int>> q; // node, cost
        q.push({src, 0});
        k=k+1;

        while(!q.empty() && k--){
            int currSize = q.size();

            for(int i=0; i<currSize; i++){
                auto currNode = q.front();
                q.pop();

                int cNode = currNode.first;
                int price_to_curr = currNode.second;
                
                for(auto& v: adjList[cNode]){
                    if(price[v.first] > price_to_curr + v.second){
                        price[v.first] = price_to_curr + v.second;
                        q.push({v.first, price[v.first]});
                    }
                }
            }
        }

        if(price[dst] == INT_MAX) return -1;
        return price[dst];
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Should be direct Dijkastra
        
        // ADJ list
        vector<vector<pair<int, int>>> adjlist(n+1, vector<pair<int, int>>{});

        for(auto& u : times){
            adjlist[u[0]].push_back({u[1], u[2]}); // dest, time
        }

        vector<int> minTime(n+1, INT_MAX);
        minTime[k] = 0;
        minTime[0] = 0;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // time_from_src, node

        pq.push({0, k});

        while(!pq.empty()){
            auto [src_to_curr, curr] = pq.top();
            pq.pop();

            for(auto& neighbour: adjlist[curr]){
                int neigh = neighbour.first;
                int curr_to_neigh = neighbour.second;

                if(minTime[neigh] > curr_to_neigh + src_to_curr){
                    minTime[neigh] = curr_to_neigh + src_to_curr;
                    pq.push({minTime[neigh], neigh});
                }
            }
        }
        int Max=INT_MIN;

        for(int i=1; i<=n; i++){
            if(minTime[i] == INT_MAX) return -1;
            Max = std::max(minTime[i], Max);
        }

        return Max;
    }
};
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1000000007;
        vector<vector<pair<int, long long>>> adjList(n);
        for(auto& v: roads){
            adjList[v[0]].push_back({v[1], (long long)v[2]}); // dest, time
            adjList[v[1]].push_back({v[0], (long long)v[2]});
        }


        vector<long long> time(n, LLONG_MAX);
        time[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;

        // Do dijkastra
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); // Price= 0 to reach source 0.

        while(!pq.empty()){
            auto [source_to_curr, curr] = pq.top();
            pq.pop();
            if(source_to_curr > time[curr])
                continue;

            for(auto& itr: adjList[curr]){
                int node = itr.first;
                long long curr_to_neigh = itr.second;

                if(time[node] == source_to_curr + curr_to_neigh){
                    ways[node] = (ways[node]+ways[curr])%mod;
                }
                else if(time[node] > source_to_curr + curr_to_neigh){
                    time[node] = (source_to_curr+curr_to_neigh); // mod here may make 100000010 -->3 this destroys dijkastra
                    ways[node] = ways[curr];
                    pq.push({time[node], node});
                }
            }
        }
        return (ways[n-1] % mod);
    }
};
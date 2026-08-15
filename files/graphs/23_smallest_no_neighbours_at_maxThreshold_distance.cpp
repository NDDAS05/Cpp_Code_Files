class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // no fixed source or destination.
        // BFS: no "uniform" edge so discard
        // Dijkastra: only between a single source to all vertex. Need to run for all vertices.

        // Bellman ford: Works for negative edge weights but not needed here
        // Floyd Warshall: Should work as it finds distance between "every" pair of vtcs.

        // Step 1: Create distance matrix and for k=0 precompute shit.
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
                // Precompute for k=0
        for(auto& e: edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        // Now floyd warshall
        // Idea was: at stage k: include vertices upto k. (at 0 upto 0, at 1 -{0,1}).
        // At stage k while including the vertex k, if a shortest distance gets updated- that must be due to this 'k' vertex. So the two paths are [i][k] and [k][j]. We know for a shortest path i---k---p--q--r---j, every pair of vertex in the line i-j has shortest path along the line. So [i][k] and [k][j] are the shortest path from i-k and k-j respectively. 

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] < INT_MAX && dist[k][j] < INT_MAX){ // if intermediate node itself can be visited then only make comparison.
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        // Now all we need to find the number of shortest path lesser than the given threshold.
        int least_city = 0;
        int least_city_count = INT_MAX;
        

        for(int i=0; i<n; i++){
            int city_count = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    city_count ++;
                }
            }

            if(city_count <= least_city_count){ // Leetcode wants if multiple city can be visited through minimum number of cities, then the city whose OWN numeric value is largest is to be returned. Since we are traversing the cities in ascending order, this <= makes sure for multuple city with minimum neighbour in threshold, we update it every time we get =minimum. Since we traverse ascending order this always captures the "numerically greatest" city with minimum neighbours.
                least_city_count = city_count;
                least_city = i;
            }
        }

        return least_city;
    }
};
#include<bits/stdc++.h>
using namespace std;

// TC: Topo sort O(V+E) : we process each vertex and for every vertex their adj edges(vertices thru edges)
// Relaxation: for every vertex their neighbours basically O(E + V)
// And adj list making, distance updating etc O(V).

// So TC: O(V+E)
class Solution {
    
    void DFS(int u, vector<vector<pair<int, int>>>& adjlist, stack<int>& stk, vector<int>& visited){
        if(visited[u] == 1) return;
        visited[u] =  1;
        
        for(auto& v: adjlist[u]){
            // adjlist[u] is a vector of pairs.
            // So v is the individual pair
            // v[0] stores the destination
            if(!visited[v.first]){
                DFS(v.first, adjlist, stk, visited);
            }
        }
        
        stk.push(u);
    }
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // First, create the adj list
        // Then do topo sorting and store the topo ordering somewhere.
        // Get the vertices one by one from the topo ordering and "relax" the neighbours.
        // Means create a distance array, set source distance to 0, all destination distances INF
        // Get one vertex from the stack/array and update its neighbours distance: 
        
        // ---> min(prevly recorded mininum distance, distance from corrent node) <---
        
        // Now does topo sort guarantee that source will come at top in the topo stack/vector? NO.
        // Say topo ordering is 6--5--1--4--0--2--3 and source is 1.
        
        // What does it mean? 
        
        // In topo sort, if there exists an path from u--..-->v u must come before v.
        //
        // So, topo ordering is 6---...---> 1. That means from 1 we CAN NOT REACH 6
        // Because, in that case, the ordering would have been 1---...--->6.
        // Similarly from 1 we CAN NOT reach 5.
        
        // So if all vertices are reachable from source, in topo ordering source will be the first/top vertex.
        
        // Main Question-------------------------------
        
        // Making a adjList
        vector<vector<pair<int, int>>> adjlist(V, vector<pair<int, int>>{});
        for(auto e: edges){
            int source = e[0];
            int dest = e[1];
            int weight = e[2];
            
            adjlist[source].push_back({dest, weight});
        }
        
        // Find valid topo ordering
        stack<int> stk;
        vector<int> visited(V, 0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                DFS(i, adjlist, stk, visited);
            }
        }
        
        // Now edge relaxation
        vector<int> distance(V, INT_MAX);
        distance[0] = 0;
        
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();
            
            for(auto& v : adjlist[top]){
                // If top distance is already INT MAX, no point of updating children's distances they will be infinite too.
                if(distance[top] != INT_MAX){
                    distance[v.first] = min(distance[top]+v.second, distance[v.first]);
                }
            }
        }
        
        
        for(int i=0; i<V; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};

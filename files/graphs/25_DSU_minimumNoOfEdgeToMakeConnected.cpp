// Leetcode 1319
#include <bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent;
    vector<int> size;
    public:

    DSU(int n){ // resize the vectors using resize
        parent.resize(n);
        size.resize(n, 1); // fill with 1

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        x = find(x);
        y = find(y);

        if(x==y) return;

        if(size[x] < size[y]){
            swap(x,y);
        }

        size[x]+=size[y];
        parent[y] = x;
    }
};

class Solution {    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int connsize = connections.size();
        if(connsize < n-1) return -1;

        // reconstructing the given graph from scratch and omitting extra edges.
        int extra = 0;
        DSU d(n);

        for(auto& itr: connections){
            int u = itr[0];
            int v = itr[1];

            if(d.find(u) == d.find(v)){
                extra++;
            }
            else{
                d.Union(u, v);
            }
        }

        // Now we know how many extra edges are there. We need to count number of connected components.
        // Since all the DSU member has representatives, the number of "representatives" ==  the number of connected components
        int components = 0;

        for(int i = 0; i<n; i++){
            if(d.find(i) == i) components++;
        }

        // To connect n connected components we need "minimum" components-1 edges. 
        // We have "extra" number of edges remaining.

        return (extra >= components-1)? components-1:-1;
    }
};

// LeetCode 947
// First think is bellow. Better is after this one.

class DSU{
    vector<int> parent, size;

public:

    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);

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
        if(size[x]<size[y]) swap(x,y);

        size[x] += size[y];
        parent[y] = x;
    }

    int getSize(int n){
        return size[n];
    }
    int getParent(int n){
        return parent[n];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // For every connected component we can remove (connected_component -1) number of nodes (connected compo means a spanning tree would be there. So following the path we can remove from leaf towards root- except root.)
        // So this looks like a UNION BY SIZE as SIZE - 1 of the parent is we can remove.

        // So construct the DSU, For every parent[i] == i nodes, we add thier size[i]-1 in our calculation.

        int nodeNo = stones.size();
        unordered_map<int, vector<int>> umpx;
        unordered_map<int, vector<int>> umpy;
        DSU d(nodeNo);

        for(int i=0; i<nodeNo; i++){
            int x = stones[i][0];
            int y = stones[i][1];

            for(int edgeNo : umpx[x]){
                d.Union(i, edgeNo);
            }

            for(int edgeNo : umpy[y]){
                d.Union(i, edgeNo);
            }
            //Insert current edge.
            umpx[x].push_back(i);
            umpy[y].push_back(i);
        }

        // Union itself takes care of size and stuff. We need to only count the connected component sizes.
        int max_removal = 0;

        for(int i=0; i<nodeNo; i++){
            if(d.find(i) == i){
                max_removal += d.getSize(i) - 1;
            }
        }

        return max_removal;
    }
};


// Modified approach

// DSU from previous

class Solution2 {
public:
    int removeStones(vector<vector<int>>& stones) {
        // For every connected component we can remove (connected_component -1) number of nodes (connected compo means a spanning tree would be there. So following the path we can remove from leaf towards root- except root.)
        // So this looks like a UNION BY SIZE as SIZE - 1 of the parent is we can remove.

        // So construct the DSU, For every parent[i] == i nodes, we add thier size[i]-1 in our calculation.

        int nodeNo = stones.size();
        unordered_map<int, int> umpx;
        unordered_map<int, int> umpy; // Since we are using DSU concept and union by size, all we need to do is to make sure connected components have proper nodes. We do not need to preserve all edges. Say (0,0) is connected to (0,1) and (0,1) to (0,2). For our purpose if we say (0,1), (0,2) both are only connected to (0,0) that does not change anything.
        DSU d(nodeNo);

        for(int i=0; i<nodeNo; i++){
            int x = stones[i][0];
            int y = stones[i][1];

            if(umpx.count(x)){
                d.Union(i, umpx[x]);
            }
            else umpx[x] = i; // No previous element so this one is representative.

            if(umpy.count(y)){
                d.Union(i, umpy[y]);
            }
            else umpy[y] = i; // Same case here
        }

        // Union itself takes care of size and stuff. We need to only count the connected component sizes.
        int max_removal = 0;

        for(int i=0; i<nodeNo; i++){
            if(d.find(i) == i){
                max_removal += d.getSize(i) - 1;
            }
        }

        return max_removal;
    }
};
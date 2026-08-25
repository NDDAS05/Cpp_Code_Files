class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;

        if(size[x] < size[y]) swap(x,y);
        size[x] += size[y];
        parent[y] = x;
    }
    int getSize(int n){
        return size[n]; // use find(n) here
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir= {{0,1}, {0,-1}, {1,0}, {-1,0}};
        // Idea: Construct a DSU outta grid first
        // Iterate over the entire thing and for every 0s: try to connect it to the connected component four directionally touching it.
        // If two (or more than 2) compo touching each other, combine their size +1 (for the current one.)
        // Get the max of combined sizes and max of size array.

        int n = grid.size();
        DSU d(n*n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(auto& p: dir){
                        int ni = i + p.first;
                        int nj = j + p.second;
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1){
                            d.Union(i*n+j, d.find(ni*n+nj));
                        }
                    }
                }
            }
        }


        int maxSize = -1;

        // This constructs the union. Now we need to find the max of (max of dsu.size array and after transformation of component).
        // Iterate again now this time we need to transform one 0.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){ // loop over all
                maxSize = max(maxSize, d.getSize(d.find(i*n+j)));
                if(grid[i][j] == 0){ // if 0 we can convert it into 1
                    //can transform into 1.
                    unordered_set<int> neigh; // to get unique neighbours
                    int currSize=0;
                    for(auto& p: dir){ // four directions
                        int newRow = i+p.first;
                        int newCol = j+p.second;
                        

                        if(newRow >= 0 && newRow<n && newCol>=0 && newCol <n && grid[newRow][newCol] != 0){
                            if(neigh.find(d.find(n*newRow+newCol))!=neigh.end()) continue;
                            neigh.insert(d.find(n*newRow+newCol));
                            currSize += d.getSize(d.find(n*newRow+newCol));
                        }
                    }
                    maxSize = max(maxSize, currSize+1);
                }
            }
        }

        return maxSize;
    }
};
// instead of using vector<unordered_set<int>> an simpler solution exists
// But bellow idea is correct.

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Treating as undirected graph.
        // Since no cycle is possible, if, from 0 any fwd edge is present that must be the one to reverse.
        // Unordered graph to make sure if backward edge exists, we can get to that node too (our ultimate target is to make backward edges.)
        vector<vector<int>> udg(n, vector<int>{});// to store unordered way
        vector<unordered_set<int>> dig(n, unordered_set<int>{}); // store the actual directions

        for(auto& edge: connections){
            // fill unordered
            udg[edge[0]].push_back(edge[1]);
            udg[edge[1]].push_back(edge[0]);
            // fill ordered
            dig[edge[0]].insert(edge[1]);
        }
        int inverse_count=0;


        queue<pair<int, int>> q; // curr, parent
        for(auto& vertex: udg[0]){
            q.push({vertex, 0});
        }
        int parent=0;

        while(!q.empty()){
            // cycle not possible, so only backward traversal prevention needed.
            int currSize = q.size();
            for(int i=0; i<currSize; i++){
                 // processing time
                 // if for the popped node, parent to that node *EXISTS* that means we are travelling outward. We need to go inward, meaning that edge has to be reversed.
                 auto [curr, parent] = q.front();
                 q.pop();

                 //process.
                 if(dig[parent].count(curr)) inverse_count++;
                 for(auto& neigh : udg[curr]){
                    if(neigh!=parent){
                        q.push({neigh, curr});
                    }
                 }
            }
        }

        return inverse_count;
    }
};
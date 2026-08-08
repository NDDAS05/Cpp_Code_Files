// Q: 3310
// READ THE PROBLEM FIRST


class Solution {

    void DFS(int u, vector<vector<int>>& adjlist, vector<int>& sus) {
        if (sus[u] == 1)
            return;

        sus[u] = 1;

        for (auto v : adjlist[u]) {
            if (!sus[v])
                DFS(v, adjlist, sus);
        }
    }

public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        // a-------->b (a invokes b)
        // idea: using DFS/BFS to mark the sus nodes first.
        // then using traversal over the entire graph to mark the nodes that
        // invokes/ has edge TO the sus nodes. If such exists sus group can not
        // bee removed.

        vector<vector<int>> adjlist(n, vector<int>{});

        for (auto& itr : invocations) {
            adjlist[itr[0]].push_back(itr[1]);
        }

        vector<int> sus(n, 0);

        DFS(k, adjlist, sus);

        // now sus set is marked as "1s".

        // queue<int> q;
        // -1 means visited
        bool invokes_sus = false; // false: remove sus group add everything else
        // true: do not remove anything

        // for (int i = 0; i < n; i++) {
        //     if (sus[i] != 1 && sus[i] != -1) {
        //         q.push(i);
        //         sus[i] = -1;
        //         while (!q.empty()) {
        //             int curr = q.front();
        //             q.pop();

        //             for (int& v : adjlist[curr]) {
        //                 if (sus[v] == 1) // calls contaminated
        //                 {
        //                     invokes_sus = true;
        //                     break;
        //                 }
        //                 if (sus[v] != -1) {
        //                     q.push(v);
        //                     sus[v] = -1;
        //                 }
        //             }
        //             if (invokes_sus)
        //                 break;
        //         }
        //         if(invokes_sus) break;
        //     }
        // }

        // We ONLY need to know if an edge exists from edge e ---> sus so we can not remove sus.
        // invokations array also serves the same purpose

        for(auto& edge : invocations){
            if(sus[edge[0]] != 1 && sus[edge[1]] == 1){
                invokes_sus = true;
                break;
            }
        }
        vector<int> result;

        if(invokes_sus){
            // can not remove anything
            for(int i=0; i<n; i++){
                result.push_back(i);
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(sus[i] == 1) continue;
                result.push_back(i);
            }
        }

        return result;
    }
};
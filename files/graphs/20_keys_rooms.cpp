class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // should be traversal only
        // Input is adjlist itself

        //now just traverse the entire thing.

        queue<int> q;
        vector<int> visited(rooms.size(), 0);

        q.push(0);
        visited[0] = 1;
        int visited_count = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited_count++;
            for(int& neigh : rooms[curr]){
                if(!visited[neigh]){
                    visited[neigh] = 1;
                    q.push(neigh);
                }
            }

        }

        if (visited_count == rooms.size()) return true;
        return false;

    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        //Putting everything in min heap
        // while popping, rank will not change if the last popped was same as this one. Otherwise decreases by 1.

        // Have a hashmap that will allow fast lookup
        // build new array with info from the heap.

        // May be don't use priority queue. In place sorting works too.

        vector<int> sortedVc = arr;
        std::sort(sortedVc.begin(), sortedVc.end());
        unordered_map<int, int> ump;
        int rank=0;
        // key: ele
        // value: priority
        
        for(int i=0; i<arr.size(); i++){
            if(ump.find(sortedVc[i]) == ump.end()){
                // If not found
                rank++;
                ump[sortedVc[i]] = rank;
            }
            else continue;
        }

        for(int i=0;i<arr.size();i++){
            arr[i] = ump[arr[i]];
        }

        return arr;
    }
};
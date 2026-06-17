class Solution {
public:
    void sum(vector<vector<int>>& combs, vector<int>& candidates, vector<int>& seq, int remSum, int pos){
        // Do the work on current
        if(remSum < 0) return;
        else if(remSum == 0) {
            combs.push_back(seq);
            return;
        }

        for(int i=pos; i<candidates.size(); i++){
            // Now we can include this again. Or we can skip it.
            // If we include it we have to upgrade the sum and remSum but NOT the pos.
            // Cuz one element can be included multiple times.
            seq.push_back(candidates[i]);
            sum(combs, candidates, seq, remSum - candidates[i], i); 

            // Now leaving part
            seq.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Move on to next index if and only if skipping current element
        // If not, stay at the current index.

        // In backtraking, we did recursive calls in Loop, if matches, put in vector, then POP it.
        // Loop counter naturally skips the current element.

        // Only caveat is that we can include it any number of times- thats it.

        // combs : All combinations- vector of vector to return.
        // candidates: supplied array- the list of candidate elements.
        // seq : individual vectors in combs i.e. all valid sequences.

        vector<vector<int>> combs;
        vector<int> seq;
        sum(combs, candidates, seq, target, 0);

        return combs;

    }
};
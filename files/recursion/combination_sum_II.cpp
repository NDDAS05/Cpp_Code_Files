class Solution {
public:
    void generateComb(vector<vector<int>>& combinations, vector<int>& candidates, vector<int>& seq,int remSum, int pos){
        if(remSum < 0) return;
        else if(remSum == 0) {
            combinations.push_back(seq);
            return;
        }

        for(int i= pos; i<candidates.size(); i++){
            // Skip at same level to start unique branches at every recursion level
            if(i>pos && candidates[i]==candidates[i-1]) // i>pos to ensure 1st occurence is taken always.
                continue; // skip them

            if(candidates[i] > remSum) break; // Cuz array is sorted, if current array value itself
            // Is greater than remaining sum, no point in taking rest of the values up ahead in the candidates.

            // Accept current element cuz irrelevant are skipped already.
            seq.push_back(candidates[i]);
            generateComb(combinations, candidates, seq, remSum - candidates[i], i+1);
            seq.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // One way to do Combination-Sum 1 and use set to fix this.
        // But there is another way.. cuz set means we are generating dups just later to skip them.
        // We can skip dupes entirely.

        // When will dupes happen? Suppose we sort the candidates first. 
        // Then if we start 2 identical recursion branches.. say 1 -> 1 1 
                                                                // -> 1 1
                                                                // -> 1 2 
        // Top 2 will create duplicates.
        // So we skip dupes on same recursion level, but not on multiple recursion levels
        // Since our starting is unique taking same ele as parent also creates new combinations because [unique]-[a] and unique-[b] are also unique. Like the end results of the tree will be unique combination.

        // But if we skip duplicates across multiple recursion levels, we will skip same emlements completely. So target 3 on [1 1 1 5] we will never consider 1 1 1 at all.

        // But here we will ONLY start 2 recursive branches one with [1] another with [5]: starting is unique , so sequences will be unique too.
        // That is : Since each recursion level starts only one branch for each distinct value, every combination is generated exactly once.
        
        vector<vector<int>> combinations;
        vector<int> seq;
        // Sort the candidates
        sort(candidates.begin(), candidates.end());
        generateComb(combinations, candidates, seq, target, 0);
        return combinations;
    }
};
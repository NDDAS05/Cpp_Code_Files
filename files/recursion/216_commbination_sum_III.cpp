class Solution {
public:
    void allCombinations(vector<vector<int>>& combs, vector<int>& currSeq, int pos, int remSum, int limit){
        if(currSeq.size() > limit) return;
        if(remSum < 0) return;
        else if(remSum == 0 && limit==currSeq.size()){
            combs.push_back(currSeq);
            return;
        }

        for(int i=pos; i<9; i++){
            // pos is 0 based. elements are 1 based.
            // push_back pos + 1 is to push back element
            if(i+1 > remSum) break;

            currSeq.push_back(i+1);
            allCombinations(combs, currSeq, i+1, remSum-i-1, limit);
            currSeq.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // Idea: Just like combination sum II.
        // Instead of array, we will use pos as the current element.

        vector<vector<int>> combs;
        vector<int> currSeq;
        allCombinations(combs, currSeq, 0, n, k);
        return combs;
    }
};
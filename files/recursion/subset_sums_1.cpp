class Solution {
  public:
    
    void sums(vector<int>& arr, vector<int>& sum,int currSum, int pos){
        // Using backtracking concept.
        sum.push_back(currSum);
        
        for(int i=pos; i<arr.size(); i++){
            sums(arr, sum, currSum + arr[i], i+1);
        }
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sum;
        sums(arr, sum, 0, 0);
        return sum;
    }
};
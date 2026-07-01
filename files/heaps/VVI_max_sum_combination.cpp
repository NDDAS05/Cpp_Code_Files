class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // Sort the two arrays first
        std::sort(a.begin(), a.end(), std::greater<int>());
        std::sort(b.begin(), b.end(), std::greater<int>());
        
        // Now we need:
        // 1. maximum sum with indices
        // 2. visited indices
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({a[0]+b[0], {0, 0}});
        
        //unordered_set<pair<int,int>> uset : This is invalid in Cpp because cpp does not have a valid hash function for this.
        set<pair<int,int>> uset;
        uset.insert({0,0});
        
        // First one is always the largest sum
        // Now what about next? Next immediate large sums can be 0 1 and 1 0.
        // if say 1 0, the next can be at 0 1 OR 2,0 so on.
        int i, j;
        
        vector<int> ans;
        while(ans.size() < k && !pq.empty()){
            // pop the largest one from heap, store it in result vector.
            // pair<pair<int, int>> p = pq.top();
            auto p = pq.top();
            pq.pop();
            // Extract its co-ordinates
            ans.push_back(p.first);
            i = p.second.first;
            j = p.second.second;
            
            // Push both (i, j+1) and (i+1, j) into the array
            // if possible
            
            if(i+1<a.size() && uset.find({i+1,j})==uset.end()){
                pq.push({a[i+1]+b[j], {i+1, j}});
                uset.insert({i+1, j});
            }
            
            if(j+1<b.size() && uset.find({i,j+1})==uset.end()){
                pq.push({a[i]+b[j+1], {i, j+1}});
                uset.insert({i, j+1});
            }
        }
        
        return ans;
        
    }
};
class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        
        vector<pair<int, int>> intervals;
        
        for(int i=0; i<start.size(); i++){
            intervals.push_back({start[i], finish[i]});
        }
        
        // Sort them based on the ending time
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a.second < b.second;
        });
        
        // Now we do them based on starting time
        int ends = intervals[0].second;
        
        int count =1;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].first > ends) {
                count++;
                ends = intervals[i].second;
            }
        }
        
        return count;
    }
};
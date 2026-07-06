// IDK whats greedy here..
// Just find where to push, and push it taking care of merging

class Solution {
public:
    int interval(vector<vector<int>>& intervals, vector<int>& newInterval){
        // Binary search for intervals.
        // The first index where intervals[1] > newInterval[0]

        int low = 0;
        int high = intervals.size()-1;
        int result= intervals.size();
        // first index where ---==____ OR ____==----
        while(low<=high){
            int mid = low + (high-low)/2;

            if(intervals[mid][1] >= newInterval[0]){
                result = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return result;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newSet;
        int idx = interval(intervals, newInterval);

        for(int i=0; i<idx; i++){
            newSet.push_back(intervals[i]);
        }

        if(idx == intervals.size()){
            newSet.push_back(newInterval);
            return newSet;
        }
        // We have to now keep merging.
        while(idx < intervals.size() && newInterval[1] >= intervals[idx][0] ){
            newInterval[0] = std::min(newInterval[0], intervals[idx][0]);
            newInterval[1] = std::max(newInterval[1], intervals[idx][1]);

            idx++;
        }

        newSet.push_back(newInterval);
        while(idx < intervals.size()) {newSet.push_back(intervals[idx]); idx++;}


        return newSet;
    }
};
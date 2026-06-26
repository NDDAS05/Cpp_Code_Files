class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // We have to find next smaller and previous smaller for all array elements
        // Our current histogram spans on both side upto them EXCLUDING THEM. They are smaller in height than our current histogram.

        // We need max of this span area.
        int max_area = INT_MIN;
        stack<int> sf; // stack for forward loop
        stack<int> sb; // stack for backward loop

        vector<pair<int, int>> span_idx(heights.size(), pair<int,int>(-1,-1));

        int i,j;

        // Finding NSE and PSE in the same loop
        for(int i=0, j=heights.size()-1;j>=0; i++, j--){
            // logic for NSE
            // loop from backward.

            //pop logic
            while(!sb.empty() && heights[j] <= heights[sb.top()]){
                // = logic in below loop
                sb.pop();
            }
            // If empty, that means all the previously pushed stack elements are greater than eqal the current one: so the current one spans all the way to the boundary. 
            // first ->next , second->previous
            span_idx[j].first = (sb.empty()) ? heights.size() : sb.top();
            sb.push(j);

            while(!sf.empty() && heights[i] <= heights[sf.top()]){
                // < "=" here because say stack situation: 1(0idx) 2(1idx) we get another 2(2idx).
                // This 2 spans previous 2(1idx) too
                // so to make sure previous smaller is 1 and not 2, <= pops 2 as well.
                //outside loop span_idx sets PSE index as 1 index.

                // If < was given , the previous smaller idx would have been 2(1idx). That means our histo does not span this 2(1idx) <Cuz this means we are considering 2 < 2(2idx) and storing 2(1idx) as SMALLER ELEMENT PREVIOUS OF 2(2idx)
                sf.pop();
            }
            // If empty, that means all the previously pushed stack elements are greater than the current one: so the current one spans all the way to the boundary. 
            span_idx[i].second = (sf.empty()) ? -1 : sf.top();
            sf.push(i);
        }

        for(int i=0; i<span_idx.size(); i++){
            max_area = std::max(max_area, (span_idx[i].first - span_idx[i].second -1)*heights[i]);
        }

        return max_area;
    }
};
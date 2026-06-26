<= and >= logic is properly written here.

class Solution {
public:
    // Logic in note copy.
    // Here is only the implementation.

    // Long story short: We need to build a histogram array grounded at the given row.
    // So we are looking at each row cumulatively.
    


    // ---------------------------------------------------------
    // || Function to calculte NSE and PSE to determine max area 
    // ---------------------------------------------------------
    int maxArea(vector<int>& histograms){
        // Using NSE and PSE
        stack<int> sf;
        stack<int> sb;
        vector<pair<int,int>> limits(histograms.size(), pair<int,int>(-1,-1));

        for(int i=0, j=histograms.size()-1; i<histograms.size(); i++, j--){
            // PSE
            while(!sf.empty() && histograms[sf.top()] >= histograms[i]){
                // >'=' because, we: Look at top stack, pop stack untill the top is smaller than current one , store that top stack idx as PSE and push the current element onto.

                // = ensures if 1234444 [4]-> when this 4 comes we DO NOT TREAT EXISTING 4s as "PREVIOUS SMALLER ELEMENT"

                // We pop these 4s too and look at the element that is properly smaller than the current 4.
                sf.pop();
            }
            // Store top index or smth as the PSE.
            limits[i].second = (sf.empty()) ? -1 : sf.top();

            // For PSE: backward loop
            while(!sb.empty() && histograms[sb.top()] >= histograms[j]){

                sb.pop();
            }
            // Store top index or smth as the NSE.
            limits[j].first = (sb.empty()) ? histograms.size() : sb.top();

            // Popping done, storing stack-top index done, now just pushing current one.
            sf.push(i);
            sb.push(j);
        }
        // Now calculate area.
        int maxArea=INT_MIN;
        for(int i=0; i<limits.size(); i++){
            maxArea = std::max(maxArea, (limits[i].first - limits[i].second -1)*histograms[i]);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // We maintain a cumulative "grounded at this level" tower height 
        vector<int> tower_height(matrix[0].size(), 0);
        int MaxArea = INT_MIN;
        for(int i=0; i<matrix.size(); i++){
            // If grounded here, prev vector values+1.
            // If not 0.
            
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '0') tower_height[j] = 0;
                else tower_height[j]++;
            }// Let it update the tower_heights array completely first
            MaxArea = std::max(MaxArea, maxArea(tower_height));
        }

        return MaxArea;
    }
};
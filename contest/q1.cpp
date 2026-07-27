#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;

        int tst1 = 0; // for series 1;
        int s1_size = series1.size();

        int tst2 = 0;
        int s2_size = series2.size();

        while(tst1 < series1.size() || tst2<series2.size()){
            int currtst = std::min(series1[tst1][0], series2[tst2][0]);
            int value = 0;
            if(tst1 < series1.size()){
                value += series1[tst1][1];
            }
            if(currtst == series1[tst1][0]){ // timestamp matches
                tst1++;
            }
            if(tst2 < series2.size()){
                value += series2[tst2][1];
            }
            if(currtst == series2[tst2][0]){ // timestamp matches
                tst2++;
            }

            ans.push_back({currtst, value});
        }

        return ans;
    }
};




int main(){
    
    
    
    return 0;

}
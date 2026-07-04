class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Why greedy? At every stage we select child with thr lowest greed factor and try to assign a cookie as close to thier greed factor as possible.

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        // Both arrays are sorted now.
        int j=0, i=0;

        for(i=0; i<g.size(); i++){
            while(j<s.size() && s[j] < g[i]) j++;
            if(j<s.size()) j++;
            else break;
        }
        return i; // Observation: if children < cookie no. and all the childern satisfied (0 1 2) array ends at i=3.
        // If not, if not all children are satisfied, i points to the index which is the first one not satisfied.
        // Which happens to be (last satisfied index)+1 OR the number of children satisfied.

        // So no separate count needed.
    }
};
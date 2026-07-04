class Solution {
    
    struct item{
        int value;
        int weight;
        double ratio;
    };
    
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        // build a separate array of value/weight
        // Format: ratio, weight, value
        vector<item> vec;
        int weight_rem = capacity;
        double cost=0;
        
        
        for(int i=0; i<val.size(); i++){
            vec.push_back({val[i], wt[i], (1.0 * val[i])/wt[i]});
        }
        
        // now sort based on weight ratios.
        
        std::sort(vec.begin(), vec.end(), [](const item& a, const item& b){
            return a.ratio > b.ratio;
        });
        
        
        for(const item& itm: vec){
            weight_rem -= itm.weight;
            if(weight_rem >= 0) cost = cost + itm.value; // if 0, in the next step, weight_rem will be negative, in the second case, cost will be cost + 0 as weight_rem is literally (-1 * itm.weight).
            else{
                double rem_value = (itm.weight + weight_rem) * itm.ratio; // Note: weight_rem is negative here, so itm.weight + weight_rem gives the remaining weight that can be taken from this item.
                // Also, we should have done (weight_we_can_fit / itm.weight) * itm.value, but see we can adjust the brackets to get (weight_we_can_fit) * (itm.value / itm.weight) = (weight_we_can_fit) * itm.ratio
                cost+=rem_value;
                break;
            }
            
        }
        
        return cost;
    }
};

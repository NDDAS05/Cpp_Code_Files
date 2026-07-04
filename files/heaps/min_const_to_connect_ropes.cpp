class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        // We need to make sure sum goes up slowly only.
        // So , at every stage we pick the two rows that are of minimum (1st and 2nd minimym)
        // so that sum goes up as slowly as possible.
        // This can be done using min heap.
        // put evey thing in heap
        // pop top 2. Add them, accumulate their cost and put back the resultant rope in the pool
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i: arr) pq.push(i);
        
        // Pop top 2 OR 1 if empty, put the resultant rope back only when there is at least one rope in min heap else we will be stuck in popping putting same rope again and again.
        int totalCost=0, combination, i;
        
        while(true){
            combination = 0;
            for(i=1;!pq.empty() && i<=2;i++){
                combination += pq.top();
                pq.pop();
            } // got top 2 from min heap
            // Calculate cost
            if(i>2) totalCost += combination; // They says: Since there is only one rope, no connections are needed, so the cost is 0. So, i exits when i is no longer <=2. So must be 3.
            if(!pq.empty()) pq.push(combination); // if pq is empty we combined last elements. Why push them again? we will allways in [12] pop12 [] --->push12[12] ---->pop12 [] forever stuck in this.
            
            else break;
        }
        return totalCost;
    }
};
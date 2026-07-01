    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        // Insert everything in max_heap as (element, index)
        // Sorting will be according to the priority of the first element, not the second.
        
        // Then pop. Start currIdx = size-1; 
        // if abs(popped.second - currIdx) <=k continue.
        //Next iteration: currIdx --;
        
        priority_queue<pair<int,int>> pq; // By default in the order of first is main priority. For same first, second acts as tiebreaker
        // Insert <element, index> pairs
        
        for(int i=0; i<n; i++){
            pq.push(pair<int, int>(arr[i], i));
        }
        
        int currIdx = n-1;
        
        while(!pq.empty()){
            if( abs((pq.top()).second - currIdx) > k) return "No";
            currIdx--;
        }
        return "Yes";
    }
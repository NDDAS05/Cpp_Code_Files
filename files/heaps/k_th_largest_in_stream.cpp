// The median problem is fundamentally different, because there we had to find the median of the so far data... that can be kinda treated as n/2th smallest/largest.

// But the n keeps changing there.
// Here k is fixed so we always maintain k elements in heap.
// there n was variable. So when 4, mid is 2nd. For 6 middle is 3. But since upto 4 we were keeping like 2 ele in array we already missed some elements.

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
public:
    KthLargest(int k, vector<int>& nums):limit(k) {
        for(auto i: nums){
            pq.push(i);
            if(pq.size()>limit) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > limit) pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// We can not do single heap based approach because, here if we try to find nth largest as such, n keeps changing
// after every iteration. What that means is we can not keep fixed TOP K ELEMENTS in array like that.

// Since n size changes, the required sample size also changes. Here n is variable. So when 4, mid is 2nd. For 6 middle is 3. But since upto 4 we are keeping like 2 ele in array we already missed some elements.


// Idea: half elements in maxHeap (lower half [ 1 2 3 4 )
// Half elements in minHeap (upper half 5 6 7 8])


// For this when both have same size or max has smaller size: push in max.
// Other wise push in min.
// Might be a case (0)     (7)
// Then 8 comes    (0 8)   (7)

// 8 belongs to the second half... why? for llower half, last ele of lower half is smaller than first ele of the higher/upper half.
// Now 8 < 7

// So after every insertion, we check, if their tops maintain this order or not.
// If they don't, we pop them and place in correct half

// For odd, since when equal sized, elements are pushrf to lower half, maxHeap top is median.
// For even total elements, maxTop + minTop /2.0 is median


// I tried first with "find k-th largest/smallest" approach but got tle!!
// this has complexity of O(2 * n/2 log n/2) = O(nlogn/2)
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int count;

public:
    MedianFinder():count(0){
      // :)  
    }
    
    void addNum(int num) {
        // Keeping 50% on min heap (upper side)
        // 50% on bottom (lower side)
        if(maxHeap.size() <= minHeap.size()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        if((maxHeap.size() * minHeap.size()) != 0 && maxHeap.top() > minHeap.top()){
            int smaller = minHeap.top();
            minHeap.pop();
            int greater = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(smaller);
            minHeap.push(greater);
        }
        count++;
    }
    
    double findMedian() {
        if(count & 1 != 0){
            return maxHeap.top();
        }
        else return ((maxHeap.top() + minHeap.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
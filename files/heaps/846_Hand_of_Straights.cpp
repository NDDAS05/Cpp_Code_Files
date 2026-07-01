// Bellow is not optimal... but something i invented myself :)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // early checking
        if (hand.size() % groupSize != 0)
            return false;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& i : hand) {
            pq.push(i); // ascennding order/min heap
        }
        int prev , i, curr;

        while (!pq.empty()) {
            prev = pq.top() -1;
            vector<int> vec;     // Empty vector 
            for (i = 0; i < groupSize && !pq.empty();) {

                curr = pq.top();
                pq.pop();
                if (curr == prev)
                    vec.push_back(curr); // Push dupplicate for next itr
                else {
                    if (curr - prev != 1)
                        return false;
                    i++;
                }
                prev = curr;
            }
            if(!vec.empty()){
                for(auto& i: vec) pq.push(i);
            }

            if(i<groupSize && pq.empty()) return false;
        }
        return true;
    }
};
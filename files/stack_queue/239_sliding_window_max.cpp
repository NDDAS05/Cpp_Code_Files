class Solution {
public:

/*
Utilizes queue upgraded to deque due to following reasons.
Sliding window problems often lead to repeated work when recalculating the maximum in each window. To identify inefficiencies, consider this: if we move from the window [1,2,3] to [2,3,2], we recalculate the max even though the outgoing element (1) wasn't the maximum.

The real concern is only when the outgoing element was the maximum. To optimize, we use a double-ended queue (deque) to maintain elements in a way that always keeps track of the current maximum efficiently. When a new element enters, we push it to the back of the deque, but before that, we remove all smaller elements from the back since they're not useful anymore. Also, if the element at the front is outside the window's range, we remove it. This ensures that the element at the front of the deque always represents the maximum of the current window.

▶ problem : thinking abt queue
 5 3 4 1 7 2
    If we encounter bigger element,
    we pop everything from front.

    > What if we don't encounter bigger when window slides?
        5
    then 3
        5 3
    then 4
        5 3 4           (this is no longer max.)
                                 ↓
    issue is when 5 goes out:    3 4


So we need something like this:
    when idx out of bounds they exits normally 
    [without disturbing other elements].
     5 X y => (5<-- goes out) X Y Z<-- 

    When we enter new element, it removes
    all elements before it smaller.

            So  5 3
                      4    should be able to 
                5 3 ──┘    remove it.
                           and creep in.

            If it was      5 3 7
                5
                5 3 
                <5─── <3 ── 7  7 should come all
                7            the way to first.


So, out of bound removals from front.
Lesser removal from back.
This naturally is a deque.

Just update the code with these removals.
*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0; i<k; i++){
            // remove from front if goes out of bound.
            // from back if new one is greater than existing ones

            // Here for the initial window window is stationary, no no need to consider "out of bounds" check

            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i); // Index storing.
        }

        // Now sliding logic:
        // pops only when: element goes out of window bounds OR new element is greater than all existing elements

        ans.push_back(nums[q.front()]);
        int qf=1, qb=k; 
        // work is done for the first window. So we start from the second window by advancing window fwd by 1.
        // window advancing does not mean we immediately push/pop it. It just means that we have moved the window and we shall process the queue now. 
        for(; qb<nums.size(); qf++, qb++){
            if(q.front()<qf) q.pop_front(); // Entering elements one by one so goes out of index one by one.

            while(!q.empty() && nums[q.back()] <= nums[qb]){
                q.pop_back();
            }
            q.push_back(qb);
            // after processing the new element we push our ans that is q.front to the final answer.
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
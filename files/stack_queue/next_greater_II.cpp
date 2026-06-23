class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Logic: In linear next greater element, we scan the element from right once so that for any element we encounter fro  right to left, we have already seen their previous elements.

        // But in circular array, The elements before the last one are also after the last one.
        // Say: 3 9 2 4 1.
        // Elements before last (1) are (3 9 2 4) which are after 1 also.
        // So why not loop over it twice? First time we do not know elements before 1. Buut next time we will know for sure because we have already seen the elements before 1 which are after 1 in next itr.

        // So we iterate number of elements * 2 times using the same algo.
        // How to do bounded looping?

        // '/' or '%' ? For size 3 we want to loop ovr 0, 1, 2 : Clearly %
        // Now, we do not want 3 so %3
        // Can we take i % 3?
        // 2%3 =2, 1%3=1, 0%3=0, -1%3 = (-1) NOT 2

        // So we try (3+i)% 3.
        // Adding any multiple of divisor only changes division result, NOT the remainder.
        // Here (3 -1)%3 is 2
        // So this works

        // unordered_map<int, int> ump; processing all elements by index. hashmap needed if we had only a few specific indices to check. but we are checking all anyway so no need of map.

        stack<int> s;
        vector<int> ans(nums.size(), -1);

        // Loop twice to update.
        int size = nums.size();
        int i = size - 1;
        int loop = size*2;
        while(loop--){
            i = (size + i) % size;
            while(!s.empty()){
                // Important: for duplicates, >= is important as we pop untill stk.top is strictly greater than nums[i]
                if(nums[i] >= s.top()) s.pop();
                else break;
            }
            // Now stack is either empty or holding the element next greater than current nums[i] at top.

            // One more change: Here we stor <index, next greater> cuz for duplicate element, they overwrite each other

            ans[i] = (s.empty()) ? (-1) : (s.top());
            s.push(nums[i]);
            // CRUCIAL: Update i
            i--;
        }
        return ans;

    }
};
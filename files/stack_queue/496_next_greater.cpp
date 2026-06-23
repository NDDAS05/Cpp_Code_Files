class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // See next greater element pattern from Copy.
        // Here the twist is that we have to return the "next greater element" of some specific elements in the exact specific order.
        // So we need to track the element too.
        // For O(m+n) solutiom, we need to use hash map.
        // Just register the elements with all thier key = nums1 element
        // And value = (-1)

        // hasm map is only used cuz we have to return NGE of some specific elements not all.
        // But if we had to return NGE of all elements, only the result array was sufficient.

        // While doing the monotonic stack operation, we will update them in order.

        unordered_map<int, int> ump;
        stack<int> stk;
        vector<int> ans;

        // First traverse the nums2 in reverse order.
        for(int i= nums2.size() -1; i>=0; i--){
            // if stack is empty current elements next greater is -1.
            while(!stk.empty()){
                if( nums2[i] > stk.top() ){
                    stk.pop();
                }
                else break;
            }
            // If stack is empty, then next greater of the current one is not there.
            // In that case, next greater of nums2[i] = -1
            // Else (we popped something or not), next greater is stack.top
            ump[nums2[i]] = ((stk.empty()) ? (-1) : (stk.top()));
            stk.push(nums2[i]);
        }

        // Now we just fill in the vector ans from the map
        for(auto i: nums1){
            ans.push_back(ump[i]);
        }
        return ans;
    }
};
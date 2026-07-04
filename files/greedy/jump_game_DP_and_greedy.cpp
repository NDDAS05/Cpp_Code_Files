class Solution {
    
public:
    bool canJump(vector<int>& nums) {
        vector<int> boolArr(nums.size(), 0);
        boolArr[boolArr.size()-1] = 1; // Can always reach last idx from last idx

        if(nums.size() == 1) return true;

        for(int i=nums.size()-2; i>=0; i--) // Excluding the last index too
        {
            int check_limit = (i+nums[i] > nums.size()-1) ? nums.size()-1 : i+nums[i];

            for(int j= check_limit; j>i; j--){
                if(boolArr[j] == 1){
                    if(i==0) return true;
                    boolArr[i] = 1; // confirmed from i we can go to end
                    break;
                }
                // if zero, we keep coming back.
            }
        }
        return false;
    }
};

// But this keeps many unnecessary steps.
// You'll realize you never needed an entire DP array. You only needed to remember the leftmost index that is already known to reach the end.

// Maintain a variable goal, initially equal to n - 1.
// While iterating from right to left, under what condition should you update goal = i?

//since for every i, the range of jump is 1 to i+nums[i], if at least one good index is there, my current i is also good because it can make me go to another good index which leads to final. Since we are traversing from right to left, and keeping track of left most good index, if my range of jump does not even include the left most good (which is closest to it), then there is no way this leads to final answer. So last good index stays the same. (if i+nums[i] < left_most_good_Index_so_far) then it left most good index stays same, otherwise , leftmost good index is updated to current i. I just did not think about the "range of jump" about hard enough previously. Also if range of jump at index i=0 includes a good index then answer is true... else false

// Start with a DP formulation.
Ask, "Do I really need all these states?"
If all the information you need can be summarized by one variable (here, the leftmost good index),
 the DP often compresses into a greedy algorithm.

// Greedy solution: <more like DP compression.>

// Greedy in a sense that we shrinked our target with left_most_good at any chance we got.
// But never think about it first.
// Think about other solutions, then think if the states they are remembering are unnecessary or not.

class Solution {
    
public:
    bool canJump(vector<int>& nums) {
        // greedy solution:
        int left_most_good = nums.size()-1;

        // if(nums.size() == 1) return true;

        for(int i = nums.size()-1; i>= 0; i--){
            if(i + nums[i] >= left_most_good) left_most_good = i;
            if(left_most_good == 0) return true;
        }
        return false;
    }
};
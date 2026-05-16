#include<bits/stdc++.h>
using namespace std;

/*
============================
Given an unsorted array of integers nums, 
return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

============================
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 
=============================
Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
=============================
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Data structure: SET
        // Concept: Set allows to SORT ALL UNIQUE ELEMENTS
        // In this problem unique does not matter cuz  0 1 |  2 1 3 0 
        // max seq length would be 4 
        // not 0 0 1 1 2 3

        // 1. Put data into set.
        set<int> st;
        for(auto i: nums) st.insert(i);

        // 2. Traverse the set (It will be sorted)
        int sequence_count=0, prev_element = INT_MIN, max_seq_seen=0;
        for(auto i: st)
        {
            if(i == prev_element+1) sequence_count++;
            else sequence_count = 1;
            if(max_seq_seen < sequence_count) max_seq_seen = sequence_count;
            prev_element = i;
        }
        return max_seq_seen;
    }
};
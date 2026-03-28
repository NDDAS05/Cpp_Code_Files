#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Last one was SET: This was O(nlogn) because each insert was logn.
        // Better is unordered map: technically a hash but with dup handling and SINGLE VALUED. (not key-value pairs)

        // 1. Put data in set.
        unordered_set<int> u_set;
        for(auto num: nums)  u_set.insert(num);

        // For an unordered set, insert: O(1) avg
        //                        erase: O(1) avg
        //                         find: O(1) avg

        /*
        If we start checking every element and its sequence, it will be very bad. May go upto O(n!) for an ascending contiguous array.
        BUT
        if we only check from the starting element, we can skip the elements that might bw in midst of a seq.
        Like, 1 4 2 3 8 5 9
        We count for 1 as 0 not there
        Skip 4 cuz 3
        Skip 2 cuz 1
        Skip 3 cuz 2
        Count for 8
        Skip 5 for 4
        skip 9 for 8
        */

        int max_length_seq = 0;

        for(auto &element : u_set)
        {
            int seqence_count = 0;
            // if not found
            if(u_set.find(element-1) == u_set.end())
            {
                int j=0;
                while(u_set.find(element+j) != u_set.end())
                {
                    seqence_count++;
                    j++;
                    // sequence count can be removed as as per code seq_count only increments with j
                    // and both resets to 0 before their increment operation.
                }
                max_length_seq = max(seqence_count, max_length_seq);
            }
        }
        return max_length_seq;
    }
};
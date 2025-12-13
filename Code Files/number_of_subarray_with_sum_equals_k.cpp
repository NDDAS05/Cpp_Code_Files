#include <bits/stdc++.h>
#define endl std::endl

class Solution
{
public:
    int numberOfSubarrays(std::vector<int> &nums, int k)
    {
        int subarrCount = 0, prefixSum = 0, i = 0, size = (int)nums.size();
        std::unordered_map<int, int> mp; // Map structure: key: prefixSum, value: count
        mp[0] = 1;

        for (;i < size;i++)
        {
            prefixSum += nums[i];
            int rem = prefixSum - k;
            // Do not add immidiately in map, we need to check already existing, not after putting.
            // Example case: say preSum=5, k=0, nums=[5]
            // So we search 5 in map.
            // If we put 5 b4, we will see it exists once, so subarrcount 0->1
            // But if we check after- we make it sure that we are checking against already existing entries, entry will not be in map so count STAYS AT 0

            if (mp.find(rem) != mp.end()) // So we found it
            {
                subarrCount += mp[rem]; // Count increases by how many times s-k exists in array
            }
            //Equivalently subarrCount+=mp[rem] -> It creates a key if doesn't exist, sets count to 0, adds to subarrcount. If exists then increases count
            mp[prefixSum]++; // Regardless found or not, count, or mp[prefixSum] increases by 1 [If key does not exists, it creates a key and sets value to 0]
        }
        return subarrCount;
    }
};

int main()
{
    int result;
    std::vector<int> vec={1,1,1,-3,3};
    Solution s;
    result=s.numberOfSubarrays(vec, 3);
    std::cout<<result<<endl;
    return 0;
}
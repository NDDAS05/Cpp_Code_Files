// Heap solution is directly visible.
// Make hash of element:freq,
// Push the "REVERSE PAIR" (freq, element)[freq more priority] into MINheap
// While pushing, maintain a k limit, elements after k will be popped.
// So after heap ends remaining k elements in heap are most freq. Build a array of .second s and return it.

// Bellow is a counting sort (or bucket sort here) algo

// Loop can be fixed by cleaner approach, but idea is same.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Logic: first find out freq of evry element
        // Create a bucket: where elememts appearing !$ times are put in !$ index.
        // Index is freq, value is bucket[!$]

        // Traverse the thing from end collect the values.

        unordered_map<int, int> freq;
        for(auto i: nums){
            freq[i]++;
        }

        // How many times an element can appear at max? In an array of size k, k times only.
        // But array is 0 indexed, in bucket sort, this 0 is frequency.
        // Not possible (elements can not "occur" 0 times). So array size n+1 instead.

        vector<vector<int>> bucket(nums.size()+1);

        for(auto i:freq){
            bucket[i.second].push_back(i.first);
        }

        int i=nums.size();
        vector<int> kFreq;
        while(i>=0  && k>0){
            if(bucket[i].size() != 0){
                int j;
                for(j= 0; j<bucket[i].size() && j<k; j++) kFreq.push_back(bucket[i][j]);
                k=k-j;
            }
            i--;
        }
        return kFreq;
    }
};
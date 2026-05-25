class Solution {
	public:
	
	bool cowPlaced(vector<int>& nums, int min_dist, int cow_no) {
		int placed = 1; // one placed at min_ele of array
		int lastPlaced_idx = 0;
		for (int i = 1; i<nums.size(); i++) {
			if (nums[i]-nums[lastPlaced_idx] >= min_dist) {
				// i.e. placed.
				placed++;
				lastPlaced_idx = i;
			}
		}
		if (placed >= cow_no)
			return true;
		return false;
	}
	
	int aggressiveCows(vector<int> &stalls, int k) {
		
		sort(stalls.begin(), stalls.end());
		int low = 1;
		int high = stalls.back() - stalls.front();
		// Returns last and first ele of stall
		int mid, ans = -1;
		
		while (low <= high) {
			mid = low + ((high - low)/2);
			if (cowPlaced(stalls, mid, k)) {
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
		
		return ans;
	}
};

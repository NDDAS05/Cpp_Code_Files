// The exact same problem as sum of subarray minimum: Just written again this time for maximum also.
// Sum of subarray ranges = sum (subarray_max - subarray_min) over all subarrays
// -----------------------> sum(subrray_max) - sum(subarray_min) over all subarrays.

// sum (subarray_min) is LeetCode problem 907 solved already.
// Check: Why stack gives O(n) time.


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> stk_fwd;
        stack<int> stk_back;
        stack<int> gstk_fwd;
        stack<int> gstk_back;

        vector<pair<int, int>> vec_min(nums.size(), pair<int, int>(-1, -1));
        vector<pair<int, int>> vec_max(nums.size(), pair<int, int>(-1, -1));

        int size = nums.size();

        for (int i = 0, j = size - 1; i < size && j >= 0; i++, j--) {
            while (!stk_fwd.empty()) {
                if (nums[stk_fwd.top()] > nums[i])
                    stk_fwd.pop();
                else
                    break;
            }

            while (!stk_back.empty()) {
                if (nums[stk_back.top()] >= nums[j])
                    stk_back.pop();
                else
                    break;
            }
            vec_min[i].first = (stk_fwd.empty()) ? (-1) : stk_fwd.top();
            vec_min[j].second = (stk_back.empty()) ? (size) : stk_back.top();
            stk_fwd.push(i);
            stk_back.push(j);
        }

        for (int i = 0, j = size - 1; i < size && j >= 0; i++, j--) {
            while (!gstk_fwd.empty()) {
                if (nums[gstk_fwd.top()] < nums[i])
                    gstk_fwd.pop();
                else
                    break;
            }

            while (!gstk_back.empty()) {
                if (nums[gstk_back.top()] <= nums[j])
                    gstk_back.pop();
                else
                    break;
            }
            vec_max[i].first = (gstk_fwd.empty()) ? (-1) : gstk_fwd.top();
            vec_max[j].second = (gstk_back.empty()) ? (size) : gstk_back.top();
            gstk_fwd.push(i);
            gstk_back.push(j);
        }

        long long sum = 0;
        for (int i = 0; i < vec_min.size(); i++) {
            long long left_min = i - vec_min[i].first;
            long long right_min = vec_min[i].second - i;

            long long left_max = i - vec_max[i].first;
            long long right_max = vec_max[i].second - i;

            long long val_min = (left_min * right_min) * nums[i];
            long long val_max = (left_max * right_max) * nums[i];
            sum = (sum + val_max - val_min);
        }

        return sum;
    }
};
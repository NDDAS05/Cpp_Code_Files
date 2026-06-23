// Optimal Soln requires Requires an advanced data structure (BIT/Segment Tree) for the truly optimal solution.

/*Given an array of arr[] and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).

Examples :

Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output:  [6, 1]
Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.
Input: arr[] = [1, 2, 3, 4, 1], queries = 2, indices[] = [0, 3]
Output:  [3, 0]
Explanation: The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4). Similarly, the count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.
Constraints:
1 ≤ N ≤ 104
1 ≤ arr[i] ≤ 105
1 ≤ queries ≤ 100
0 ≤ indices[i] ≤ N - 1
*/


class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // Not Same as NGE code.
        // Cuz what stack contains depends on order of elements. Number of elements in the stack does not equals number of elements greater than current one.
        // Say: 2 8 7
        // for 7 stk  [] then [7]
        // For 8 stk [7]->[]->[8]
        // For 2 stk [8]->[2,8] (See only 1 cuz 8 eliminated elements smaller than it that comes after 8)
        
        // Just count bruteforcely
        vector<int> ans(indices.size(), -1);
        int count = 0, val;
        
        for(int i=0; i<indices.size(); i++){
            count = 0;
            for(int j=indices[i]+1; j<arr.size();j++){
                if(arr[j] > arr[indices[i]]) count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};
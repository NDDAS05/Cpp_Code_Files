# How to IDENTIFY Which DSA Pattern to Use — Decision Guide + C++ Templates

Stop memorizing solutions. Start recognizing patterns.

This guide answers the one question nobody properly answers:

> "I see a new problem — how do I know WHICH pattern to apply?"

Most pattern lists only teach solutions. Interviews test whether you can recognize the pattern in a completely new problem.

This guide focuses on:
- Pattern recognition
- Trigger questions
- Constraints analysis
- Reusable templates

---

# 📌 The Core Problem With How Most People Study DSA

Most people do this:

```text
See problem → look at tags → learn solution → move on
```

This causes blank-outs during interviews because you memorized a solution, not a reusable pattern.

The correct process is:

```text
See problem
→ Read constraints
→ Ask trigger questions
→ Identify pattern
→ Apply template
```

This guide gives you:
- Trigger questions
- Identification signals
- C++ templates
- Practice problems

---

# 🗺️ Master Decision Tree

When you open a new problem, ask these questions in order:

```text
Q1. Does the problem involve a CONTIGUOUS subarray or substring?
    └── YES → Sliding Window or Prefix Sum

Q2. Is the input SORTED (or can I sort it)?
    ├── YES + looking for pair/triplet → Two Pointers
    └── YES + looking for index/value → Binary Search

Q3. Does the problem involve a LINKED LIST?
    ├── Detect cycle / find middle → Fast & Slow Pointers
    └── Reverse / merge → Standard Linked List operations

Q4. Does the problem involve a TREE or GRAPH?
    ├── Level-by-level / shortest path → BFS
    ├── Explore all paths / connected components → DFS
    └── Dependencies / ordering → Topological Sort

Q5. Does the problem ask for ALL combinations / subsets / permutations?
    └── → Backtracking

Q6. Does the problem ask for OPTIMAL value (min/max/count)?
    ├── Overlapping subproblems → Dynamic Programming
    └── Greedy choice works → Greedy

Q7. Does the problem involve a STACK-shaped structure?
    └── Matching brackets / next greater element → Monotonic Stack
```

---

# Pattern 1 — Sliding Window

## 🔍 How to Identify

Use Sliding Window when:
- Problem involves subarray or substring
- Need max/min/count within a contiguous range
- Brute force uses nested loops over same array

## 🚦 Trigger Keywords

```text
longest
shortest
maximum sum
at most k
exactly k
contiguous
window
```

---

## ✅ C++ Template — Fixed Window

```cpp
int maxSumSubarray(vector<int>& nums, int k) {
    int windowSum = 0, maxSum = 0;

    // Build first window
    for (int i = 0; i < k; i++)
        windowSum += nums[i];

    maxSum = windowSum;

    // Slide window
    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
```

---

## ✅ C++ Template — Variable Window

```cpp
int longestSubstring(string s, int k) {
    unordered_map<char, int> freq;

    int left = 0;
    int result = 0;

    for (int right = 0; right < s.size(); right++) {

        freq[s[right]]++;

        // Shrink window if condition breaks
        while (/* condition violated */) {

            freq[s[left]]--;

            if (freq[s[left]] == 0)
                freq.erase(s[left]);

            left++;
        }

        result = max(result, right - left + 1);
    }

    return result;
}
```

---

## 📝 Practice Problems

- #3 Longest Substring Without Repeating Characters  
  https://leetcode.com/problems/longest-substring-without-repeating-characters/

- #76 Minimum Window Substring  
  https://leetcode.com/problems/minimum-window-substring/

- #239 Sliding Window Maximum  
  https://leetcode.com/problems/sliding-window-maximum/

- #424 Longest Repeating Character Replacement  
  https://leetcode.com/problems/longest-repeating-character-replacement/

---

# Pattern 2 — Prefix Sum

## 🔍 How to Identify

Use Prefix Sum when:
- Multiple subarray sum queries exist
- Need cumulative information
- Problem says:
  - "Subarray sum equals k"
  - "Range sum query"

## 🚦 Trigger Keywords

```text
sum of subarray
range sum query
number of subarrays with sum
cumulative sum
```

---

## ✅ C++ Template

```cpp
// Build prefix sum
vector<int> prefix(n + 1, 0);

for (int i = 0; i < n; i++)
    prefix[i + 1] = prefix[i] + nums[i];

// Query sum of nums[l...r]
int rangeSum = prefix[r + 1] - prefix[l];
```

---

## ✅ Subarray Sum Equals K Variant

```cpp
int subarraySumEqualsK(vector<int>& nums, int k) {

    unordered_map<int, int> prefixCount;

    prefixCount[0] = 1;

    int sum = 0;
    int count = 0;

    for (int num : nums) {

        sum += num;

        count += prefixCount[sum - k];

        prefixCount[sum]++;
    }

    return count;
}
```

---

## 📝 Practice Problems

- #560 Subarray Sum Equals K  
  https://leetcode.com/problems/subarray-sum-equals-k/

- #238 Product of Array Except Self  
  https://leetcode.com/problems/product-of-array-except-self/

- #303 Range Sum Query - Immutable  
  https://leetcode.com/problems/range-sum-query-immutable/

---

# Pattern 3 — Two Pointers

## 🔍 How to Identify

Use Two Pointers when:
- Array is sorted
- Looking for pair/triplet
- Comparing from both ends
- Need in-place partitioning

## 🚦 Trigger Keywords

```text
sorted array
pair with sum
two elements
move in-place
triplet
```

---

## ✅ Opposite Direction Template

```cpp
int left = 0;
int right = nums.size() - 1;

while (left < right) {

    int sum = nums[left] + nums[right];

    if (sum == target)
        return {left, right};

    else if (sum < target)
        left++;

    else
        right--;
}
```

---

## ✅ Same Direction (Fast/Slow) Template

```cpp
int slow = 0;

for (int fast = 0; fast < nums.size(); fast++) {

    if (nums[fast] != nums[slow]) {

        slow++;

        nums[slow] = nums[fast];
    }
}
```

---

## 📝 Practice Problems

- #167 Two Sum II - Input Array Is Sorted  
  https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

- #15 3Sum  
  https://leetcode.com/problems/3sum/

- #11 Container With Most Water  
  https://leetcode.com/problems/container-with-most-water/

- #75 Sort Colors  
  https://leetcode.com/problems/sort-colors/

---

# Pattern 4 — Binary Search

## 🔍 How to Identify

Use Binary Search when:
- Input is sorted
- Answer space is monotonic
- O(log n) expected
- Need minimum/maximum feasible value

## 🚦 Trigger Keywords

```text
sorted
rotated sorted
find position
minimum feasible value
kth element
```

---

## ✅ Classic Binary Search Template

```cpp
int binarySearch(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}
```

---

## ✅ Binary Search on Answer

```cpp
int left = minPossible;
int right = maxPossible;

while (left < right) {

    int mid = left + (right - left) / 2;

    if (condition(mid))
        right = mid;

    else
        left = mid + 1;
}

return left;
```

---

## 📝 Practice Problems

- #704 Binary Search  
  https://leetcode.com/problems/binary-search/

- #33 Search in Rotated Sorted Array  
  https://leetcode.com/problems/search-in-rotated-sorted-array/

- #153 Find Minimum in Rotated Sorted Array  
  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

- #875 Koko Eating Bananas  
  https://leetcode.com/problems/koko-eating-bananas/

---

# Pattern 5 — Fast & Slow Pointers

## 🔍 How to Identify

Use when:
- Linked list has cycle-related operations
- Need middle node
- Two objects move at different speeds

## 🚦 Trigger Keywords

```text
cycle
middle
linked list
tortoise and hare
```

---

## ✅ C++ Template

```cpp
// Detect cycle

ListNode* slow = head;
ListNode* fast = head;

while (fast && fast->next) {

    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
        return true;
}

return false;
```

---

## ✅ Find Middle Node

```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast && fast->next) {

    slow = slow->next;
    fast = fast->next->next;
}

// slow is at middle
```

---

## 📝 Practice Problems

- #141 Linked List Cycle  
  https://leetcode.com/problems/linked-list-cycle/

- #142 Linked List Cycle II  
  https://leetcode.com/problems/linked-list-cycle-ii/

- #876 Middle of the Linked List  
  https://leetcode.com/problems/middle-of-the-linked-list/

- #234 Palindrome Linked List  
  https://leetcode.com/problems/palindrome-linked-list/

---

# Pattern 6 — BFS (Breadth First Search)

## 🔍 How to Identify

Use BFS when:
- Need shortest path in unweighted graph
- Need level-order traversal
- Need minimum steps
- Multi-source spreading problems

## 🚦 Trigger Keywords

```text
shortest path
minimum distance
level order
nearest
minimum steps
```

---

## ✅ Graph BFS Template

```cpp
void bfs(int start, vector<vector<int>>& graph) {

    queue<int> q;
    unordered_set<int> visited;

    q.push(start);
    visited.insert(start);

    int level = 0;

    while (!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {

            int node = q.front();
            q.pop();

            // Process node

            for (int neighbor : graph[node]) {

                if (!visited.count(neighbor)) {

                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        level++;
    }
}
```

---

## 📝 Practice Problems

- #102 Binary Tree Level Order Traversal  
  https://leetcode.com/problems/binary-tree-level-order-traversal/

- #994 Rotting Oranges  
  https://leetcode.com/problems/rotting-oranges/

- #200 Number of Islands  
  https://leetcode.com/problems/number-of-islands/

- #127 Word Ladder  
  https://leetcode.com/problems/word-ladder/

---

# Pattern 7 — DFS (Depth First Search)

## 🔍 How to Identify

Use DFS when:
- Need to explore all paths
- Need connected components
- Solving recursive tree problems

## 🚦 Trigger Keywords

```text
all paths
connected
explore
count
exists a path
```

---

## ✅ Graph DFS Template

```cpp
void dfs(int node,
         vector<vector<int>>& graph,
         vector<bool>& visited) {

    visited[node] = true;

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {

            dfs(neighbor, graph, visited);
        }
    }
}
```

---

## 📝 Practice Problems

- #104 Maximum Depth of Binary Tree  
  https://leetcode.com/problems/maximum-depth-of-binary-tree/

- #543 Diameter of Binary Tree  
  https://leetcode.com/problems/diameter-of-binary-tree/

- #417 Pacific Atlantic Water Flow  
  https://leetcode.com/problems/pacific-atlantic-water-flow/

- #130 Surrounded Regions  
  https://leetcode.com/problems/surrounded-regions/

---

# Pattern 8 — Topological Sort

## 🔍 How to Identify

Use when:
- Dependencies exist
- Directed Acyclic Graph (DAG)
- Need valid ordering

## 🚦 Trigger Keywords

```text
prerequisites
ordering
dependency
before
schedule
```

---

## ✅ Kahn's Algorithm Template

```cpp
vector<int> topoSort(int n,
                     vector<vector<int>>& edges) {

    vector<int> indegree(n, 0);
    vector<vector<int>> graph(n);

    for (auto& e : edges) {

        graph[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {

        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        order.push_back(node);

        for (int neighbor : graph[node]) {

            if (--indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return order.size() == n
           ? order
           : vector<int>{};
}
```

---

## 📝 Practice Problems

- #207 Course Schedule  
  https://leetcode.com/problems/course-schedule/

- #210 Course Schedule II  
  https://leetcode.com/problems/course-schedule-ii/

- #310 Minimum Height Trees  
  https://leetcode.com/problems/minimum-height-trees/

---

# Pattern 9 — Backtracking

## 🔍 How to Identify

Use when:
- Need ALL solutions
- Generating combinations/permutations/subsets
- Constraints prune invalid branches

## 🚦 Trigger Keywords

```text
all combinations
generate all
permutations
subsets
valid arrangements
```

---

## ✅ C++ Template

```cpp
void backtrack(vector<int>& current,
               vector<vector<int>>& result,
               vector<int>& nums,
               int start) {

    result.push_back(current);

    for (int i = start; i < nums.size(); i++) {

        current.push_back(nums[i]);

        backtrack(current, result, nums, i + 1);

        current.pop_back();
    }
}
```

---

## 📝 Practice Problems

- #78 Subsets  
  https://leetcode.com/problems/subsets/

- #46 Permutations  
  https://leetcode.com/problems/permutations/

- #39 Combination Sum  
  https://leetcode.com/problems/combination-sum/

- #79 Word Search  
  https://leetcode.com/problems/word-search/

- #131 Palindrome Partitioning  
  https://leetcode.com/problems/palindrome-partitioning/

---

# Pattern 10 — Dynamic Programming

## 🔍 How to Identify

Use DP when:
- Need optimal answer
- Subproblems repeat
- Recursive brute force gives TLE

## 🚦 Trigger Keywords

```text
minimum cost
maximum profit
number of ways
can you reach
longest
fewest
```

---

## 🧪 Quick Test

If you can define:

```text
dp[i]
```

using:
```text
dp[i-1]
dp[j]
```

where `j < i`, it is probably DP.

---

## ✅ 1D DP Template

```cpp
int dp[n];

dp[0] = nums[0];
dp[1] = max(nums[0], nums[1]);

for (int i = 2; i < n; i++) {

    dp[i] = max(dp[i - 1],
                dp[i - 2] + nums[i]);
}

return dp[n - 1];
```

---

## 📝 Practice Problems

- #70 Climbing Stairs  
  https://leetcode.com/problems/climbing-stairs/

- #198 House Robber  
  https://leetcode.com/problems/house-robber/

- #322 Coin Change  
  https://leetcode.com/problems/coin-change/

- #62 Unique Paths  
  https://leetcode.com/problems/unique-paths/

- #139 Word Break  
  https://leetcode.com/problems/word-break/

- #300 Longest Increasing Subsequence  
  https://leetcode.com/problems/longest-increasing-subsequence/

---

# Pattern 11 — Monotonic Stack

## 🔍 How to Identify

Use when:
- Need next greater/smaller element
- Histogram problems
- Need ordered maintenance during scan

## 🚦 Trigger Keywords

```text
next greater
previous smaller
temperatures
histogram
stock span
```

---

## ✅ C++ Template

```cpp
vector<int> nextGreater(vector<int>& nums) {

    int n = nums.size();

    vector<int> result(n, -1);

    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() &&
               nums[st.top()] < nums[i]) {

            result[st.top()] = nums[i];
            st.pop();
        }

        st.push(i);
    }

    return result;
}
```

---

## 📝 Practice Problems

- #496 Next Greater Element I  
  https://leetcode.com/problems/next-greater-element-i/

- #739 Daily Temperatures  
  https://leetcode.com/problems/daily-temperatures/

- #84 Largest Rectangle in Histogram  
  https://leetcode.com/problems/largest-rectangle-in-histogram/

- #853 Car Fleet  
  https://leetcode.com/problems/car-fleet/

---

# 🎯 Quick Reference Cheat Sheet

| If you see... | Think... |
|---|---|
| Contiguous subarray + max/min/count | Sliding Window |
| Subarray sum = k | Prefix Sum + HashMap |
| Sorted array + pair/triplet | Two Pointers |
| Sorted array + find element | Binary Search |
| Minimum X satisfying condition | Binary Search on Answer |
| Linked list + cycle | Fast & Slow Pointers |
| Shortest path / level order | BFS |
| All paths / connected components | DFS |
| Dependencies / prerequisites | Topological Sort |
| All combinations / permutations | Backtracking |
| Min/Max with overlapping subproblems | Dynamic Programming |
| Next greater / previous smaller | Monotonic Stack |
| Matching brackets | Stack |
| Top K elements | Heap / QuickSelect |

---

# ⚠️ The 3 Most Common Mistakes

## 1. Jumping to code immediately

Wrong approach:

```text
Read → Start coding
```

Correct approach:

```text
Read
→ Identify constraints
→ Ask trigger questions
→ Identify pattern
→ THEN code
```

---

## 2. Not knowing when to use BFS vs DFS

```text
Need SHORTEST path? → BFS

Need to explore ALL paths? → DFS

Both work for connectivity?
→ DFS is usually simpler
```

---

## 3. Treating DP as magic

DP is just:

```text
Recursion
→ Memoization
→ Bottom-up Tabulation
```

Workflow:

```text
Recursive brute force (TLE)
→ Add memoization
→ Convert to iterative DP
```

---

# 💡 How to Actually Use This Guide

1. Open a new problem
2. Do NOT look at tags
3. Run through the Master Decision Tree
4. Match the problem to a pattern
5. Apply the template structure
6. Adapt template to the problem
7. Check tags only AFTER committing to an approach

---

# 🚀 Final Goal

Do this consistently for ~30 problems per pattern.

Eventually:
- Pattern recognition becomes automatic
- You stop memorizing solutions
- You start solving unseen problems confidently
- Interviews become much easier

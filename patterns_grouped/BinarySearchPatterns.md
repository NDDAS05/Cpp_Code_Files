# [title:Important BS Questions]# 1. Classic Binary Search (Exact Search)

Core idea:
- Array is sorted
- Find exact target
- Eliminate one half every step

Recognition:
- "Find x in sorted array"
- "Return index of target"
- O(log n) expected

Typical Problems:
- Binary Search (#704)
- Search Insert Position (#35)
- Guess Number Higher or Lower (#374)

--------------------------------------------------

# 2. First/Last Occurrence (Lower Bound / Upper Bound)

Core idea:
- Duplicates exist
- Need boundary positions
- Continue searching even after finding target

Recognition:
- "First occurrence"
- "Last occurrence"
- "Count occurrences"
- "Insert position"
- "Smallest greater than"

Subtypes:
- Lower Bound → first >= target
- Upper Bound → first > target

Typical Problems:
- Find First and Last Position (#34)
- Search Insert Position (#35)
- Find Smallest Letter Greater Than Target (#744)
- First Bad Version (#278)

--------------------------------------------------

# 3. Rotated Sorted Array Problems

Core idea:
- Array was sorted, then rotated
- At least one half is always sorted

Recognition:
- "Rotated sorted array"
- Pivot rotation
- Circular ordering

Typical Problems:
- Search in Rotated Sorted Array (#33)
- Search in Rotated Sorted Array II (#81)
- Find Minimum in Rotated Sorted Array (#153)
- Find Minimum in Rotated Sorted Array II (#154)

Main trick:
- Detect which half is sorted

--------------------------------------------------

# 4. Peak / Valley Problems

Core idea:
- Use slope/property instead of sortedness
- Move toward increasing/decreasing side

Recognition:
- "Peak element"
- Local maxima/minima
- Mountain array

Typical Problems:
- Find Peak Element (#162)
- Peak Index in Mountain Array (#852)
- Find in Mountain Array (#1095)

Main observation:
- If nums[mid] < nums[mid+1]
  peak lies right
- else left

--------------------------------------------------

# 5. Binary Search on Answer (MOST IMPORTANT)

Core idea:
- Binary search on possible answer space
- Use feasibility function:
  can(mid) = true/false

Recognition:
- "Minimum possible"
- "Maximum possible"
- Capacity/speed/days/rate/time
- Optimization problem

Huge clue:
Answer space behaves like:
false false false true true true

Typical Problems:
- Koko Eating Bananas (#875)
- Capacity To Ship Packages Within D Days (#1011)
- Split Array Largest Sum (#410)
- Minimum Days to Make m Bouquets (#1482)
- Minimum Speed to Arrive on Time (#1870)

Main mindset:
"Can I check whether answer = X works?"

--------------------------------------------------

# 6. Binary Search on Monotonic Function

Core idea:
- Predicate/function changes monotonically

Recognition:
- Monotonic condition
- Increasing/decreasing function
- Threshold finding

Typical Problems:
- First Bad Version (#278)
- Sqrt(x) (#69)
- Valid Perfect Square (#367)

--------------------------------------------------

# 7. Matrix Binary Search

Core idea:
- Treat matrix as sorted structure

Recognition:
- Sorted rows/columns
- Search in matrix

Subtypes:

A) Fully flattened sorted matrix
- Treat as 1D array

Problems:
- Search a 2D Matrix (#74)

B) Row-column sorted matrix
- Use matrix properties carefully

Problems:
- Search a 2D Matrix II (#240)

--------------------------------------------------

# 8. Search in Infinite / Unknown Sized Space

Core idea:
- Search range not known initially
- Expand bounds first

Recognition:
- Infinite array
- Unknown size
- Hidden API

Typical Problems:
- Search in a Sorted Array of Unknown Size (#702)

Main trick:
- Exponential expansion
- Then normal binary search

--------------------------------------------------

# 9. Binary Search + Greedy

Core idea:
- Greedy feasibility check inside binary search

Recognition:
- Partitioning
- Allocation
- Scheduling

Typical Problems:
- Split Array Largest Sum (#410)
- Ship Packages Within D Days (#1011)

--------------------------------------------------

# 10. Hard Mathematical / Partition Binary Search

Core idea:
- Binary search on partitions/indexes
- Usually harder reasoning

Recognition:
- Two sorted arrays
- Partition correctness

Typical Problems:
- Median of Two Sorted Arrays (#4)
- K-th Smallest Element problems

--------------------------------------------------

# 11. Interactive Binary Search

Core idea:
- Use API feedback

Recognition:
- Hidden API
- Interactive judge

Typical Problems:
- Guess Number Higher or Lower (#374)
- First Bad Version (#278)

--------------------------------------------------

# 12. Hybrid Binary Search Problems

These combine binary search with:
- Graphs
- DP
- Prefix sums
- Hashing
- Sliding window

Examples:
- Maximum Value at a Given Index (#1802)
- Find K Closest Elements (#658)
- Time Based Key-Value Store (#981)
Monotonic Stack Pattern

For each element:
    Find the range/span where it remains relevant.

Minimum  -> Previous Smaller + Next Smaller
Maximum  -> Previous Greater + Next Greater

class Solution {

public:

// Say 3 1 2 4 subarray.

// Now, we do not need subarray sum- we need "minimum" subarray sum.

// for here:

// 3 1 (2,4)

// -   (2)

//     (-)



// For these 2*3 = 6 subarrays minimum is 1.

// How long does minimum span?

// from the current index: Next index smaller than current,

                        // Previous index smaller than current.



// So this problem can be solved if we know "NEXT SMALLER ELEMENT" and "PREVIOUS SMALLER ELEMENT" for every element of the array.



// Thus this becomes a "Stack Problem".

// All these problems where there is a "span" of elements, stack may be an option.

// We will attempt to find next min in both backward and fwd loop to find minimum from fwd and min from backward.

int sumSubarrayMins(vector<int>& arr) {

    stack<int> stk_fwd;

    stack<int> stk_back;

    long long mod = 1000000007;

    // Invalid: vector<pair<int,int>> vec(arr.size(), {-1, -1});

    vector<pair<int,int>> vec(arr.size(), pair<int,int>(-1, -1));





    int size = arr.size();

    for(int i=0, j=size-1; i<size && j>=0; i++, j--){

        // fwd loop to get previous smaller

        // Stack fwd for forward loop

        // Backward loop to get next smaller.

        // Stack bck for backward loop.



        while(!stk_fwd.empty())

        {

            // As long as not empty

            // Keep popping untill we get our first element that is "lesser" than current element.

// If there are arrays like 2 3 2 4 say...
//for left 2 subarry would be 2 3 2 4 (if 2 is not limiting)
// for middle 2, subarray is also 2 3 2 4 if prev 2 js not limiting.
// So one side has to be limiting. That is > will be popped only =s will not be popped.


            if(arr[stk_fwd.top()] > arr[i]) stk_fwd.pop();

            else break;

        }

        while(!stk_back.empty())

        {

            // As long as not empty

            // Keep popping untill we get our element that is "lesser" than current element.

            if(arr[stk_back.top()] >= arr[j]) stk_back.pop();

            else break;

        }



        // if stack is empty, then no one is found. IDX will be -1.

        vec[i].first = (stk_fwd.empty()) ? (-1) : stk_fwd.top();



        vec[j].second = (stk_back.empty()) ? (size) : stk_back.top();



        stk_fwd.push(i);

        stk_back.push(j);

    }



    // Now every index contains "smaller and larger"

    long long sum = 0;

    for(int i=0; i<vec.size(); i++){

        long long left = i - vec[i].first;

        long long right = vec[i].second - i;



        long long val = ((left%mod) * (right%mod))%mod;

        val = (val * arr[i]) % mod;

        sum = (sum + val) % mod;

    }



    return (int)sum;

}

};


Sum of Subarray Minimums - Notes

Problem

Given an array, find the sum of the minimum element of every possible subarray.

Example:

arr = [3,1,2,4]

Subarrays and their minimums:

[3] -> 3

[3,1] -> 1

[3,1,2] -> 1

[3,1,2,4] -> 1

[1] -> 1

[1,2] -> 1

[1,2,4] -> 1

[2] -> 2

[2,4] -> 2

[4] -> 4

Answer = 17

---

Initial Observation

Brute force approach:

For every subarray, calculate its minimum.

Time Complexity: O(n²) or worse.

This is too slow.

---

Key Insight

Instead of asking:

"For each subarray, what is its minimum?"

Ask:

"For each element, in how many subarrays is it the minimum?"

Then:

Contribution of arr[i] =

arr[i] × (number of subarrays where arr[i] is minimum)

Total Answer = Sum of contributions of all elements.

---

Example

Array:

[3,1,2,4]

Consider element 1.

Subarrays where 1 is minimum:

[1]

[3,1]

[1,2]

[3,1,2]

[1,2,4]

[3,1,2,4]

Count = 6

Contribution:

1 × 6 = 6

---

Core Question

For an element arr[i]:

How many subarrays have arr[i] as the minimum?

To answer this, determine how far the element can "span" while remaining the minimum.

This requires:

1. Previous Smaller Element

2. Next Smaller Element

---

Why Previous and Next Smaller?

Example:

[3,1,2,4]

Consider 2.

Previous Smaller:

1

Next Smaller:

None

Therefore 2 can only remain minimum inside a limited range.

---

Boundary Interpretation

For every element:

left = distance from Previous Smaller

right = distance from Next Smaller

Number of subarrays where arr[i] is minimum:

left × right

Contribution:

arr[i] × left × right

---

Example Calculation

Array:

[3,1,2,4]

For element 2:

Previous Smaller = index 1

Next Smaller = index 4 (virtual boundary)

left = 2 - 1 = 1

right = 4 - 2 = 2

Contribution:

2 × 1 × 2 = 4

---

Why This Becomes a Stack Problem

The real requirement is:

Find Previous Smaller for every element.

Find Next Smaller for every element.

Whenever a problem asks for:

- Previous Smaller
- Previous Greater
- Next Smaller
- Next Greater

Monotonic Stack should be considered.

---

Monotonic Stack Recognition Pattern

Ask:

Can I rephrase the problem as:

"Find the nearest smaller/greater element on either side?"

If yes:

Monotonic Stack is likely useful.

---

Important Bug Encountered

Initially contribution was calculated as:

(left + right) × arr[i]

This is incorrect.

Reason:

We are choosing:

One left boundary

AND

One right boundary

Hence multiplication is required.

Correct formula:

Contribution = left × right × arr[i]

---

Duplicate Elements Problem

Example:

[2,2,2]

This caused Wrong Answer.

Reason:

Equal elements create ambiguity.

Question:

Which occurrence of 2 should claim subarray [2,2,2]?

If multiple occurrences claim it:

Overcounting occurs.

If no occurrence claims it:

Undercounting occurs.

---

Tie-Breaking Rule

One side must use:

«»

and the other side must use:

«=»

Typical convention:

Previous Smaller:

while(arr[stack.top()] > arr[i])

Next Smaller:

while(arr[stack.top()] >= arr[i])

Alternative convention also works:

Previous Smaller:

«=»

Next Smaller:

«»

The important thing is:

DO NOT use the same comparison on both sides.

---

Debugging Trick

If a monotonic stack solution fails on:

[2,2]

or

[2,2,2]

or

[20000,20000,20000...]

Check duplicate handling first.

Most often the issue is:

Using > on both sides

or

Using >= on both sides.

---

Understanding Subarrays

Array:

[2,2,2]

Subarrays are identified by indices, not values.

Subarrays:

[2] (index 0)

[2,2] (0..1)

[2,2,2] (0..2)

[2] (index 1)

[2,2] (1..2)

[2] (index 2)

Total = 6 subarrays

Formula:

Number of subarrays of length n:

n(n+1)/2

For n = 3:

3×4/2 = 6

---

Final Mental Model

Do NOT think:

"This is a stack problem."

Think:

1. How far can each element remain the minimum?

2. Need left boundary.

3. Need right boundary.

4. Need Previous Smaller and Next Smaller.

5. Monotonic Stack efficiently finds those boundaries.

The stack is not solving the original problem directly.

The stack is solving the hidden subproblem:

"Find nearest smaller elements on both sides."


Final Implementation (My Approach)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stk_fwd;
        stack<int> stk_back;

        long long mod = 1000000007;

        vector<pair<int,int>> vec(
            arr.size(),
            pair<int,int>(-1, -1)
        );

        int size = arr.size();

        for(int i=0, j=size-1;
            i<size && j>=0;
            i++, j--)
        {
            // Previous Smaller (or Equal)
            while(!stk_fwd.empty())
            {
                if(arr[stk_fwd.top()] > arr[i])
                    stk_fwd.pop();
                else
                    break;
            }

            // Next Strictly Smaller
            while(!stk_back.empty())
            {
                if(arr[stk_back.top()] >= arr[j])
                    stk_back.pop();
                else
                    break;
            }

            vec[i].first =
                (stk_fwd.empty()) ? -1 : stk_fwd.top();

            vec[j].second =
                (stk_back.empty()) ? size : stk_back.top();

            stk_fwd.push(i);
            stk_back.push(j);
        }

        long long sum = 0;

        for(int i=0; i<size; i++)
        {
            long long left =
                i - vec[i].first;

            long long right =
                vec[i].second - i;

            long long contribution =
                ((left % mod) * (right % mod)) % mod;

            contribution =
                (contribution * arr[i]) % mod;

            sum =
                (sum + contribution) % mod;
        }

        return (int)sum;
    }
};

Meaning of vec[i]

For every index i:

vec[i].first  = Previous Smaller Index
vec[i].second = Next Smaller Index

Example:

Array:

[3,1,2,4]

For element 2:

Previous Smaller Index = 1
Next Smaller Index = 4 (virtual boundary)

Stored as:

vec[2] = {1,4}

---

Contribution Formula

For each element:

left  = i - previous_smaller_index
right = next_smaller_index - i

Number of subarrays where arr[i] is minimum:

left × right

Contribution:

arr[i] × left × right

---

Mistake #1 Encountered

Incorrect:

(left + right) * arr[i]

Reason:

We are choosing:

- One valid left boundary
- One valid right boundary

Hence multiplication is required.

Correct:

(left * right) * arr[i]

---

Mistake #2 Encountered

Used:

>=

for both Previous Smaller and Next Smaller.

This failed on duplicate values such as:

[2,2]
[2,2,2]
[20000,20000,20000,...]

Reason:

Multiple equal elements started claiming the same subarrays.

---

Duplicate Handling Rule

One side must use:

>

and the other side:

>=

My final choice:

Previous Smaller:

arr[stack.top()] > arr[i]

Next Smaller:

arr[stack.top()] >= arr[i]

This gives a consistent owner for every subarray.

---

What I Learned About Monotonic Stack

Wrong way of thinking:

This looks like a stack problem.

Better way:

How far can an element remain the minimum?

↓

Need left boundary.
Need right boundary.

↓

Need Previous Smaller.
Need Next Smaller.

↓

Use Monotonic Stack.

The stack is only a tool.

The actual problem is finding the nearest smaller elements efficiently.
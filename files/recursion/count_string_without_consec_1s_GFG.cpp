// The bellow WILL give TLE because even for constraint of n<=44 there are roughly 2^44 recursive calls.

// For absolute solution we need to introduce DP solution.

class Solution {
  public:
  
    int genStringCount(int last_char, int rem_stringLength){
        // Base case: only rem_stringLength is 1 only
        if(rem_stringLength == 0) return 1; // Only 1 string possible
        
        // Depending on last character, we will place new characters.
        // If the last was 0, we can place 0 and 1
        // If the last was 1, we can ONLY place 0

        if(last_char == 1) return genStringCount(0, rem_stringLength-1);
        else return genStringCount(1,rem_stringLength-1) + genStringCount(0, rem_stringLength-1);
    }
    int countStrings(int n) {
        return genStringCount(1, n-1) + genStringCount(0, n-1);
    }
};

// Read bellow:

/*
`memset` is a C library function used to **fill a block of memory with a single byte value**.

The syntax is:

```cpp
memset(pointer, value, number_of_bytes);
```

For example:

```cpp
int arr[5];
memset(arr, 0, sizeof(arr));
```

This sets **every byte** of `arr` to `0`.

Since an `int` has 4 bytes, each integer becomes:

```text
00 00 00 00
```

which is indeed `0`.

---

### In your DP code

```cpp
int dp[2][100005];
memset(dp, -1, sizeof(dp));
```

`sizeof(dp)` gives the total size of the entire 2D array in bytes.

`memset(dp, -1, ...)` fills **every byte** with:

```text
11111111   // -1 in one byte
```

Since each `int` consists of 4 bytes, each integer becomes:

```text
FF FF FF FF
```

which represents:

```cpp
-1
```

So after this:

```cpp
dp[i][j] == -1
```

for every element.

---

### Why do we use `-1`?

Because `-1` means:

> "This state hasn't been computed yet."

Then we can do:

```cpp
if (dp[last_char][rem] != -1)
    return dp[last_char][rem];
```

---

### A very important caveat

`memset` works safely only for certain values:

✅ Good:

```cpp
memset(arr, 0, sizeof(arr));
memset(arr, -1, sizeof(arr));
```

❌ Dangerous:

```cpp
memset(arr, 1, sizeof(arr));
```

Many beginners expect:

```text
1 1 1 1 1
```

But that's not what happens.

Each byte becomes:

```text
01 01 01 01
```

So one integer becomes:

```text
0x01010101
```

which is:

```cpp
16843009
```

Example:

```cpp
int arr[3];
memset(arr, 1, sizeof(arr));

cout << arr[0];
```

Output:

```text
16843009
```

not `1`.

---

### Rule of thumb

For `int` arrays:

```cpp
memset(arr, 0, sizeof(arr));   // Safe
memset(arr, -1, sizeof(arr));  // Safe
```

For any other value, use:

```cpp
fill(arr, arr + n, value);
```

or

```cpp
std::fill(&arr[0], &arr[0] + n, value);
```

When you start DP, you'll see `memset(dp, -1, sizeof(dp));` so often that it almost becomes muscle memory!

*/

class Solution2 {
  public:
  
    int dp[2][45]; // Here 45 size cuz we are accessing 1 to index 44. for index 0(rem_stringLength=0) we are straight up returning 1.
  
    int genStringCount(int last_char, int rem_stringLength){
        // Base case: only rem_stringLength is 1 only
        if(rem_stringLength == 0) return 1; // Only 1 string possible
        
        if(dp[last_char][rem_stringLength] != -1) // Soln in dp table
            return dp[last_char][rem_stringLength];
        
        // Depending on last character, we will place new characters.
        // If the last was 0, we can place 0 and 1
        // If the last was 1, we can ONLY place 0

        if(last_char == 1) 
            return dp[last_char][rem_stringLength]=genStringCount(0, rem_stringLength-1);
            
        else 
            return dp[last_char][rem_stringLength]=genStringCount(1,rem_stringLength-1) + genStringCount(0, rem_stringLength-1);
    }
    int countStrings(int n) {
        memset(dp, -1, sizeof(dp));
        return genStringCount(1, n-1) + genStringCount(0, n-1);
    }
};
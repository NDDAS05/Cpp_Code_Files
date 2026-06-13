The reason we use modulo at every step is to prevent numbers from growing huge.

Suppose:

```cpp
2^100
```

This is around:

```cpp
1.26 × 10^30
```

which cannot fit in a `long long`.

But we only care about the answer modulo `M` (where `M = 1e9+7`).

The key mathematical property is:

```cpp
(a * b) % M = ((a % M) * (b % M)) % M
```

Similarly:

```cpp
(a + b) % M = ((a % M) + (b % M)) % M
```

This means we can reduce numbers at every step without changing the final answer.

For example:

```cpp
(123456789 * 987654321) % M
```

is equivalent to:

```cpp
((123456789 % M) * (987654321 % M)) % M
```

Now let's see your code.

You calculate:

```cpp
half = power(num, exp/2)
```

Suppose:

```cpp
half = num^(exp/2) % mod
```

Then for an even exponent:

```cpp
num^exp
=
num^(exp/2) * num^(exp/2)
```

So:

```cpp
num^exp % mod
=
(half * half) % mod
```

which is why you wrote:

```cpp
long long full = (half * half) % mod;
```

The `% mod` here keeps `full` small.

For an odd exponent:

```cpp
num^exp
=
num * num^(exp-1)
```

After squaring the half, you have:

```cpp
full = num^(exp-1) % mod
```

so:

```cpp
(num^exp) % mod
=
(full * num) % mod
```

Hence:

```cpp
return (full * (num % mod)) % mod;
```

You could even write:

```cpp
return (full * num) % mod;
```

because:

```cpp
(full * num) % mod
==
(full * (num % mod)) % mod
```

The latter is just a habit that reminds us to keep numbers reduced.

Think of modulo as a compression machine:

```text
Huge number
    ↓ % mod
Small representative
```

Instead of storing:

```cpp
5^100000
```

(which has ~70,000 digits)

you only store:

```cpp
5^100000 % (1e9+7)
```

which is always less than `1e9+7`.

That's why every multiplication in modular arithmetic is usually written as:

```cpp
ans = (ans * x) % mod;
```

rather than:

```cpp
ans *= x;
```

A useful mental rule for DSA:

```cpp
// Addition
ans = (a + b) % mod;

// Multiplication
ans = (a * b) % mod;

// Fast exponentiation
full = (half * half) % mod;
ans = (full * num) % mod;
```

Never wait until the very end to take `% mod`, because the intermediate value may overflow long before you reach the final answer.

Once you start DP and combinatorics problems, you'll see this pattern constantly:

```cpp
dp[i] = (dp[i-1] + dp[i-2]) % mod;
```

and

```cpp
ans = (ans * x) % mod;
```

for exactly the same reason.

The one thing to remember is:

```cpp
Take modulo after every operation
that can make the number grow.
```

That's the entire philosophy behind modular arithmetic in competitive programming.

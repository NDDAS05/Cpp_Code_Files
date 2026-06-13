class Solution {
public:
    long long power(long long num, long long exp, long long mod){
        if(num == 0) return 0;
        else if(exp == 0) return 1;

        // If say n= 10^15, exp will be in the range of 10^14: num, before mod, will go outta bounds even for long long.
        // We have to apply the mod intermediately as well in the recursions: to be exact after every multiplication.

        // How? By changing recursive call orders.

        // Go to lowest power fast:
        // See: k^8 = (k^4) * (k^4)
        //      k^9 = (k^4) * (k^4) * [k----> 1 k extra at the very end]
        // So we just get to the base case as fast as possible by doing /2.

        long long half_side = power(num, exp/2, mod); // Here half side means (k^4). We have one more k^4.

        // Basically doing num*num in distributed way.
        long long full = (half_side * half_side) % mod;
        if((exp & 1) == 0) return full;
        else return (full * (num % mod)) % mod;
    }
    int countGoodNumbers(long long n) {
        // We are given length of string. We need to see possible number of good numbers.
        // For a string of length n:
        // Odd places : n+1/2 (eg for n=3, we have 2 odd places.)
        // Even places: n/2 (for n=3, we have only one place.)

        // In odd places: only 4 primes can be there: so we have 4^(n/2) comb for odd places.
        // For even places, even numbers are possible: 0, 2, 4, 6, 8 ->5 ways.
        // So, for odd places, we have: 5^(n+1/2) combinations.
        // Total: 5^(n+1/2) * 4^(n/2).
        
        // All we need is to calculate this power.
        long long mod = 1000000007;
        long long ans1 = power(5, (n+1)/2, mod);
        long long ans2 = power(4, n/2, mod);

        return (ans1 * ans2)%mod;

    }
};
// Helper function because leetcode defn was myPow(double, int) which will break for INT_MIN.
// Cuz positive range is 0 to (-1 * INT_MIN) - 1. So one less than positived INT_MIN.

// We  can not modify the defn of function. So write a helper instead.


class Solution {
public:
    double userDefinedPow(double x, long long n) {
        // 8^4 : (8 * 8)^2
        // 8^3 : 8 * 8^2 -> Then above case

        // 8^7 = 8 * 8^6
        //     = 8 * (8 * 8)^3
        //     = 8 * (8 * 8) * (8 * 8)^2
        //     = 8 * (8 * 8) * ( [8 * 8] * [8 * 8] ) // 4 instead of 7 steps.

        if (n == 0)
            return 1;
        else if (x == 0)
            return 0;
        else if (n == 1)
            return x;

        if (n < 0) {
            long long p =
                -1.0 * n; // Cuz +ve has one lesser range
                                   // Also, -1 * n is already a pos integer
                                   // before assignment. So before assignment to
                                   // long long p, it will overflow for INT_MIN.
                                   // But in this helper, n is long long: so that case is handled automatically!
            return (1.0 / userDefinedPow(x, p));
        } else {
            if ((n & 1) == 0)
                return userDefinedPow(x * x, n / 2); // Always use ((n&1) == 0) because
                                            // == has higher precedence.
            else
                return x * userDefinedPow(x, n - 1);
        }
    }
    double myPow(double x, int n) {
        return userDefinedPow(x,n);
    }
};
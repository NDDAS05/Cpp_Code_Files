class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int a= 1; // Can reach in 1 way only: 1 step
        int b =2; // Can reach in 2 ways: 1+1 or  direct 2
        int c;
        // for 3 onwards: for step 3: we can reach step 1 in 1 way: reach 1 then single (2 len jump)
        // OR reach step 2 (in 2 ways) then make a 1 jump.
        // So total 3 ways.

        // In general
        // steps(n) = steps(n-2)<a 2 len jump after this> + steps(n-1)<a 1 len jump after this>
        // Also see, we need to memorize only last 2 steps.

        for(int i=3; i<=n; i++){
            c = a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
class Solution {
  public:
    long long multiple(int n, int m){
        long long multiple=1;
        for(int i=1;i<=n;i++)
            multiple = multiple * m;
        return multiple;
    }
    int nthRoot(int n, int m) {
        // Code here
        int low=0;
        int high = ((m/n == 0)?1:(m/n));
        int ans;
        
        
        long long mid, calc_val;
        while(low <= high){
            mid = low + (high - low) / 2;
            calc_val = multiple(n,mid);
            
            if(calc_val == m) return mid;
            else if (calc_val < m){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return -1;
    }
};
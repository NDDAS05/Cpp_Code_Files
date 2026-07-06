The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. Given an array of integers bt[] of size n. Array bt[] denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.

Note: Consider all process are available at time 0.

Examples:

Input: bt[] = [4,3,7,1,2]
Output: 4
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.
Input: bt[] = [1,2,3,4]
Output: 2
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.


//Code

class Solution {
  public:
    int solve(vector<int>& bt) {
        std::sort(bt.begin(), bt.end());
        
        long long current_running_time=0, total_running_time=0;
        
        for(auto i:bt){
            total_running_time+=current_running_time;
            current_running_time+=i;
        }
        
        int avg_running_time = total_running_time/bt.size();
        return avg_running_time;
    }
};
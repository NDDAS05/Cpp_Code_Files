class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char ,int> ump;
        // Construct the frequency map from this

        for (auto& i : tasks) {
            ump[i]++;
        }

        // Construct a "priority queue" from this thing
        priority_queue<int> pq;
        for (auto& i : ump) {
            pq.push(i.second); // We do not need char themselves.
        }

        // What we have to do: 
        // After every item placed, we can not place the next item for next n cycle.
        // Also we want to fill the first cycles with most frequent tasks as much as possible: because unique tasks do not create conflict: non unique task does.

        // Idea:
        // For n cooldown period: we simulate a "n+1" cycle.
        // Why n+1? say n=1
        // A A A B C D E: (A B)[after n+1=2 can place most frequent A again.]

        // So, in a loop while queue is not empty: i.e, tasks to be placed,
        // 1. Push all freqs in a pq. (we do not need task names, freq is enough)
        // 2. Keep a empty vector. 
        // 3. while(0 to n || queue is empty): 
        // 3a.      pop queue, reduce by 1 and push in vector if non zero
        // 3b.      cpu_cycle++;

        // If loop ends prematurely, that means rest slots will be filled with idle.
        // At the end push vector's tasks into the queue once again.
        // If nothing to push, next itr queue is empty.
        int cpu_cycles=0;
        while(!pq.empty()){
            // first time push is done outside
            vector<int> vec;
            int currPlaced=1;
            while(currPlaced<=n+1 && !pq.empty()){
                int most_freq = pq.top();
                pq.pop();
                most_freq--;
                if(most_freq) vec.push_back(most_freq);
                currPlaced++;
            }
            currPlaced--;
            // 1. all elements completely placed (nothing to push next cycle: vector is empty)
            // 2. vector non-empty still stuff to push next itr.

            if(!vec.empty()){
                cpu_cycles = cpu_cycles + currPlaced + (n+1 - currPlaced); // padding with idle
                for(int i:vec) pq.push(i);
            }
            else cpu_cycles += currPlaced;
        }
        return cpu_cycles;
    }
};
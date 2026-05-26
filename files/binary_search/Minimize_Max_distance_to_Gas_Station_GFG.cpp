/*
Problem Statement:
------------------
We have a horizontal number line with gas stations placed at positions:

stations[0], stations[1], ..., stations[n-1]

We can add K more gas stations anywhere on the line.

Goal:
Minimize the maximum distance between any two adjacent gas stations.

Return the minimum possible value of the maximum adjacent distance
accurate up to 6 decimal places.

------------------------------------------------------------

Core Observation:
-----------------
This is a Binary Search on Answer problem.

Suppose:
max allowed adjacent distance = mid

Question:
Can we ensure every adjacent gap becomes <= mid
using at most K extra gas stations?

This gives a monotonic behavior:

Smaller mid  -> harder -> may require more stations
Larger mid   -> easier -> requires fewer stations

So feasibility pattern becomes:

false false false true true true

Hence:
We binary search for the FIRST feasible value.

------------------------------------------------------------

Search Space:
-------------
low  = 0
high = maximum existing gap between consecutive stations

Why?
Because:
- minimum possible answer cannot be negative
- maximum possible answer initially is the largest existing gap
  (before adding any new stations)

------------------------------------------------------------

Floating Point Binary Search:
-----------------------------
Unlike integer binary search,
continuous binary search cannot terminate using:

while(low <= high)

because infinitely many decimal values exist.

Instead we stop when the search interval becomes very small:

while(high - low >= 1e-6)

This guarantees precision upto 6 decimal places.

------------------------------------------------------------

Feasibility Logic:
------------------
For a given 'mid':

We simulate placing stations greedily.

Suppose:
last placed station = x

If:
x + mid < next existing station

then current segment exceeds allowed distance,
so we MUST place another station.

Otherwise:
we can move to the next existing station.

Total inserted stations required is returned.

------------------------------------------------------------

Binary Search Invariant:
------------------------
If feasible:
    high = mid
because we try to reduce maximum distance further.

Else:
    low = mid
because current distance is too small.

At the end:
- high stays on feasible side
- low stays on infeasible side

Both become extremely close due to epsilon termination.

Hence returning high is theoretically cleaner.
*/

class Solution {
  public:

    // Returns number of extra stations needed
    // so that no adjacent distance exceeds 'mid'
    int extraGasNumber(vector<int>& stations, double mid){

        int station_count = 0;

        // Last station currently considered
        double last_placed_station = stations[0];

        for(int i = 1; i < stations.size();){

            /*
            If next station is farther than allowed distance,
            insert another gas station at:
            
                last_placed_station + mid

            This greedily minimizes distance violation.
            */
            if(last_placed_station + mid < stations[i]){

                station_count++;

                // newly inserted station becomes current reference
                last_placed_station += mid;
            }
            else{

                // existing station can now be reached safely
                last_placed_station = stations[i];

                i++;
            }
        }

        return station_count;
    }

    double minMaxDist(vector<int> &stations, int K) {

        double low = 0;

        // maximum existing adjacent gap
        double high = INT_MIN;

        for(int i = 1; i < stations.size(); i++){

            high = max(high,
                      1.0 * (stations[i] - stations[i - 1]));
        }

        double mid;

        /*
        Continuous Binary Search

        Terminate once search interval becomes
        sufficiently small.
        */
        while(high - low >= 0.000001){

            mid = low + (high - low) / 2;

            /*
            Feasible:
            We can satisfy maximum distance <= mid
            using at most K stations.

            So try smaller answer.
            */
            if(extraGasNumber(stations, mid) <= K){

                high = mid;
            }
            else{

                /*
                Not feasible:
                Too many stations required.

                Increase allowed maximum distance.
                */
                low = mid;
            }
        }

        // high stores feasible boundary
        return high;
    }
};
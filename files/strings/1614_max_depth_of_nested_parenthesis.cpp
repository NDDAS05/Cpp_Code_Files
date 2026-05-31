#include<iostream>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = INT_MIN;
        int current_depth=0;
        for(auto i: s){
            if(i == '(') current_depth++;
            if(i==')') current_depth--;

            max_depth = max(current_depth, max_depth);
        }

        return max_depth;
    }
};
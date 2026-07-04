// Recursive approach is also valid, but gives TLE.
// There is also a DP approach

// Bellow is the greedy approach

class Solution {

public:
    bool checkValidString(string s) {
        int min=0, max=0;
        for(auto i: s){
            if(i == '('){
                min++;
                max++;
            }

            else if(i == ')'){
                min--;
                max--;
            }
            else{ // * case
                min--; // * = -1
                max++; // * = +1
            }

            if(min<0) min=0; // if we have min = -1, max = 5, that means there must be some interpretation of * that could be considered 0 or +1 to make this min value == 0. Since 0 is still contained in the range.
            // What if max is itself <0, immediately exit.  That means )|we are here|    ( case, can not be recovered . Extra closing can not be fixed by upcoming openings.
         

            if(max < 0) return false;
        }

        return min==0; // if min itself > 0, even the most optimistic combination can not bring valid parenthesis.
    }
};
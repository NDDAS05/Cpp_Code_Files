#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void allSubstr(int pos, string& s, string currStr, vector<string>& st){
        
        if(pos == s.length()) {
            st.push_back(currStr);
            return;
        }
        // Two options: Take it or leave it
        // Leaving it.
        allSubstr(pos+1, s, currStr, st);
        
        // Take it and move on
        currStr.push_back(s[pos]);
        allSubstr(pos+1, s, currStr, st);
    }
    vector<string> powerSet(string &s) {
        vector<string> vec;
        allSubstr(0, s, "", vec);
        
        return vec;
    }
};

// Now the alternate version.
//  This is a little different one.
// We use a loop through all the characters. And use recursion to explore "if included" options, then we come back, un-include it, move on to next character.
// So for every character, we explore if included and if not included branch.

class Solution2 {
  public:
  
    void allSubstrLexico(int pos, string& s, string& currStr, vector<string>& st) {
        
        // 1. Add the current subset to the result immediately.
        // This naturally adds "", then "a", then "ab", etc., in order.
        st.push_back(currStr);
        
        // 2. Loop through all remaining characters
        for (int i = pos; i < s.length(); i++) {
            //  say currStr is "a"
            
            // Take the character
            // That is now currStr is "ab"
            currStr.push_back(s[i]);
            
            // Move on to the next index (i + 1)
            // Explore all possible combination with the currStr AND the new included character in the previous step.
            // That is explore all subsequences having "ab" in the beginning. (ab itself is pushed first in the recursive call).
            allSubstrLexico(i + 1, s, currStr, st);
            
            // Backtrack: Remove the character we just added so the loop 
            // That means "ab" becomes "a" in currStr. Now when loop advances, our currStr will be "ac"- so we skipped "ab" AFTER exploring all combinations with "ab".
            // That means we "un-include" the last included character. Then move on to next character. So we skipped this char. 
            currStr.pop_back();
        }
    }
    
    vector<string> powerSet(string &s) {
        vector<string> vec;
        string currStr = "";
        
        // Sort the input string first to ensure we process characters alphabetically
        sort(s.begin(), s.end());
        
        allSubstrLexico(0, s, currStr, vec);
        
        return vec;
    }

/*
Why This Guarantees Lexicographical Order

By combining sort(s.begin(), s.end()) with the for loop, the recursion forces the computer to fully explore words starting with 'a' before it ever touches words starting with 'b'.
Here is the flow of the st.push_back() calls for "abc":
Pushes ""
Loop picks 'a'  Pushes "a"
Loop picks 'b' --> Pushes "ab"
Loop picks 'c' --> Pushes "abc"
Backtracks to "a", loop picks 'c' --> Pushes "ac"
Backtracks to "", loop picks 'b' --> Pushes "b"
Loop picks 'c' --> Pushes "bc"
Backtracks to "", loop picks 'c' --> Pushes "c"
*/
};

int main(){
    string str = "abc";
    Solution s;
    vector<string> vec = s.powerSet(str);

    for(auto i: vec){
        cout<< (i == "" ? "{empty}" : i) <<endl;
    }

    return 0;
}
int main(){
    string str = "abc";
    Solution s;
    vector<string> vec = s.powerSet(str);

    for(auto i: vec){
        cout<<i<<endl;
    }

    return 0;
}
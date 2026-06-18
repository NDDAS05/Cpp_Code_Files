class Solution {
private: 
    bool checkPalindrome(string& s, int start, int end){
        int i=start, j=end;

        for(;i<j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
public:
    void substringPartitions(vector<vector<string>>& ans, vector<string>& currSet, string& s, int start_idx){
        if(start_idx == s.length()){ // Because we exit the moment we see a string is not palindrome, it is impossible to reach this condition unless all the strings in a perticular partition type are plaindromes.
            ans.push_back(currSet);
            return;
        }

        for(int i=start_idx; i<s.length(); i++){
            // Push/backtrack IF AND ONLY IF current partition from start_idx to i is palindrome.
            if(checkPalindrome(s, start_idx, i)){
                currSet.push_back(s.substr(start_idx, i-start_idx+1));
                substringPartitions(ans, currSet, s, i+1); // We know upto i was palindrome. So now check remainder of the string
                currSet.pop_back();
            }
            else{
                // Not palindrome. So no recursive call. It ends here.
                continue;
                // This statement is not necessary, but for learning purpose just to make it explicit.
                // If we did return instead: say "efe".
                // It would have seen "ef" is not a palindrome and would have exited very early.
                // But that should not be the case. That iteration should be skipped and we should start with a new currStr kinda string. Not exit the entire function itself. 

                // This currSet clearing is done by backtracking itself. Because we start with empty currSet, thus every pop_back call at every recursion level will pop the element inserted at that level. So when controll comes back to this level the currSet will be empty (after this pop statement).
            }
        }

    }
    
    vector<vector<string>> partition(string s) {
        // Idea: Using same backtracking.
        //  Why? Because, there is a hint that we need to explore ALL substrigs and return all palindromic ones.
        // How we do? We loop over possible partitions.
        // From start to that index, if it is palindrome we move one level deeper.
        // From start to that |-> this is done cuz every partition has to be palindrome. So we move to next partition if and only if starting is itself palindromic partition.

        // At any given point if we find even one string at any recursive level that is not palindrome,
        // We just return.

        vector<vector<string>> ans;
        vector<string> currSet;
        substringPartitions(ans, currSet, s, 0);

        return ans;
    }
};
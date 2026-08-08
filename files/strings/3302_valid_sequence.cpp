// Read statement first
// Pattern: suffix matching, greedy

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        // Approach: Creating a dp array of size = word1
        // This represents: at index 'i', from the remaining words of word1 (i+1 -to- word1.size - 1), the last dp[i] characters can be matched in lex order 
        // dp[3]= 2. Meaning, from word1[4]-word1[9] we can find last 2 characters of word[2] can be found. Note "after this" NOT "AT THIS". So, current character match is not checked.

        // Why skipping current one? We have choice: to either modify the current one (once only) or to take if matches.
        // While modifying something, we need to know info about the future characters if they can still be matched or not.

        int w1size = word1.size();
        int w2size = word2.size();

        vector<int> dp(w1size);

        int w1ptr = w1size-1;
        int w2ptr = w2size-1;
        int count = 0;

        for(; w1ptr>=0; w1ptr--){
            dp[w1ptr] = count; // for carry over
            if(w2ptr>=0 && word1[w1ptr] == word2[w2ptr]){
                // Change the previus index dp array. Not the current one.
                count++; // increment the count which will be put in next iteration
                w2ptr--;
            }
        }

        // Now we traverse from left to right.
        // Cases of w2ptr char != w1ptr char:
        // 1. Remaining characters ([word2.size-1] - w2ptr) in word2 > dp[w1ptr] 
        // This means:
        // "if we change the current, ie take it as a match even if it did not, the remaining char is greater than the suffix length that can be matched. So we need to find match up"

        // 2. Remaining char in word 2 == dp[w1ptr] :
        // This means:

        // If we did not "took as match (not matched but we took)", we can "take as match" the current word of word1 and remaining chars will be found in the word1 in proper order.

        // 3. Remaining char in word2 < dp[w1ptr]
        // This means: The difference can be at max 1. This means, we can "take" this as matchup and remaining will be found during traversal.
        //-----------------------
        // If matches just take them.
        
        int changed = 0; // still not changed anything.
        w2ptr = 0;
        vector<int> seq;

        for(w1ptr = 0; w1ptr < w1size; w1ptr++){
            if(word1[w1ptr] == word2[w2ptr]) 
            {
                seq.push_back(w1ptr);
                w2ptr++;
            }

            else if(changed== 0 && (w2size-1-w2ptr) <=dp[w1ptr]){
                // we can either take it or try to get a matchup for word2[w2ptr] which "WE MAY NOT FIND AT ALL"

                // Better take it here. Both results in lex order anyway
                seq.push_back(w1ptr);

                changed = 1;
                w2ptr++;
            }

            if(w2ptr == w2size) return seq;
        }

        return {};
    }
};
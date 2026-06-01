#include <iostream>
#include <string>

using namespace std;

class solution
{
public:
    // Logic: Both-way travarsal.
    // For even length palindromes, center of current and next element is the mid.
    // For odd length palindromes, current IS the center
    // We need to find a way to manage two of these at once

    // a b c b a
    // a b b a
    // a b b b a

    // So , we start from 1, end at str.length()-2. Cuz after 1, next minimum pal is 2.
    // 1 is basically guaranteed.

    // a b b a c x d x c a a b
    int palLength(string& s, int idx1, int idx2){
        while(idx1>=0 && idx2<=s.size()-1 && s[idx1] == s[idx2]){
            idx1--;
            idx2++;
        }
        return idx2-idx1-1;
    }

    string longestPalindrome(string s){
        if(s.empty()) return "";
        int largest_pal_start=0, largest_pal_end=0;
        int local_maxLen;

        for(int i=0; i<s.length(); i++){
            int oddLen = palLength(s, i, i);
            int evenLen = palLength(s, i, i+1);

            local_maxLen = max(oddLen, evenLen);

            // Find out start end through local_maxlen.

            if(local_maxLen > largest_pal_end - largest_pal_start + 1){

                // Remember the formula !!!!!!!!

                // If odd, i - (localMaxlen-1) /2 
                // Cuz excluding the center itself, equal on both sides.
                // 1 2 3 2 1.
                // center = 2, length = 5.
                // Excluding the center, 4/2 = 2 ele left. So 0.


                // Now for even 1 2 2 1, it also works

                largest_pal_start = i - (local_maxLen - 1)/2;
                largest_pal_end = i + local_maxLen/2;
            }

        }

        return s.substr(largest_pal_start, largest_pal_end-largest_pal_start+1);
    }
 
};

int main()
{
    solution s;
    cout << s.longestPalindrome("cbb") << endl;

    return 0;
}
#include<iostream>
#include<string>

using namespace std;

class solution{
public:
    int atMostK(int k, string& s){
        int i=0, j=0;
        int distinct = 0;
        int totalDistinct = 0;
        int freq[26] = {0};
        for(;j<s.size();j++){
            // Note how the window is increasing..
            // j increases 1 by 1.
            // i decreases to make window valid again after j making the window potentially invalid (off by +1)
            if(freq[s[j] - 'a'] == 0) distinct++;
            freq[s[j]-'a']++;
            // Not here: if(distinct<=k) totalDistinct += (j-i+1);
            // If distinct goes outta bound, we shrink window, but due to the if condition we do not check that window again EVER.
            // What happens is that, next i loop bellow shrinks the window.
            // Next itr, j again increases that window to a >k count. That is skipped AGAIN.
            // Basically counting stops after first window completely... 
            // So count after shrinking window.. i.e. at a valid window. Since we increment j automatically,
            // If distinct <k, we won't shrink anyway. Shrinking ONLY happens once it becomes invalid.
            // Then we make it valid again by shrinking and check number of substrings.
            while(distinct > k){
                freq[s[i] - 'a']--;
                if(freq[s[i]-'a'] == 0) distinct--;
                i++;
            }

            totalDistinct += (j-i+1); // If above loop did not execute then it is valid. 
            // If it did, we make it valid by shrinking window.

        }

        return totalDistinct;
    }
    int countSubstr(string s, int k) {
        return (atMostK(k, s) - atMostK(k-1, s));
    }
};


int main(){
    solution s;
    cout<<s.countSubstr("aa", 1);
    return 0;
}
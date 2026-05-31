/*
451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 10^5
s consists of uppercase and lowercase English letters and digits.

 */
#include<bits/stdc++.h>
using namespace std;

class solution{
public: // See optimized implementation bellow
    string frequencySort(string s){
        // Idea: We have to first count the frequency of characters...
        // And then do some custom sorting based on those frequency values.

        int hashmap[256] = {0}; // std::memset(arr, 0, sizeof(arr)); // Fills the memory block with zeros
        for(auto i: s){
            hashmap[i]++; //frequency counting.
        }

        // Now custom sort.

        sort(s.begin(), s.end(), [&hashmap](char a, char b){
            if(hashmap[a] == hashmap[b]) return a<b;
            return hashmap[a]>hashmap[b];
        });

        return s;
    }

    // This is one way to do it.
    // But see, we are sorting the string itself. If it has like 90000 elements, we know there are
    // only 56 max possible unique characters. (A-Z, a-z). For only 52 characters we are sorting 90000 elements!

    // What we can do is we can make a collection that will only store the unique elements encountered in the string,
    // And will store their frequencies too..
    // We sort that collection.
    // We know the frequencies.. we can utilize that to reconstruct the string.



    /*
    1. The Cleanest Way: Passing the arguments directly to append
The std::string::append function has a built-in override that accepts a 
count and a character directly. You do not need to construct a temporary string at all!

C++
    // Correct & Highly Efficient
    
    s.append(hasharr[i], i);
    */
    string frequencySort2(string s){
        // 1. store unique characters in something and their freq in something
        vector<char> uniqueChars;
        int hashmap[256]={0};

        for(auto i: s){
            if(hashmap[i] == 0) uniqueChars.push_back(i);
            hashmap[i]++;
        }

        // Now we do custom sorting
        sort(uniqueChars.begin(), uniqueChars.end(), [&hashmap](char a, char b){
            if(hashmap[a] == hashmap[b]) return a<b;
            return hashmap[a] > hashmap[b];
        });

        // Reconstruct the string
        s="";
        for(auto i: uniqueChars){
            s.append(hashmap[i], i);
        }

        return s;
        
    }
};

int main(){
    solution s;
    cout<<s.frequencySort2("abbbbbcccddee");
    return 0;
}
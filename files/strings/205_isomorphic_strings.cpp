/*
205. Isomorphic Strings


Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "f11", t = "b23"

Output: false

Explanation:

The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 10^4
t.length == s.length
s and t consist of any valid ascii character.
*/

#include<iostream>
#include<string>
#include<array>
// #include<unordered_map> [Do not use for only alphabetical strings]
using namespace std;

class solution{
public:
    bool isIsomorphic(string s, string t){
        
        array<int, 256> mapS_to_T = {0};
        array<int, 256> mapT_to_S = {0};
        // Isomorphic in short is bijective mapping. We need to ensure one to one from both side.
        // Onto is ensured by constraint.
        for(size_t i=0; i<s.size();i++){
            if(mapS_to_T[s.at(i)] == 0 && mapT_to_S[t.at(i)] == 0){
                // Add two-way mapping.
                mapS_to_T[s.at(i)] = t.at(i);
                mapT_to_S[t.at(i)] = s.at(i);
            }
            else{ // At least one found.
                if(mapS_to_T[s.at(i)]!=t.at(i) || mapT_to_S[t.at(i)]!=s.at(i)) return false;
            }
        }
        return true;
    }
};

int main(){
    solution s;
    if(s.isIsomorphic("bbbaaaba", "aaabbbba")) cout<<"isomorphic"<<endl;
    else cout<<"Not isomorphic."<<endl;

    return 0;
}
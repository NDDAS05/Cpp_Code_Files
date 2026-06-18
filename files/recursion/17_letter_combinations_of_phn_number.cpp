class Solution {
private:
    string maps[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:

    void genCombinations(vector<string>& combs, string& str, string& digits, int pos){
        // Each digit is associated with an array.
        // Say: 2[abc], 3[def], 5[jkl]
        // So in top level for loop we run on the array defined by 2 ["a""b""c"]
        // After selecting a character, the next level (1 level deep recursion) will run on array defined by 3: [d e f]
        // Last level is on [j k l]

        // This is JUST like other recursions, but here we, at each recursive level, change the array we are working on. Thats the only difference.

        // So, when we return?
        // When: str.length == digits.length
        // Also in Loop, we need to make sure we include at least 1 character at each level.
        if(str.length() == digits.length()){
            combs.push_back(str);
            return;
        }

        // Change the array we will be looping on
        string s = maps[digits[pos] - '0'];
        for(char ch: s){
            str.push_back(ch);
            // At next level, the array itself changes due to the change in pos. Thus we are never skipping all characters at any given level because after picking a character we immediately change the array itself in the next recursive call.
            genCombinations(combs, str, digits, pos+1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> combs;
        string str;
        genCombinations(combs, str, digits, 0);

        return combs;
    }
};
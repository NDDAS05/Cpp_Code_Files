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

int main(){
    string str = "abc";
    Solution s;
    vector<string> vec = s.powerSet(str);

    for(auto i: vec){
        cout<<i<<endl;
    }

    return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int i=0, j=0;
    char ref_char;
    std::string result="";
    if(strs[i].length()==0)
      return result;
    for(j=0;j<strs[0].length();j++)  //Runs as long as 1st string is non empty.
    {
      ref_char=strs[0][j];
      for(i=0;i<strs.size();i++)     //Runs over the rows
      {
        //Breaking case;
        if(j>=strs[i].length() || strs[i][j]!=ref_char)
        {
          return result;
        } 
      }
      result.push_back(ref_char);
    }
    return result;
    }
};
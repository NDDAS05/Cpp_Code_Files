// size_t means unsigned integer
#include <bits/stdc++.h>
#include <string>
class solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    size_t i = 0, j = 0;
    char ref_char;
    std::string result = "";
    if (strs[i].length() == 0)
      return result;
    for (j = 0; j < strs[0].length();
         j++) // Runs as long as 1st string is non empty.
    {
      ref_char = strs[0][j];
      for (i = 0; i < strs.size(); i++) // Runs over the rows
      {
        // Breaking case;
        if (j >= strs[i].length() || strs[i][j] != ref_char) {
          return result;
        }
      }
      result.push_back(ref_char);
    }
    return result;
  }
};

int main() {
  std::vector<std::string> arrStr;
  arrStr = {"low", "ow", "o"};
  std::string result;
  solution sol;
  result = sol.longestCommonPrefix(arrStr);
  std::cout << result;
}

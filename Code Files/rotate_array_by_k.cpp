class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int l = 0, size = (int)(nums.size()), startIndex, i = 0;
    //%size means ans will be in -(size-1) to (size-1)
    //+size means 0 to 2(size-1)
    //%size again mans 0 to size-1
    startIndex = l;
    while (i < size - 1) {
      std::swap(nums[i], nums[l]);
      i++;
      l++;
      if (l == size)
        l = startIndex;
    }
  }
};

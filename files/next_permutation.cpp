#include<iostream>
#include<vector>
#include<algorithm>
#define endl std::endl

class Solution{
public:
    void nextPermutation(std::vector<int>& nums)
    {
        auto reverseArray=[&](int start, int end){
            for(;start<end;start++,end--)
            {
                std::swap(nums[start], nums[end]);
            }
        };

        int size=(int)nums.size(), i=size-1;
        while(i>0)
        {
            if(nums[i-1]<nums[i]) break;
            i--;
        }
        i--;
        std::cout<<i<<endl<<endl;
        //i points to the pervious of maximum from right side if they are arranged in increasing order from the right side
        if(i<0){
            reverseArray(i+1, size-1);
            return;
        }

        for(int j=size-1;j>=i;j--){ //j should point to the first element that is greater than (i-1)
            if(nums[j]>nums[i])
            {
                std::swap(nums[i], nums[j]);
                reverseArray(i+1, size-1);
                return;
            }
        }

    }
};

int main(){
    std::vector<int> vec={7,2,4,3,1};
    Solution s;
    s.nextPermutation(vec);
    for(int i:vec) std::cout<<i<<" "<<endl;
    return 0;
}
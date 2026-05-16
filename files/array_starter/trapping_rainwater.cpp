#include<iostream>
#include<vector>
#include<algorithm>
class solution{
    public:
    int getrainwater(std::vector<int>& nums, int i, int j){
        int limit=std::min(nums[i],nums[j]);
        int sum=0, q;
        for(int p=i;p<=j;p++)
        {
            q=(limit-nums[p]<0)?0:(limit-nums[p]);
            sum+=q;
        }
        return sum;
    }

    int trap(std::vector<int>& height){
        int size=height.size(), max_index=0;
        for(int i=0;i<size;i++){
            if(height[i]>=height[max_index]) max_index=i;
        }

        int left=0, right=size-1, trapped_water=0;
        for(int i=0;i<=max_index;i++)
        {
            if(height[i]>=height[left])
            {
                trapped_water+=getrainwater(height, left, i);
                left=i;
            }
        }

        for(int j=right;j>=max_index;j--)
        {
            if(height[j]>=height[right])
            {
                trapped_water+=getrainwater(height, j, right);
                right=j;
            }
        }
        return trapped_water;
    }
};


int main()
{
    std::vector<int> vec={5,4,0,3};
    solution s;
    std::cout<<s.trap(vec)<<std::endl;
    return 0;
}
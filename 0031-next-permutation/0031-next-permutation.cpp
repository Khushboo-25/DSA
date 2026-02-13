class Solution {
    
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int i1=-1;
        for(int i=n-1;i>=1;i--)
        {
            if(nums[i-1]<nums[i])
            {
                i1=i-1;
                break;
            }
        }
        if(i1==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>i1;i--)
        {
            if(nums[i]>nums[i1])
            {
                swap(nums[i],nums[i1]);
                reverse(nums.begin()+i1+1,nums.end());
                return ;
            }
        }

    }
};
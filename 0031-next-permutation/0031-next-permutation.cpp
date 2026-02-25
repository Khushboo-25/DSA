class Solution {
public:

    void nextPermutation(vector<int>& nums) 
    {
        /*
        12355115842

        12355118245
        */
        int n=nums.size();
        int s=n;
        for(int i=n-1;i>=1;i--)
        {
            if(nums[i-1]<nums[i])
            {
                s=i;
                break;
            }
        }
        if(s==n)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int t1=s-1;
        for(int i=n-1;i>=s;i--)
        {
            if(nums[i]>nums[t1])
            {
                swap(nums[i],nums[t1]);
                break;
            }
        }
        reverse(nums.begin()+s,nums.end());
    }
};
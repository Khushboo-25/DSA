class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<=1)
        return 1;
        vector<int>ps(n,1);
        vector<int>sf(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            ps[i]=0&ps[i-1];
            else
            ps[i]=1&ps[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            sf[i]=0&sf[i+1];
            else
            sf[i]=1&sf[i+1];
        }
        if(sf[1] ||ps[n-2])
        return 1;
        for(int i=1;i<n-1;i++)
        {
            if(sf[i+1]==1 && ps[i-1]==1 && nums[i-1]<=nums[i+1])
            return 1;
        }
        return 0;
        
    }
};
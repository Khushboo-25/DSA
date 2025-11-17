class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int i=-1;
        int n=nums.size();
        int s=0;
        while(s<n)
        {
            if(nums[s]==1)
            {
                i=s;
                break;
            }
            s++;
        }
        int ans=INT_MAX;
        if(i==-1)
        return 1;
        s++;
        while(s<n)
        {
            if(nums[s]==nums[i])
            {
                ans=min(ans,s-i-1);
                if(ans<k)
                return 0;
                i=s;
            }
            s++;
        }

        if(ans<k)
        return 0;
        return 1;

        
    }
};
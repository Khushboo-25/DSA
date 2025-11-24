class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        int n=nums.size();
        vector<bool>ans(n,false);
        int s=0;
        for(int i=0;i<n;i++)
        {
            s=s<<1;
            if(nums[i]==1)
            {
                s|=1;
            }
            if(s%5==0)
            {
                ans[i]=true;
            }
            s=s%10;

        }
        return ans;
        
    }
};
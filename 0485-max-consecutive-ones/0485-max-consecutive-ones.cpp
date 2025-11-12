class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ans=0;
        int cn=0;
        for(auto it:nums)
        {
            if(it!=1)
            {
                ans=max(ans,cn);
                cn=0;
            }
            else
            cn++;
        }
        ans=max(ans,cn);
        return ans;
        
    }
};
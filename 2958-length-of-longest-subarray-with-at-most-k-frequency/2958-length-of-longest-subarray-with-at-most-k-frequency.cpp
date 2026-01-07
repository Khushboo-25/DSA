class Solution {
public:

    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int ans=0;
        int s=0;
        int e=0;
        unordered_map<int,int>pp;
        while(s<=e && e<n)
        {
            pp[nums[e]]++;
            if(pp[nums[e]]>k)
            {
                while(s<=e && pp[nums[e]]>k)
                {
                    if(pp[nums[s]]>1)
                    {
                        pp[nums[s++]]--;
                    }
                    else
                    pp.erase(nums[s++]);
                }
            }
            ans=max(ans,e-s+1);
            e++;
        }
        return ans;

        
    }
};
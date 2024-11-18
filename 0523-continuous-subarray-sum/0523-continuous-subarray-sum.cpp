class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<long long,int>pp;
        long long s=0;
        int n=nums.size();
        pp[0]=0;
        for(int i=0;i<n;i++)
        {
            s=(s+nums[i])%k;
            if(pp.find(s)==pp.end())
            pp[s]=i+1;
            else
            {
                int df=i+1-pp[s];
                if(df>=2)
                return 1;
            }
            
        }
        return 0;
        
    }
};
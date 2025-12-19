class Solution {
public:
int mod=1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>av;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            av.push_back(i);
        }
        int n1=av.size();
        if(n1<1)
        return 0;
        long long ans=1;
        for(int i=1;i<n1;i++)
        {
            ans=(ans*((av[i]-av[i-1])%mod))%mod;
        }
        return ans;

        
    }
};
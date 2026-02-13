class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>bin(n,1);
        int ans=n;
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            bin[i]=bin[i+1]&1;
            else
            bin[i]=0;
            
        }
        for(int i=n-1;i>=0;i--)
        {
            if(bin[i]==1)
            ans=min(ans,i);
        }
        
        return ans;
        

        
    }
};
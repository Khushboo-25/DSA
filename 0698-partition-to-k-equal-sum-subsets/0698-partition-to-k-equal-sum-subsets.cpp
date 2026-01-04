class Solution {
public:
bool call(vector<int>&ks,int i,int &n,vector<int>&nums,int &k,int &sm)
{
    if(i>=n)
    {
        int ks0=ks[0];
        for(int i=1;i<k;i++)
        {
            if(ks[i]!=ks0)
            return 0;
        }
        return 1;
    }
    for(int j=0;j<k;j++)
    {
        if(ks[j]+nums[i]<=sm)
        {
            
        ks[j]+=nums[i];
        if(ks[j]<=sm && call(ks,i+1,n,nums,k,sm))
        return 1;
        ks[j]-=nums[i];
        if(ks[j]==0)
        break;
        }
    }
    return 0;
}
    bool canPartitionKSubsets(vector<int>&nums,int&k)
    {
        
        int n=nums.size();
        vector<int>ks(k,0);
        int sm=0;
        for(auto it:nums)
        {
            sm+=it;
        }
        
        sort(nums.rbegin(),nums.rend());
        
        if(sm%k!=0)
        return 0;
        sm/=k;
        
        if (nums[0] > sm) return 0;
        return call(ks,0,n,nums,k,sm);
        
    }
};
class Solution {
public:
bool call(int &sz,vector<int>&nums,int &n,int &k)
{
    unordered_map<int,int>pp;
    for(int i=0;i<sz;i++)
    {
        pp[nums[i]]++;
    }
    bool ps=1;
    for(auto it:pp)
    {
        if(it.second>k)
        {
            ps=0;
            break;
        }
    }
    if(ps)
    return 1;
    for(int i=sz;i<n;i++)
    {
        pp[nums[i]]++;
        if(pp[nums[i-sz]]>1)
        pp[nums[i-sz]]--;
        else
        pp.erase(nums[i-sz]);
        bool fs=1;
        for(auto it:pp)
        {
            if(it.second>k)
            {
                fs=0;
                break;
            }
        }
        if(fs)
        return 1;
    }
    return 0;

}
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int ans=0;
        int s=1;
        int e=n;
        while(s<=e)
        {
            int md=s+(e-s)/2;
            if(call(md,nums,n,k))
            {
                ans=md;
                s=md+1;
            }
            else
            e=md-1;
        }
        return ans;

        
    }
};
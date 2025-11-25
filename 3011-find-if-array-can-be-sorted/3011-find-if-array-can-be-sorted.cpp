class Solution {
public:
int count(int x)
{
    int ans=0;
    while(x>0)
    {
        if(x&1==1)
        ans++;
        x=x>>1;
    }
    return ans;
}
    bool canSortArray(vector<int>& nums) 
    {
        unordered_map<int,int>pp;
        int n=nums.size();
        for(auto it:nums)
        {
            pp[it]=count(it);
        }
        for(int j=n-1;j>=1;j--)
        {
            for(int i=0;i<j;i++)
            {
                if(nums[i]>nums[i+1] && pp[nums[i]]==pp[nums[i+1]])
                {
                    swap(nums[i],nums[i+1]);
                }
            }
        }
        // bool ans=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            return 0;
        }
        return 1;

        
        
    }
};
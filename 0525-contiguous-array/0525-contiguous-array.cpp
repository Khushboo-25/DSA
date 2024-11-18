class Solution {
public:
    int findMaxLength(vector<int>& nums) 
{
        unordered_map<int,int>pp;
        int n0=0,n1=0;
        int n=nums.size();
        pp[0]=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            n0++;
            else
            n1++;
            int df=n0-n1;
            if(pp.find(df)==pp.end())
            pp[df]=i+1;
            else
            {
                int ans1=i+1-pp[df];
                ans=max(ans1,ans);
            }
            
        }
        return ans;
    }
};
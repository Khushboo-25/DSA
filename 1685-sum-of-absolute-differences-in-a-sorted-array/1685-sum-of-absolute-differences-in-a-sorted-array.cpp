class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long long> pv(n,0),av(n,0);
        pv[0]=nums[0],av[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        pv[i]=pv[i-1]+nums[i];
        for(int i=n-2;i>=0;i--)
        av[i]=av[i+1]+nums[i];
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int sump=nums[i]*(i+1)-pv[i];
            int sumb=0;
            if(i+1<n)
            {
                sumb+=av[i+1]-nums[i]*(n-1-i);
            }
            ans[i]=sump+sumb;
        }
        return ans;
        

        
    }
};
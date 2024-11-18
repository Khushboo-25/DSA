class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> prev(n);
        vector<int>suff(n);
        prev[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            prev[i]=prev[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=nums[i]+suff[i+1];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=i*nums[i];
        }
        int ans1=0;
        int fans=ans;
        for(int i=n-1;i>0;i--)
        {
            ans1=ans+prev[i-1]-(n-1)*nums[i];
            if(i+1<n)
            {
                ans1+=suff[i+1];
            }

            fans=max(ans1,fans);
            ans=ans1;
            ans1=0;
        }
        return fans;
        
    }
};
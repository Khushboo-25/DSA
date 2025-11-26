class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) 
    {
        
        // int lm=*max_element(nums.begin(),nums.end());
        vector<int>pr(1e5+1,1);
        int lm=1e5;
        pr[0]=0;
        pr[1]=0;
        for(int i=2;i<=lm;i++)
        {
            if(pr[i]==1)
            {
                // pr[i]=1;
                for(int j=min(i*1ll*i,lm*1ll);j<=lm;j+=i)
                {
                    pr[j]=0;
                }
            }
        }
        // for(int i=0;i<=lm;i++)
        // {
        //     if(pr[i]==1)
        //     cout<<i<<" ";
        // }
        int mn=INT_MAX,mx=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pr[nums[i]]==1)
            {
                mn=min(mn,i);
                mx=max(mx,i);
            }
        }
        
        return mx-mn;
        
    }
};
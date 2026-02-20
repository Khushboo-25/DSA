class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>ps(n+1,-1),bs(n+2,n+2);
        vector<int>psm(n+2,0);
        vector<int>bsm(n+2,0);
        for(int i=1;i<=n;i++)
        psm[i]=psm[i-1]+nums[i-1];
        for(int i=n;i>=1;i--)
        bsm[i]=bsm[i+1]+nums[i-1];
        int leftsum=0;
        int lefti=0;
        for(int i=k;i<=n;i++)
        {
            if(psm[i]-psm[i-k]>leftsum)
            {
                lefti=i-k+1;
                leftsum=psm[i]-psm[i-k];
            }
            ps[i]=lefti;
        }
        int rightsum=0;
        int righti=n+2;
        for(int i=n-k+1;i>=1;i--)
        {
            if(bsm[i]-bsm[i+k]>=rightsum)
            {
                righti=i;
                rightsum=bsm[i]-bsm[i+k];
            }
            bs[i]=righti;
        }
        vector<int>ans{-1,-1,-1};
        int sum=0;
        for(int i=n-2*k+1;i>=k+1;i--)
        {
            int leftst=ps[i-1];
            int rights=bs[i+k];
            int sum1=psm[leftst+k-1]-psm[leftst-1];
            int sum2=psm[i+k-1]-psm[i-1];
            int sum3=bsm[rights]-bsm[rights+k];
            if(sum1+sum2+sum3>=sum)
            {
                ans[0]=leftst-1;
                ans[1]=i-1;
                ans[2]=rights-1;
                sum=sum1+sum2+sum3;
            }
        }

        // for(auto it:ps)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:bs)
        // {
        //     cout<<it<<" ";
        // }

        return ans;
    }
};
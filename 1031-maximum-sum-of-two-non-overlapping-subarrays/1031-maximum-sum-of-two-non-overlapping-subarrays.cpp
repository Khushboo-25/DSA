class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) 
    {
        int n=nums.size();
        vector<int>ps(n+1,0);
        for(int i=0;i<n;i++)
        {
            ps[i+1]=ps[i]+nums[i];
        }
        // for(auto it:ps)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        vector<int>ans1(n+1,0);
        for(int i=fl;i<=n;i++)
        {
            ans1[i]=max(ans1[i-1],ps[i]-ps[i-fl]);
            // cout<<ans1[i]<<" ";
        }
        // cout<<endl;
        vector<int>ans2(n+2,0);
        for(int i=n-sl+1;i>=1;i--)
        {
            ans2[i]=max(ans2[i+1],ps[i+sl-1]-ps[i-1]);
            // cout<<ans2[i]<<" "; 
        }
        // cout<<endl;
        int fn=0;
        for(int i=fl+1;i<=n-sl+1;i++)
        {
            fn=max(ans1[i-1]+ans2[i],fn);
        }
        vector<int>b1(n+1,0),b2(n+2,0);
        for(int i=sl;i<=n;i++)
        {
            b1[i]=max(b1[i-1],ps[i]-ps[i-sl]);
            // cout<<b1[i]<<" ";
        }
        // cout<<endl;
        for(int i=n-fl+1;i>=1;i--)
        {
            b2[i]=max(b2[i+1],ps[i+fl-1]-ps[i-1]);
            // cout<<b2[i]<<" "; 
        }
        for(int i=sl+1;i<=n-fl+1;i++)
        {
            fn=max(b1[i-1]+b2[i],fn);
        }
        // cout<<endl;
        return fn;
    }
};